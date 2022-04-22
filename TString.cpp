#include "TString.h"
#include <iostream>
using namespace std;

TString::TString()
{
	len = 0;
	str = '\0';
}

TString::~TString()
{
	if (len != 0)
		delete[] this->str;
	len = 0;
}

TString::TString(char h, int l)
{
	str = new char[l + 1];
	for (int i = 0; i < l; i++)
		str[i] = h;
	str[l] = '\0';
}

TString::TString(const TString& a)
{
	str = new char[a.len];
	for (int i = 0; i < a.len; i++)
	{
		this->str[i] = a.str[i];
	}
	this->str[len] = '\0';
}

TString::TString(char* a)
{
	len = strlen(a);
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		str[i] = a[i];
	}
	str[len + 1] = '\0';
}

void TString::Print()
{
	std::cout << this->str << std::endl;
}

TString TString::operator+(const TString& a)
{
	int i = 0;
	TString res;
	res.len = this->len + a.len;
	res.str = new char[res.len + 1];
	for (i; i <= this->len; i++)
	{
		res.str[i] = this->str[i];
	}
	for (int j = 0; j <= a.len; j++)
	{
		res.str[i] = a.str[j];
		i++;
	}
	res.str[len + 1] = '\0';
	return res;
}

TString& TString::operator=(const TString& a)
{
	if (a.len < 0)
		throw "oshibka";
	this->len = a.len;
	this->str = new char[a.len + 1];
	for (int i = 0; i <= len; i++)
	{
		this->str[i] = a.str[i];
	}
	this->str[len + 1] = '\0';
	return *this;
}

bool TString::operator==(const TString& a)
{
	if (this->len == a.len)
		for (int i = 0; i <= a.len; i++)
			if (this->str[i] == a.str[i])
				return true;
	return false;
}

bool TString::operator<(const TString& a)
{
	if (this->len < a.len)
		return true;
	return false;
}

bool TString::operator>(const TString& a)
{
	if (this->len > a.len)
		return true;
	return false;
}

char TString::operator[](int a)
{
	char res;
	if (a <= this->len && a>=0)
		res = this->str[a];
	return res;
}

int TString::FindWord(char* s)
{
	int f = 0;
	if (s == 0)
		throw"Error";
	for (int i = 0; i <= this->len; i++)
	{
		if (this->str[i] == s[0])
		{
			for (int j = 0; j <= strlen(s); j++)
				if (this->str[i + j] == s[j])
					f = i;
		}
	}
	std::cout << f << std::endl;
	return f;
}

int TString::FindLetter(char s)
{
	int f = 0;
	int len = strlen(this->str);
	for (int i = 0; i < len; i++)
		if (this->str[i] == s)
		{
			f = i + 1;
			std::cout << f << std::endl;
			break;
		}
	if (f == 0)
		std::cout << "Haven't this letter in string " << std::endl;
	return f;
}

char** TString::Division(char c)
{
	int len = strlen(this->str);
	int n = 0;
	for (int i = 0; i < len; i++)
		n++;
	char** mas = new char* [n];
	if (n != 0)
	{
		char* tmp;
		int l = 0;
		int j = 0;
		while (j < len + 1)
		{
			if ((str[j] == c || j == len) && l != 0)
			{
				tmp = new char[l + 1];
				for (int i = 0; i < l; i++)
				{
					tmp[i] = str[j - l + i];
				}
				tmp[l] = '\0';
				mas[n] = new char[l + 1];
				mas[n] = tmp;
				std::cout << tmp << std::endl;
				l = 0;
				j++;
				delete[] tmp;
			}
			else
			{
				if (str[j] != c)
					l++;
				j++;
			}
		}
	}
	else
		std::cout << "no entire in stroke" << std::endl;
	return mas;
}

std::ostream& operator<<(std::ostream& out, const TString& tmp)
{
	if (tmp.str != nullptr)
		out << "string = " << tmp.str << std::endl;
	return out;
}

std::istream& operator>>(std::istream& input, TString& tmp)
{
	input >> tmp.str;
	return input;
}