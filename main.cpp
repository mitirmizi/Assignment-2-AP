/*
* File:   main.cpp
*
* Created on December 06, 2016
*/
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "StringBuffer.h"
#include "String.h"
#include "String2.h"
#include "StringLink.h"
using namespace std;

/*
* Author: Mohammad Ismail Tirmizi
*/
int main(int argc, char** argv) {
	// main for 4. COW with reference Linking

	//char* sml = "small"; int strLength = 5; // For smal case
	//char* sml = "This is a medium size string30"; 	int strLength = 30;
	char* sml = "Finally this the last part of the code and after that i am done. This has to be especially a larg string as i want good profiling result from my compiler i gues hitting a 200 mark would be good enough";
	int strLength = 200;
	{
	StringLink strMas1(sml, strLength);
	std::cout << "master string length = " << strMas1.length() << std::endl;
	StringLink strMas2(sml, strLength);
	std::cout << "master string length = " << strMas2.length() << std::endl;
	StringLink strMas3(sml, strLength);
	std::cout << "master string length = " << strMas3.length() << std::endl;
	//multiple references
	StringLink str1(strMas1);
	std::cout << "copied string length = " << str1.length() << std::endl;
	StringLink str2(strMas2);
	std::cout << "copied string length = " << str2.length() << std::endl;
	StringLink str3(strMas3);
	std::cout << "copied string length = " << str3.length() << std::endl;
	cout << endl;
	str1.append('Z');
	std::cout << "copied string length = " << str1.length() << std::endl;
	std::cout << "charAt 5 = " << str1.charAt(5) << std::endl;
	strMas2.append('Z');
	std::cout << "master string length = " << strMas2.length() << std::endl;
	std::cout << "charAt 5 = " << strMas2.charAt(5) << std::endl;
	str3.append('Z');
	std::cout << "copied string length = " << str3.length() << std::endl;
	std::cout << "charAt 5 = " << str3.charAt(5) << std::endl;
	}
/*	// main for 3. COW with reference counting

	//char* sml = "small"; int strLength = 5; // For smal case
	//char* sml = "This is a medium size string30"; 	int strLength = 30;
	char* sml = "Finally this the last part of the code and after that i am done. This has to be especially a larg string as i want good profiling result from my compiler i gues hitting a 200 mark would be good enough";
	int strLength = 200;
	{
	String strMas1(sml, strLength);
	std::cout << "master string length = " << strMas1.length() << std::endl;
	String strMas2(sml, strLength);
	std::cout << "master string length = " << strMas2.length() << std::endl;
	String strMas3(sml, strLength);
	std::cout << "master string length = " << strMas3.length() << std::endl;
	//multiple references
	String str1(strMas1);
	std::cout << "copied string length = " << str1.length() << std::endl;
	String str2(strMas2);
	std::cout << "copied string length = " << str2.length() << std::endl;
	String str3(strMas3);
	std::cout << "copied string length = " << str3.length() << std::endl;
	cout << endl;
	str1.append('Z');
	std::cout << "copied string length = " << str1.length() << std::endl;
	std::cout << "charAt 5 = " << str1.charAt(5) << std::endl;
	strMas2.append('Z');
	std::cout << "master string length = " << strMas2.length() << std::endl;
	std::cout << "charAt 5 = " << strMas2.charAt(5) << std::endl;
	str3.append('Z');
	std::cout << "copied string length = " << str3.length() << std::endl;
	std::cout << "charAt 5 = " << str3.charAt(5) << std::endl;
} */ 
/*	// main for 2. Owned Pointers

	//char* sml = "small"; int strLength = 5; // For smal case
	//char* sml = "This is a medium size string30"; 	int strLength = 30;
	char* sml = "Finally this the last part of the code and after that i am done. This has to be especially a larg string as i want good profiling result from my compiler i gues hitting a 200 mark would be good enough";
	int strLength = 200;
	{
		String2 strMas1(sml, strLength);
		std::cout << "master string length = " << strMas1.length() << std::endl;
		String2 strMas2(sml, strLength);
		std::cout << "master string length = " << strMas2.length() << std::endl;
		String2 strMas3(sml, strLength);
		std::cout << "master string length = " << strMas3.length() << std::endl;
		//multiple references
		cout << "Before copy strMas1: " << strMas1.itsOwn << endl;
		String2 str1(strMas1);
		std::cout << "copied string length = " << str1.length() << std::endl;
		cout << "Ownership of str1: " << str1.itsOwn << endl;
		cout << "After copy strMas1: " << strMas1.itsOwn << endl << endl;

		cout << "Before copy strMas2: " << strMas2.itsOwn << endl;
		String2 str2(strMas2);
		std::cout << "copied string length = " << str2.length() << std::endl;
		cout << "Ownership of str2: " << str2.itsOwn << endl;
		cout << "After copy strMas2: " << strMas2.itsOwn << endl << endl;

		cout << "Before copy strMas3: " << strMas3.itsOwn << endl;
		String2 str3(strMas3);
		std::cout << "copied string length = " << str3.length() << std::endl;
		cout << "Ownership of str3: " << str3.itsOwn << endl ;
		cout << "After copy strMas3: " << strMas3.itsOwn << endl << endl;

		cout << endl;
		str1.append('Z');
		std::cout << "copied string length = " << str1.length() << std::endl;
		std::cout << "charAt 5 = " << str1.charAt(5) << std::endl;
		strMas2.append('Z');
		std::cout << "master string length = " << strMas2.length() << std::endl;
		std::cout << "charAt 5 = " << strMas2.charAt(5) << std::endl;
		str3.append('Z');
		std::cout << "copied string length = " << str3.length() << std::endl;
		std::cout << "charAt 5 = " << str3.charAt(5) << std::endl;
}	*/
/*	// main for 1. Copied Pointers
	
	//char* sml = "small"; int strLength = 5; // For smal case
	//char* sml = "This is a medium size string30"; 	int strLength = 30;
	char* sml = "Finally this the last part of the code and after that i am done. This has to be especially a larg string as i want good profiling result from my compiler i gues hitting a 200 mark would be good enough";
	int strLength = 200;
{
	String strMas1(sml, strLength);
	std::cout << "master string length = " << strMas1.length() << std::endl;
	String strMas2(sml, strLength);
	std::cout << "master string length = " << strMas2.length() << std::endl;
	String strMas3(sml, strLength);
	std::cout << "master string length = " << strMas3.length() << std::endl;
	//multiple references
	String str1(strMas1);
	std::cout << "copied string length = " << str1.length() << std::endl;
	String str2(strMas1);
	std::cout << "copied string length = " << str2.length() << std::endl;
	String str3(strMas1);
	std::cout << "copied string length = " << str3.length() << std::endl;
	cout << endl;
	str1.append('Z');
	std::cout << "copied string length = " << str1.length() << std::endl;
	std::cout << "charAt 5 = " << str1.charAt(5) << std::endl;
	strMas2.append('Z');
	std::cout << "master string length = " << strMas2.length() << std::endl;
	std::cout << "charAt 5 = " << strMas2.charAt(5) << std::endl;
	str3.append('Z');
	std::cout << "copied string length = " << str3.length() << std::endl;
	std::cout << "charAt 5 = " << str3.charAt(5) << std::endl;
} */
	system("pause");
	return 0;
}

