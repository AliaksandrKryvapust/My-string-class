#include<iostream>
#include "Mystring.h"
#include<string>
using namespace std;

int main(){
	Mystring str = "Hello";
	Mystring str2 = "World";
	Mystring result;
	result = str + str2;
	cout << "Sring one length:\t" << str.Length() << endl;
	cout << "Sring two length:\t" << str2.Length() << endl;
	cout << "United string length:\t" << result.Length() << endl;
	bool equal = str != str2;
	cout << "Is string one not equal to second?\t" << equal << endl;
	cout << "First element of the first string\t" << str[0] << endl;
	try
	{ cout << "Second element of the first string\t" << str.At(1) << endl;	}
	catch (const std::exception& ex)
	{ cout << ex.what() << endl; }
	cout << "Is first string empty?\t" << str.Empty() << endl;
	str.PushBack('!');
	cout << "Push back function" << endl;
	str.Print();
	cout << endl;
	try
	{ str.PopBack(); }
	catch (const std::exception& ex)
	{ cout << ex.what() << endl; }
	cout << "Pop back function" << endl;
	str.Print();
	cout << endl;
	const int lt = 5;
	char* str3 = new char[lt+1];
	try
	{ str.Copy(str3, lt, 0); }
	catch (const std::exception& ex)
	{ 	cout << ex.what() << endl; 	}
	cout << "Copy function" << endl;
	for (int i = 0; i < lt; i++)
	{ cout << str3[i] << '\t'; }
	cout << endl;
	delete[] str3;
	str.Swap(str2);
	cout << "String one & two swap function" << endl;
	str.Print();
	cout << endl;
	str2.Print();
	cout << endl;
	return 0;
}