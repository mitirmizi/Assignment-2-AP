/*
* File:
*
* Created on December 05, 2016
*
* Implements Owned pointers
*/
// Implementing COW with reference linking
#ifndef STRINGLINK_H
#define	STRINGLINK_H

class StringLink {
private:
	//StringBuffer* itsPtr;
public:
	StringBuffer* _str;
	StringLink* nxt;
	StringLink* prv;
	StringLink();
	~StringLink();
	StringLink(StringLink& );
	StringLink(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
};

#endif	/* STRING2_H */
