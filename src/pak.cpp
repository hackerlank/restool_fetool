#include <zlib.h>
#include "util.h"
#include "pak.h"


Pak::Pak(const char* file)
{
	strcpy(_path, file);
	_file.open(file, ios::in|ios::binary);

    uint32 total;
	_file.read((char *)&total, 4);

    uint32 ukn;
	_file.read((char *)&ukn, 4);

    cout << "total " << total << " ukn " << ukn << endl;
    for(int i = 0; i < total; i++)
    {
        PakFile f;
        memset((char*)&f, 0, sizeof(f));

        uint16 n;
	    _file.read((char *)&n, 2);
	    _file.read((char *)f.name, n);
	    _file.read((char *)&f.offset, 4);
	    _file.read((char *)&f.size, 4);

        _list.push_back(f);

        cout << f.name << " " << f.offset << " " << f.size << endl;
    }

}


Pak::~Pak()
{
	_file.close();
}


void Pak::save()
{
    char path[255];
    for(int i = 0; i < _list.size(); i++)
    {
        PakFile v = _list[i];
        

        strcpy(path, "out/");
        strcpy(path + 4, v.name);
        for(int t = 0; t < strlen(path); t++)
            if(path[t] == '\\')
                path[t] = '/';


        char* buf = new char[v.size];
	    _file.seekg(v.offset);
        _file.read(buf, v.size);

        cout << "[SAVE]" << path << endl;
        Util::mkdir(path);
        ofstream fout(path, ios::out|ios::binary);
        fout.write(buf, v.size);
        fout.close();

        delete[] buf;
    }
}







