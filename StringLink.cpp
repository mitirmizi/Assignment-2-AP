#include "StringBuffer.h"
#include "StringLink.h"
#include <memory>
#include <iostream>
using namespace std;
// Implementing COW with reference linking
// default constructor
StringLink::StringLink()
{
	this->_str = new StringBuffer();
}

// destructor
StringLink::~StringLink()
{
	// case 1 only element: Delete the object 
	if (this->nxt == this)
	{
		if (--this->_str->_refcount == 0)
			cout << "only one element in the list\n";
		cout << "string" << endl;
		delete this->_str;
	}
	// case 2: more than 1 element
	else
	{
		// Remove this object from the chain
		cout << "Breaking chain as there are multiple elements\n";
		this->prv->nxt = this->nxt;
		this->nxt->prv = this->prv;
		// debugging
		--this->_str->_refcount;
	}
}

// 1st instance of pointer
StringLink::StringLink(char* newString, int length) {
	char* chrPtr = new char[length];
	for (int i = 0; i < length; i++)
	{
		chrPtr[i] = newString[i];
	}
	this->_str = new StringBuffer(chrPtr, length);

	this->_str->_refcount = 1;
	this->nxt = this;
	this->prv = this;
}

// 2nd and so on Copy Constructor 
StringLink::StringLink(StringLink& newString)
{
	this->_str = newString._str;

	if (this->nxt == this)
	{
		++this->_str->_refcount;
		this->nxt = newString.nxt;
		this->prv = newString.prv;
		newString.nxt = this;
		newString.prv = this;
	}
	else
	{
		//Reference linking
		++this->_str->_refcount;
		// Back of this
		this->prv = newString.prv;
		newString.prv->nxt = this;

		// Front of this
		this->nxt = &newString;
		newString.prv = this;
	}
}

void StringLink::append(char c) {

	//    char* tempbuf = new char[this->_str->length()+1];
	//    this->_str->revSmartCopy(tempbuf);
	// case 1 only element: 
	if (this->nxt == this)
	{
		// #me if only this pointing then we reserve more mem and add new char
		this->_str->reserve(this->_str->length() + 1);
	} 
	// case 2: more than 1 element
	else
	{
		//more than 1 reference to this string
		auto_ptr<StringBuffer> newdata(new StringBuffer);
		newdata.get()->reserve(this->_str->length() + 1);
		newdata.get()->smartCopy(this->_str);

		// Remove this object from the chain
		this->prv->nxt = this->nxt;
		this->nxt->prv = this->prv;
		// debugging
		--this->_str->_refcount;

		this->_str = newdata.release();
	}
	//copy the new character at the end of this string
	this->_str->append(c);
}

//get length of the string
int StringLink::length() const {
	return this->_str->length();
}

//get character at index if it is less than length
char StringLink::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();
		cout << "Index out of bound\n";
		return '\0';
	}
}