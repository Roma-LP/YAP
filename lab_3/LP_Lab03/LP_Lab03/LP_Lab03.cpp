//LepeshRoma2001
//ЛепешРома2001
//Лепеш2001Рома

#include <cstdlib>
#include <iostream>

char lf[] = "LepeshRoma2001";  //4C6570657368526F6D6132303031  (Windows-1251)
char rf[] = "ЛепешРома2001";   //CBE5EFE5F8D0EEECE032303031    (Windows-1251)
char lr[] = "Лепеш2001Рома";   //CBE5EFE5F832303031D0EEECE0    (Windows-1251)

wchar_t Llp[] =L"LepeshRoma2001";  //4C6570657368526F6D6132303031                 (UTF-8)
wchar_t Lrp[] =L"ЛепешРома2001";   //D09BD0B5D0BFD0B5D188D0A0D0BED0BCD0B032303031 (UTF-8)
wchar_t Llr[] =L"Лепеш2001Рома";   //D09BD0B5D0BFD0B5D18832303031D0A0D0BED0BCD0B0 (UTF-8)

char* UpperW1251(char* destination, char* source);


int main()
{
    setlocale(LC_ALL,"Russian");
	char source[]      = "12345sdfghjlйцгшщз";
	char destination[] = "124567890123456789";

	UpperW1251(destination,source);

	std::cout << destination << std::endl;

	system("pause");
	return 0;
}

char* UpperW1251(char* destination, char* source)
{
	for (int i = 0; source[i]!='\0'; i++)
	{
		if ((source[i] >= 'а'&&source[i] <= 'я') || (source[i] >= 'a'&&source[i] <= 'z'))
			destination[i] = source[i]-32;
		else
			destination[i] = source[i];
	}
	return destination;
}