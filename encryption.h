#ifndef ENCRYPRION_H
#define ENCRYPRION_H

#include <openssl/des.h>
#include <string>
#include <iostream>
#include <fstream>
class Encryption
{
public:
    Encryption();
    Encryption(std::string text):m_text(text){}
	char * encrypt_DES_ECB();
	char * encrypt_3DES_ECB();

private:
	std::string m_text;
       char* result;
};

#endif // ENCRYPRION_H
