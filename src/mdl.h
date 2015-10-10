#ifndef __MDL_H__
#define __MDL_H__

#include "define.h"


class Mdl
{
public:
	Mdl(const char* file);
	~Mdl();

	void save();
public:
	char 	 _path[255];
	ifstream _file;
};



#endif

