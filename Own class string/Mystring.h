#pragma once
#include<iostream>
class Mystring
{
public:
	Mystring();
	Mystring(const char* str);
	~Mystring();
	Mystring(const Mystring& other);
	Mystring(Mystring&& other);
	Mystring operator =(const Mystring& other);
	Mystring operator +(const Mystring& other);
	bool operator ==(const Mystring& other);
	bool operator !=(const Mystring& other);
	char& operator[](int index);
	void Print();
	int Length();
	int Size();
};

