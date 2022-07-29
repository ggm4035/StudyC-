#pragma once
#include "String.h"

String::String() : str(NULL) { }
String::String(const char* strData)
{
	str = new char[strlen(strData) + 1];
	strcpy(str, strData);
}
String::String(const String& ref)
{
	str = new char[strlen(ref.str) + 1];
	strcpy(str, ref.str);
}
String::~String()
{
	if (str != NULL)
		delete[] str;
}

String& String::operator=(const String& ref)
{
	if (str != NULL)
		delete[] str;
	str = new char[strlen(ref.str) + 1];
	strcpy(str, ref.str);
	return *this;
}
String String::operator+(const String& ref)
{
	char* sum = new char[strlen(str) + strlen(ref.str) + 1];
	strcpy(sum, str);
	strcat(sum, ref.str);
	String result = sum;
	return result;
}
String String::operator+=(const String& ref)
{
	char* save = new char[strlen(str) + 1];
	strcpy(save, str);

	if (str != NULL)
		delete[] str;
	str = new char[strlen(save) + strlen(ref.str) + 1];
	strcpy(str, save);
	strcat(str, ref.str);
	return *this;
}
bool String::operator==(const String& ref)
{
	return !strcmp(str, ref.str);
}
ostream& operator<<(ostream& os, const String& ref)
{
	cout << ref.str << endl;
	return os;
}
istream& operator>>(istream& is, String& ref)
{
	char str[100];

	if (ref.str != NULL)
		delete[] ref.str;

	cin >> str;
	ref.str = new char[strlen(str) + 1];
	strcpy(ref.str, str);
	return is;
}
