#ifndef STRINGBUFFER_H
#define	STRINGBUFFER_H

class StringBuffer{
public :
    StringBuffer();
    ~StringBuffer();
    StringBuffer(const StringBuffer&);
    StringBuffer(char*,int);

    char charAt(int) const;
    int length() const;
	void smartCopy(StringBuffer*); // overrides original str with user str as much as it can
    void smartCopy(char*,int); // overrides original str till length of new string, can cause problems
    void revSmartCopy(char* newString); // overrides user str till own length, can cause problems
    void reserve(int); // Okay
    void append(char);
    int _refcount;
	void getStringBuf();
private:
    char* _strbuf;
    int _length;
    
};

#endif	/* STRINGBUFFER_H */

