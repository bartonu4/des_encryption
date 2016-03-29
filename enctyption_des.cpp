// enctyption_des.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "encryption.h"
#include <fstream>
int _tmain(int argc, _TCHAR* argv[])
{
	
	std::ifstream file("input.txt", std::ios::in | std::ios::binary | std::ios::ate);
	int size;
	char* memblock;
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char[size];
		file.seekg(0, std::ios::beg);
		file.read(memblock, size);
		file.close();
	}
	std::string str(memblock,size);
	
	Encryption encrpt(str);
	encrpt.encrypt_3DES_ECB();
	encrpt.encrypt_DES_ECB();



		//return 0;
	

}

