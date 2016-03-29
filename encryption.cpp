#include "encryption.h"

Encryption::Encryption()
{

}

char * Encryption::encrypt_DES_ECB()
{
	printf("-------DES ECB--------\n");
	std::string result_str;
	DES_cblock key = { 0x11, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 };;
    
     DES_key_schedule ks;
     int str_length = m_text.size();
	 DES_set_odd_parity(&key);

	 int r = des_set_key_checked(&key, ks);
	 std::cout << r << '\n';
     
	 ;
	 result = new char[str_length];
	 //const_DES_cblock input = "aaaaaaa";
	 //char input[] = "abcdabcdabcd";
	 //str_length = sizeof(input);
	 int t;
	 if (str_length % 8)
	 {
		 int t = str_length + 8 - str_length % 8;
	 }
	 else
	 {
		 t = str_length;
	 }
	 
	 std::cout<<t<<"\n";
	 unsigned char *out = new unsigned char[t];
	 unsigned char *part_out;
	 printf("cleartext:%s\n ", m_text.c_str());
	 
    
	 for (int i= 0; i < t;i+=8)
	 {
		 if (i<(str_length-str_length%8))
		 {
			std::string substr= m_text.substr(i, i + 8).c_str();
			std::cout << substr;
			const char * input = substr.c_str();
			 DES_ecb_encrypt((const_DES_cblock*)input, (DES_cblock*)out, &ks, DES_ENCRYPT);
		 }
		 else
		 {
			 char input[8];
			 for (int j = 0; j < 8;j++)
			 {
				 
				 if (i + j >= str_length)
				 {
					 input[j] = '\0';
				 }
				 else
				 {
					 input[j] = m_text[i + j];
				 }
			 }
			 DES_ecb_encrypt((const_DES_cblock*)&input, (DES_cblock*)out, &ks, DES_ENCRYPT);

		 }
		 result_str.append((char*)out,8);
	 }
	 //DES_ecb_encrypt((const_DES_cblock*)input, (DES_cblock*)out, &ks, DES_ENCRYPT);
	 for (int i = 0; i < result_str.size(); i++)
	 {
		 
		 printf("%02x", reinterpret_cast<unsigned char&>(result_str[i]));
		 printf(" ");
	 }
	 DES_cblock res;

	 DES_ecb_encrypt((const_DES_cblock*)out, &res, &ks, DES_DECRYPT);
	 printf("\ndecrypted:%s\n", res);
	 
	 //DES_ecb_encrypt((const_DES_cblock*)result, (DES_cblock*)output, &ks, DES_DECRYPT);
	 /* std::ofstream fs("output");
	  fs << output;
	  fs.close();*/
	
	 return result;

}

char * Encryption::encrypt_3DES_ECB()
{
	printf("-------3DES ECB--------\n");
	DES_cblock key1 = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
	DES_cblock key2 = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
	DES_cblock key3 = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
	//DES_cblock cblock = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	DES_key_schedule ks1,ks2,ks3;
	int str_length = m_text.size();
	if (DES_set_key_checked(&key1, &ks1) ||
		DES_set_key_checked(&key2, &ks2) ||
		DES_set_key_checked(&key3, &ks3)) {
		printf("Key error, exiting ....\n");
	
	}

	// std::cout << r << '\n';

 
	result = new char[str_length];
	const_DES_cblock input = "aaaa";
	DES_cblock out;
	printf("cleartext:%s\n", input);

	// DES_ecb_encrypt((const_DES_cblock*)&text,(DES_cblock *)result,&ks,DES_ENCRYPT)
	DES_ecb3_encrypt(&input, &out, &ks1,&ks2,&ks3, DES_ENCRYPT);
	printf("ciphered: ");
	for (int i = 0; i < sizeof(input); i++)
	{
		printf("%02x", out[i]);
		printf(" ");
	}
	DES_cblock res;

	DES_ecb3_encrypt(&out, &res, &ks1, &ks2, &ks3, DES_DECRYPT);
	printf("\ndecrypted:%s \n", res);


	//DES_ecb_encrypt((const_DES_cblock*)result, (DES_cblock*)output, &ks, DES_DECRYPT);
	/* std::ofstream fs("output");
	fs << output;
	fs.close();*/

	return result;
}
