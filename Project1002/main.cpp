/*
 *  Created on: Mar 25, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Print cstring backwards.
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAXLINE = 80;

void PrntBackwards(char *str);
void getline(char *str);

int main()
{
	char *cstr = new char[MAXLINE];

	cout << "Enter a C-String? ";
	getline(cstr);
	cout << "The C-string backwards: ";
	PrntBackwards(cstr);

	delete cstr;
}
/**********************************************************
 * Prints a C-string backwards.
 */
void PrntBackwards(char *str)
{
	int index = 0;

	while(str[index] != '\0')
		index++;
	index--; //deincrements the index by one so that the null character is not printed.
	while(index >= 0)
		cout << str[index--];

}
/*********************************************************
 * gets a C-string from stdio.
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
