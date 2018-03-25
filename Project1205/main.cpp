/*
 *  Created on: Mar 23, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Print entire file one screen at a time.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const int NUMBER_OF_LINES = 24;

int main()
{
	fstream textFile;
	char *filename = new char[80], ch = '\0';
	string str;
	int linenumber = 1;

	cout << "Enter name of file to read? ";
	cin >> filename;
	textFile.open(filename, ios::in);
	if(textFile.fail())
		cout << "ERROR can't open file to read." << endl;
	else{
		while(toupper(ch) != 'Q' ){
			for(int i = 0;i < NUMBER_OF_LINES;i++){
				if(textFile.eof()){
					cout << "END OF FILE." << endl;
					break;
				}
				getline(textFile, str, '\n');
				cout << linenumber << ":" << str << endl;
				linenumber++;

			}
			if(textFile.eof())
				break;
			cout << "push any character to continue or Q to quit." << endl;
			cin.ignore();
			ch = cin.get();
		}
		textFile.close();
		cout << "Closing File." << endl;
	}

	return 0;
}
