#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
// default constructor
String::String() 
{
    this->_str = new StringBuffer();
}

// destructor
String::~String() 
{
    //decrement the refcount and only if it is =0, delete the buffer.
    if (--this->_str->_refcount < 1) {
		cout << "String Destructor" << endl;
		delete this->_str;
    }
}

//copy a const String into this string // Copy constructor #me 
String::String(const String& newString) {
    this->_str = newString._str;
    //increment the refcount by 1
    ++this->_str->_refcount;

	// For 1. Copied pointer checking
	//this->_str = new StringBuffer(*newString._str);
}

//copy a char* into your string
String::String(char* newString, int length) {
	char* chrPtr = new char[length];
	for (int i = 0; i < length; i++)
	{
		chrPtr[i] = newString[i];
	}
    this->_str = new StringBuffer(chrPtr, length);
    //increment the refcount by 1
    this->_str->_refcount = 1;

	// 1.For copied pointer
	
}

void String::append(char c) {

    //    char* tempbuf = new char[this->_str->length()+1];
    //    this->_str->revSmartCopy(tempbuf);
    if (this->_str->_refcount > 1) {
        //more than 1 reference to this string
        auto_ptr<StringBuffer> newdata(new StringBuffer);
        newdata.get()->reserve(this->_str->length() + 1);
        newdata.get()->smartCopy(this->_str);

        //decrement the reference count to this String
        --this->_str->_refcount;

        //cout<<"length at newdata"<<newdata.get()->length()<<endl;
        //now split the object instances
        this->_str = newdata.release();
    } else {
		// #me if only this pointing then we reserve more mem and add new char
        this->_str->reserve(this->_str->length() + 1);
    }
    //copy the new character at the end of this string
    this->_str->append(c);
}

//get length of the string
int String::length() const {
	return this->_str->length();
}

//get character at index if it is less than length
char String::charAt(int index) const {
    if (index < this->_str->length()) {
        return this->_str->charAt(index);
    } else {
        //throw new IndexOutOfBoundException();
		cout << "Index out of bound\n";
		return '\0';
    }
}