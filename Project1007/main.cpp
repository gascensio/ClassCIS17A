/*
 * main.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Count the number of words in C-string.
 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

using namespace std;

const int NAMESIZE = 20;
const int LINESIZE = 80;

int main()
{
	char first[NAMESIZE], middle[NAMESIZE], last[NAMESIZE];
	char *line = new char[LINESIZE];

	cout << "Enter your name? ";
	cin >> first >> middle >> last;

   line = strcpy(line, last);   //insert last name.
   line = strcat(line, ", ");
   line = strcat(line, first);  //inserts first name.
   line = strcat(line, " ");
   line = strcat(line, middle); //inserts middle name.

   cout << line << endl;

   delete line;

}
