#include"MyString.h"
#include<iostream>
using namespace std;
	//default constructor
	MyString::MyString() {
		length = 0;
		str = nullptr;
	}
	//parameterized constructor
	MyString::MyString(const char* ch) {
		int i = 0;
		for (i; ch[i] != '\0'; i++);
		length = i;
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
			str[i] = ch[i];
		str[length] = '\0';
	}
	//copy constructor 
	MyString::MyString(const MyString& cpy) {
		length = cpy.length;
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
			str[i] = cpy.str[i];
		str[length] = '\0';
	}
	//destructor
	MyString::~MyString() {
		if (str) {
			delete[]str;
			str = nullptr;
		}
	}
	//display string & sub-string
	void MyString:: display() const {
		cout << str;
	}
	//returns length of the string & sub-string 
	int MyString:: getLength() const {
		return length;
	}
	//returns substring of the string from index 'start' to 'end' 
	MyString  MyString:: subString(int start, int end)const {
		MyString sub;
		sub.length = (end - start) + 1;
		sub.str = new char[sub.length + 1];
		for (int i = 0; i < sub.length; i++)
			sub.str[i] = str[start + i];
		sub.str[sub.length] = '\0';
		return sub;
	}
	// for conversion from 'MyString' to 'int'
	MyString::operator int() {
		int k = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] <= 57 && str[i] >= 48) {
				k = (k*10)+(str[i]-48);
			}
		}
		if (k == 0)
			return -1;
		else
			return k;
	}
	//for conversion from 'MyString' to 'char*' (C-style string) [call as: char c=MyString obj]
	MyString::operator char* () {
		char* arr = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			arr[i] = str[i];
		}
		arr[length] = '\0';
		return arr;
	}
	//set data member of instance
	void MyString::setStr(const char* ch) {
		int i = 0;
		for (i; ch[i] != '\0'; i++);
		length = i;
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
			str[i] = ch[i];
		str[length] = '\0';
	}
	//returns index of start occurence of substring in the string 
	int MyString:: find(const MyString& subString)const
	{
		for (int i = 0; i < length; i++)
		{
			int k = 0;
			if (str[i] == subString.str[k])
			{
				for (int j = i; j < i + subString.length; j++)
				{
					if (str[j] == subString.str[k])
						k++;
				}
			}
			if (k == subString.length)
				return i;
		}
		return -1;
	}
	//returns index of start occurence of substring in the string after index 'start'
	int MyString:: find(const MyString& subString, int start) const
	{
		for (int i = start + 1; i < length; i++)
		{
			int k = 0;
			if (str[i] == subString.str[k])
			{
				for (int j = i; j < i + subString.length; j++)
				{
					if (str[j] == subString.str[k])
						k++;
				}
			}
			if (k == subString.length)
				return i;
		}
		return -1;
	}
	//returns index of end occurence of substring in the string 
	int MyString:: rfind(const MyString& subString) const {
		int n = -1;
		for (int i = 0; i < length; i++) {
			int k = 0;
			if (str[i] == subString.str[k])
			{
				for (int j = i; j < i + subString.length; j++)
				{
					if (str[j] == subString.str[k])
						k++;
				}
			}
			if (k == subString.length)
				n = i;
		}
		return n;
	}
	//returns index of start occurence of char in the string
	int MyString:: find(const char ch) const {
		for (int i = 0; i < length; i++)
		{
			if (ch == str[i])
				return i;
		}
		return -1;
	}
	//returns index of end occurence of char in the string 
	int MyString:: rfind(const char ch) const {
		int n = -1;
		for (int i = 0; i < length; i++)
		{
			if (ch == str[i])
				n = i;
		}
		return n;
	}
	//overloading assignment operator
	const MyString& MyString:: operator=(const MyString& cpy) {
		if (str == cpy.str)
			return *this;
		else
		{
			if(str)
			delete[]str;
			length = cpy.length;
			str = new char[length + 1];
			for (int i = 0; i < length; i++)
				str[i] = cpy.str[i];
			str[length] = '\0';
			return *this;
		}
	}
	//overloading stream insertion operator as friend function 
    ostream& operator<<(ostream&obj, const MyString&c) {
		for (int i = 0; i < c.length; i++)
			obj << c.str[i];
		return obj;
	}
	//overloading stream extraction operator as friend function 
	istream& operator>>(istream&obj, MyString&ch) {
		if(ch.str)
			delete[]ch.str;
		cout << "Enter length : ";
		obj >> ch.length;
		ch.str = new char[ch.length+1];
		for (int i = 0; i < ch.length; i++) {
			cout << "Enter a Character" << i+1 << " : ";
			obj >> ch.str[i];
		}
		ch.str[ch.length] = '\0';
		return obj;
	}
	//overloading + operator
	MyString MyString:: operator+(const MyString&ch) const {
		MyString concatenate;
		int m = 0;
		concatenate.length = length + ch.length;
		concatenate.str = new char[concatenate.length + 1];
		for (int i = 0; i < length; i++)
			concatenate.str[i] = str[i];
		for (int i = length; i < concatenate.length; i++)
			concatenate.str[i] = ch.str[m++];
		concatenate.str[concatenate.length] = '\0';
		return concatenate;
	}
	//overloading == operator
	bool MyString:: operator==(const MyString&ch) const {
		if (length != ch.length) 
			return false;
		for (int i = 0; i < length; i++)
			if (str[i] != ch.str[i])
				return false;
		return true;
	}
	//overloading < operator
	bool MyString:: operator<(const MyString&ch) const {
		for (int i = 0; i < length; i++)
			if (str[i] != ch.str[i])
			{
				if (str[i] > ch.str[i])
					return true;
				else
					return false;
			}
		return false;
	}
	//overloading <= operator
	bool MyString:: operator<=(const MyString&ch) const {
		if (((ch == (*this)) || ((*this) < ch)))
			return true;
		else
			return false;
	}
	//overloading += operator
	MyString MyString:: operator += (const MyString&ch) {
		*this = (*this) + ch;
		return *this;
	}
	//overloading pre-increment operator 
	MyString& MyString:: operator++() {
		if (this->str[length - 1] == 'z')
			this->str[length - 1] = 'a';
		else if (this->str[length - 1] == 'Z')
			this->str[length - 1] = 'A';
		else if (this->str[length - 1] != '9')
			this->str[length - 1] = this->str[length - 1] + 1;
		else if (this->str[length - 1] == '9')
		{
			this->length = this->length + 1;
			this->str[length - 2] = '1';
			this->str[length - 1] = '0';
		}
		return *this;
	}