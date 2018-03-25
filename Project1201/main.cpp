/*
 *  Created on: Mar 23, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Print Head of File.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUMBER_OF_LINES = 10;

int main()
{
	fstream textFile;
	char *filename = new char[80];
	string str;

	cout << "Enter name of file to read? ";
	cin >> filename;
	textFile.open(filename, ios::in);
	if(textFile.fail())
		cout << "ERROR can't open file to read." << endl;
	else{
		for(int i = 0;i < NUMBER_OF_LINES;i++){
			if(textFile.eof()){
				cout << "END OF FILE." << endl;
				break;
			}
			getline(textFile, str, '\n');
			cout << str << endl;

		}
		textFile.close();
		cout << "Closing File." << endl;
	}

	return 0;
}
