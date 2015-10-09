#ifndef __PKG_H__
#define __PKG_H__

#include "define.h"


#pragma pack(1)
typedef struct _PakFile
{
    char   name[255]; 
	uint32 offset;
    uint32 size;
} PakFile;
#pragma pack()


class Pak
{
public:
	Pak(const char* file);
	~Pak();

	void save();
public:
	char 	 _path[255];
	ifstream _file;

	vector<PakFile> _list;
};



#endif

