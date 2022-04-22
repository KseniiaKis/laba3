#pragma once

class TString
{
protected:
	int len;
	char* str;
public:
	TString();
	~TString();
	TString(char h, int l);
	TString(const TString& a);
	TString(char* a);
	void Print();

	TString operator+(const TString& a);
	TString& operator=(const TString& a);
	bool operator==(const TString& a);
	bool operator<(const TString& a);
	bool operator>(const TString& a);
	char operator[](int a);

	int FindWord(char* s);
	int FindLetter(char s);
	char** Division(char c);

	friend std::ostream& operator<<(std::ostream& out, const TString& tmp);
	friend std::istream& operator>>(std::istream& input, TString& tmp);
};