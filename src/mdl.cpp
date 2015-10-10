#include <zlib.h>
#include "util.h"
#include "mdl.h"


Mdl::Mdl(const char* file)
{
	strcpy(_path, file);
	_file.open(file, ios::in|ios::binary);

	_file.seekg(0, ios::end);
    uint32 total = _file.tellg();
    cout << "[FILE] " << total << endl;

	_file.seekg(0, ios::beg);
    while(_file.tellg() < total)
    {
        char head[5];
        memset((char*)head, 0, sizeof(head));
	    _file.read((char *)head, 4);

        uint32 n;
	    _file.read((char *)&n, 4);

        uint32 ukn1;
	    _file.read((char *)&ukn1, 4);
        uint32 ukn2;
	    _file.read((char *)&ukn2, 4);

        uint32 p = _file.tellg();


        uint32 d = (n % 16 == 0)? (n): (n + (16 - n % 16));
	    _file.seekg(p + d, ios::beg);

        cout << "[" << head << "] " << n << " " << ukn1 << " " << ukn2 << endl;
        cout << "[U-" << head << "] " << ukn2 << " " << n/ukn1 << endl;
    }
}


Mdl::~Mdl()
{
	_file.close();
}


void Mdl::save()
{
//    char path[255];
//    strcpy(path, "aries/");
//    strcpy(path + 6, _path);
//    strcpy(path + strlen(path) - 4, ".bone");
//
//    cout << "[SAVE]" << path << endl;
//    Util::mkdir(path);
//    ofstream fout(path, ios::out|ios::binary);
//
//    uint8 bn = (uint8)_list.size();
//    fout.write((char *)&bn, 1);
//
//    for(int i = 0; i < _list.size(); i++)
//    {
//        MdlBone b = _list[i];
//
//        int8 id = (int8)i;
//        fout.write((char *)&id, 1);
//
//        int8 bp = (int8)b.parent;
//        fout.write((char *)&bp, 1);
//
//        uint8 bs = strlen(b.name);
//        fout.write((char *)&bs, 1);
//        fout.write((char *)b.name, bs);
//
//
//	    Matrix4f m4 = Matrix4f::TransMat(b.invpos.x, b.invpos.y, b.invpos.z);
//	    Matrix4f m5(Quaternion(b.invrot.x, b.invrot.y, b.invrot.z, b.invrot.w));
//        Matrix4f m6 = m5 * m4;
//
//        //cout << "====================================" << endl;
//        //m6.print();
//        //getMatById(i)->inverted().print();
//
//        //fout.write((char *)m6.inverted().x, 4 * 16);
//        fout.write((char *)(getMatById(i)->x), 4 * 16);
//    }
//
//    fout.close();
}













