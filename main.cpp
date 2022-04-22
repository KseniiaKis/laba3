#include "TString.h"
#include <iostream>

int main()
{
	TString str("ertyu");
	TString str4('i', 4);
	TString str1(str);
	TString str2;
	TString str5("dfghjk");
	TString str6("jtyu fghjk sghjk juice");
	str4.Print();
	str.Print();
	str1.Print();
	str2 = str + str1;
	str2.Print();
	if (str == str2)
		std::cout << "Compare!" << std::endl;
	else
		std::cout << "NOT Compare!" << std::endl;
	char q;
	q = str1[2];
	std::cout << q << std::endl;
	std::cout << str2;
	str5.FindWord("tr");
	str.FindLetter('s');
	TString* p = 0;
	int size = 0;
	for (int i = 0; i < size; i++)
	std::cout << p[i] << '\t';

	return 0;
}