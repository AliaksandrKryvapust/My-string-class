#include "Mystring.h"
Mystring::Mystring()	{
		str = nullptr;
		length = 0;	}
Mystring::Mystring(const char* str)	{
		length = strlen(str);
		this->str = new char[length + 1]; // + 1 for\0
		for (int i = 0; i < length; i++) 
		{ this->str[i] = str[i];	}
		this->str[length] = '\0'; }
Mystring::~Mystring() { delete[] this->str; }
Mystring::Mystring(const Mystring& other) {
		length = strlen(other.str); // copy constructor, essential for dynamic memmory
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{ this->str[i] = other.str[i]; }
		this->str[length] = '\0'; 	}
Mystring::Mystring(Mystring&& other) 	{
		this->length = other.length; // move constructor
		this->str = other.str;
		other.str = nullptr; 	}
Mystring Mystring::operator=(const Mystring& other) {
	if (this->str != nullptr)
	{ delete[] str; }
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{ this->str[i] = other.str[i];}
	this->str[length] = '\0';
	return*this;}
Mystring Mystring::operator +(const Mystring& other) {
		Mystring newStr; // string concotenation
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newStr.length = thisLength + otherLength;
		newStr.str = new char[thisLength + otherLength + 1];
		int i = 0;
		for (; i < thisLength; i++)
		{ newStr.str[i] = this->str[i];	}
		for (int j = 0; j < otherLength; j++, i++)
		{ newStr.str[i] = other.str[j]; }
		newStr.str[thisLength + otherLength] = '\0';
		return newStr;	}
bool Mystring::operator==(const Mystring& other) {
	if (this->length != other.length)
		return false;
	else for (int i = 0; i < this->length; i++) {
		if (this->str[i] != other.str[i])
			return false;	}
	return true; }
bool Mystring::operator !=(const Mystring& other) { return !(this->operator==(other)); }
char& Mystring::operator[](int index) // reference to change value
	{ return this->str[index];	}
void Mystring::Print() {	std::cout << str;}
int Mystring::Length() 	{	return length;	}
int Mystring::Size() { return length; }
char& Mystring::At(const int index){
	if (index>=length)
	{ throw std::exception("Index out of range"); }
	return this->str[index];}
bool Mystring::Empty() { return (this->length>0)? false : true; }
void Mystring::PushBack(char sbl){
	if (this->Empty()) {
		length++;
		this->str = new char[length + 1];
		this->str[length-1] = sbl;
		this->str[length] = '\0';	}
	else {
		length++;
		char* temp = new char[length + 1];
		for (int i = 0; i < length - 1; i++)		
		{	temp[i] = this->str[i];	}
		temp[length -1] = sbl;
		temp[length] = '\0';
		delete[] this->str;
		this->str = temp;
		temp=NULL;
		}
	}
void Mystring::PopBack(){
	if (!this->Empty())	{
		length--;
		char* temp = new char[length + 1];
		for (int i = 0; i < length ; i++)		
		{	temp[i] = this->str[i];	}
		temp[length] = '\0';
		delete[] this->str;
		this->str = temp;
		temp = NULL;
	}	else
	{ throw std::exception("Empty string, forbidden");	}
}
void Mystring::Copy(char str[], int length, int position) {
	if (position>length)
	{ throw std::exception("Position is out of range");	}
	for (int i = 0; i < length; i++)
	{ str[i] = this->str[position + i]; }
	str[length] = '\0';
}
void Mystring::Swap(Mystring& other){
	char* temp = this->str;
	this->str = other.str;
	other.str = temp;
	temp = NULL;
}
