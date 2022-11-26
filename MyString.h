#pragma once
#include<iostream>
using namespace std;
class MyString
{
private:

	char* str;
	int length;

public:

	//default constructor
	MyString();

	//parameterized constructor
	MyString(const char*);

	//destructor
	~MyString();

	//display string
	void display() const;

	//returns length of the string
	int getLength() const;

	//copy constructor
	MyString(const MyString&);

	//overloading assignment operator
	const MyString& operator=(const MyString&);

	//overloading stream insertion operator as friend function
	friend ostream& operator<<(ostream&, const MyString&);

	//overloading stream extraction operator as friend function 
	friend istream& operator>>(istream&, MyString&);

	//overloading + operator. you can perform concatenation using +operator
	MyString operator+(const MyString&) const;

	//overloading == operator
	bool operator==(const MyString&) const;

	//overloading < operator
	bool operator<(const MyString&) const;

	//overloading <= operator
	bool operator<=(const MyString&) const;

	//overloading += operator
	MyString operator += (const MyString&);

	//set data member of instance
	void setStr(const char*);

	//for conversion from 'MyString' to 'int'
	operator int();

	//for conversion from 'MyString' to 'char*' (C-style string) 
	operator char* ();

	//overloading pre-increment operator 
	MyString& operator++();

	//returns substring of the string from index 'start' to 'end' 
	MyString subString(int, int) const;

	//returns index of first occurence of substring in the string 
	int find(const MyString&) const;

	//returns index of first occurence of char in the string 
	int find(const char) const;

	//returns index of first occurence of substring in the string after index 'start'
	int find(const MyString&, int) const;

	//returns index of last occurence of substring in the string 
	int rfind(const MyString&) const;

	//returns index of last occurence of char in the string
	int rfind(const char) const;
};