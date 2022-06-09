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
	char& At(const int index);
	bool Empty();
	void PushBack(char sbl);
	void PopBack();
	void Copy(char str[], int length, int position);
	void Swap(Mystring& other);
private:
	char* str; // array pointer to store char
	int length;
};