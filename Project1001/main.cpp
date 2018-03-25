/*
 *  Created on: Mar 25, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: String length.
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAXLINE = 80;

int stringlength(char *);
void getline(char *);

int main()
{
	char *cstr = new char[MAXLINE]; // C-String to be checked

	cout << "Enter C-string? ";
	getline(cstr);

	cout << endl << "The length of the C-string is " << stringlength(cstr);

	delete cstr;
	return 0;

}
/**********************************************************
 *  Returns length of cstring str.
 */
int stringlength(char *str)
{
	int length = 0;

	while(str[length] != '\0')
		length++;

	return length;
}
/*********************************************************
 * gets a Cstring from stdio.
 *
 */
void getline(char *str)
{
	int index = 0;

	*str = cin.get();
	while(*(str+index) != '\n')
		*(str+(++index)) = cin.get();
	*(str+index) = '\0';
}


