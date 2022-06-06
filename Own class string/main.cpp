#include<iostream>
#include "Mystring.h"
#include<string>
using namespace std;

int main(){
	Mystring str = "Hello";
	Mystring str2 = "World";
	Mystring result;
	result = str + str2;
	cout << str.Length() << endl;
	cout << str2.Length() << endl;
	cout << result.Length() << endl;
	bool equal = str != str2;
	cout << equal << endl;
	cout << str[0] << endl;
	string example;
	example.length();
	return 0;
}