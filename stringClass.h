#pragma once
#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class String
{
private:
	char* str;
public:
	String();
	String(const char* strData);
	String(const String& ref);
	~String();

  //연산자 오버로딩(=, +, +=, ==, >>, <<)
	String& operator=(const String& ref);
	String operator+(const String& ref);
	String operator+=(const String& ref);
	bool operator==(const String& ref);

	friend ostream& operator<<(ostream& os, const String& ref);
	friend istream& operator>>(istream& os, String& ref);
};
