/*
* File:
*
* Created on December 05, 2016
*
* Implements Owned pointers
*/

#ifndef STRING2_H
#define	STRING2_H

class String2 {
private:
	//StringBuffer* itsPtr;
public:
	StringBuffer* _str;
	mutable bool itsOwn;
	String2(const String2&);
	String2();
	~String2();
	String2(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
};

#endif	/* STRING2_H */