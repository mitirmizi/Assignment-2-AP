#include "StringBuffer.h"
#include "String2.h"
#include <memory>
#include <iostream>
using namespace std;

// Implements Owned pointers

// Def Constructor
String2::String2()
{
	this->_str = new StringBuffer();
	itsOwn = true;
}

// Destructor
String2::~String2() {
	//decrement the refcount and only if it is =0, delete the buffer.
	if (itsOwn) 
	{
		cout << "string" << endl;
		delete this->_str;
	}
	else
	{
		cout << "Not my responsibility \n";
	}
}

// Copy Constructor ownership transfer
String2::String2(const String2& newString)
{
	this->_str = newString._str;
	this->itsOwn = true;
	newString.itsOwn = false;
}

//copy a char* into your string
String2::String2(char* newString, int length) {
	char* chrPtr = new char[length];
	for (int i = 0; i < length; i++)
	{
		chrPtr[i] = newString[i];
	}
	this->_str = new StringBuffer(chrPtr, length);
	//give ownership to this
	this->itsOwn = true;
}

void String2::append(char c) {

	if (itsOwn) 
	{
		this->_str->reserve(this->_str->length() + 1);
		this->_str->append(c);
	}
	else 
	{
		cout << "Sorry this is not the owner so it can not append\n";
	}
}

//get length of the string
int String2::length() const {
	return this->_str->length();
}

char String2::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();
		cout << "Index out of bound\n";
		return '\0';
	}
}