#include "Mystring.h"
class Mystring{
public:
	Mystring()	{
		str = nullptr;
		length = 0;	}
	Mystring(const char* str)	{
		length = strlen(str);
		this->str = new char[length + 1]; // + 1 для терминирующего 0
		for (int i = 0; i < length; i++) 
		{ this->str[i] = str[i];	}
		this->str[length] = '\0'; }
	~Mystring() { delete[] this->str; }
	Mystring(const Mystring& other) {
		length = strlen(other.str); // конструктор копирования нужен при работе с динамичекой памятью
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{ this->str[i] = other.str[i]; }
		this->str[length] = '\0'; 	}
	Mystring(Mystring&& other) 	{
		this->length = other.length; // коструктор переноса
		this->str = other.str;
		other.str = nullptr; 	}
	Mystring operator =(const Mystring& other)	{
		if (this->str != nullptr)
		{ delete[] str; }
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{ this->str[i] = other.str[i]; }
		this->str[length] = '\0';
		return*this; 	}
	Mystring operator +(const Mystring& other) {
		Mystring newStr; // для конкотенации строк
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
	bool operator ==(const Mystring& other) {
		if (this->length != other.length)
			return false;
		else for (int i = 0; i < this->length; i++) {
			if (this->str[i] != other.str[i])
				return false; }
		return true;	}
	bool operator !=(const Mystring& other) { return !(this->operator==(other)); }
	char& operator[](int index) // ссылка чтобы можно было присваивать значение данного элемента
	{ return this->str[index];	}
	void Print() {	std::cout << str;}
	int Length() 	{	return length;	}
	int Size() { return length; }
private: // указатель на массив. Хранит переданные символы
	char* str;
	int length;
};