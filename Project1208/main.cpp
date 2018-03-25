/*
 *  Created on: Mar 24, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Array/binary file functions.
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Global Constants and Variables.
const char *FILENAME = "ArrayOFInt.bin";
const int ARRAYSIZE = 6;

// Function prototypes
int arrayToFile(const char *filename, int array[], int size);
int FillToArray(const char *filename, int array[], int size);

int main()
{
	int array[ARRAYSIZE] = {1234, 5678, 7787, 6776, 3456, 4567};
	int array2[ARRAYSIZE] = {0,0,0,0,0,0};

	if(arrayToFile(FILENAME, array, ARRAYSIZE))
		cout << "successfully wrote." << endl;
	else
		return 1;
	if(FillToArray(FILENAME, array2, ARRAYSIZE)){
		for(int c = 0;c < ARRAYSIZE;c++){
			cout << array2[c] << " ";
		}
		cout << endl << "successfully read." << endl;
	}
	return 0;
}
/**********************************************************
 * Function arrayToFile() saves an array of any size
 * to a binary files named filename.
 */
int arrayToFile(const char *filename, int array[], int size)
{
	fstream ArrayFile;

	cout << "Strating ArrayToFile" << endl;
	ArrayFile.open(filename, ios::out | ios::binary);
	if(ArrayFile.fail()){
		cout << "Failed to Open File." << endl;
		return 0;
	}
	ArrayFile.write(reinterpret_cast<char *>(array),(size*4));
	ArrayFile.close();
	return 1;
}
/**********************************************************
 * Function FillToArray() fills an array of size from
 * a binary file named filename.
 */
int FillToArray(const char *filename, int array[], int size)
{
	fstream ArrayFile;

	cout << "Starting FillToArray" << endl;

	ArrayFile.open(filename, ios::in | ios::binary);
	if(ArrayFile.fail()){
			cout << "Failed to Open File." << endl;
			return 0;
		}
	ArrayFile.read(reinterpret_cast<char *>(array), (size * 4));
	ArrayFile.close();
	return 1;
}
