/*
 *  Created on: Mar 23, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Print entire fill one screen at a time.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;
const int LINELEN = 80;
const int STRLEN = 32;

int main()
{
	char *filename = new char[LINELEN];
	char *cstr, *key = new char[STRLEN];
	int langth, count = 0;
	int linenumber = 1;
	string line;

	cout << "Type in name of file to read from? ";
	cin >> filename;
	cout << "Type in string to search for? ";
	cin >> key;

	langth = strlen(key);

	fstream TextFile(filename, ios::in);

	if(TextFile.fail()){
		cout << "File dose not exist." << endl;
		return 0;
	}
	while(!TextFile.eof()){
		getline(TextFile, line, '\n');
		cstr = (char*)line.c_str();
		if(strstr(cstr, key) != NULL){
			count++;
			char *temp = cstr;
			cstr = strstr(cstr, key);
			cstr = &cstr[langth];
			while(strstr(cstr, key) != NULL){
				count++;
				cstr = strstr(cstr, key);
				cstr = &cstr[langth];
			}
			cout << linenumber << ":" << temp << endl;
		}
		linenumber++;
	}
	cout << "Occurrence of \042"<< key << "\042 : " << count << endl;
	TextFile.close();
}
