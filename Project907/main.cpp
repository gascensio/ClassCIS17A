/*
 * main.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        days: MW Time: 12:45p - 2:30
 */
// This program is based on program 9-19 from Starting Out
// With C++ From Control Structures Through Objects 9th
// edition.
//
// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
using namespace std;

// Function prototypes
void RevArrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

int main()
{
	const int NUM_DONATIONS = 15; // Number of donations

	// An Array of  containing the donation amounts.
	int donations[NUM_DONATIONS] = { 5, 100, 5, 25, 10,
								   5, 25,  5, 5,  100,
								   10, 15, 10, 5, 10 };
	//An array of pointers to int.
	int *arrPtr[NUM_DONATIONS] = {nullptr, nullptr, nullptr, nullptr, nullptr,
								  nullptr, nullptr, nullptr, nullptr, nullptr,
								  nullptr, nullptr, nullptr, nullptr, nullptr,};

	// Each element of arrPtr is a pointer to int. Make each
	// element point to an element in the donations array.
	for(int count = 0; count < NUM_DONATIONS; count++)
	arrPtr[count] = &donations[count];

	// Sort the elements of the array of pointers.
	RevArrSelectSort(arrPtr, NUM_DONATIONS);

	// Display the donations using the array of pointers. This
	// will display them in sorted order.
	cout << "The donations, sorted in ascending order, are: \n";
	showArrPtr(arrPtr, NUM_DONATIONS);

	// Display the donations, in their original order.
	cout << "The donations in thier original order, are: \n";
	showArray(donations, NUM_DONATIONS);

	return 0;
}

/****************************************************************
 * definition of function RevArrSelectSort.						*
 * This function performs an descending order selection sort on 	*
 * arr, which is an array of pointers. Each element of array	*
 * points to an element of a second array. After the sort,		*
 * arr will point to the elements of the seconed array in 		*
 * ascending order.												*
 ****************************************************************/
void RevArrSelectSort(int *arr[], int size)
{
	int startScan, minIndex;
	int *maxElem;

	for(startScan = 0; startScan < (size - 1); startScan++){
		minIndex = startScan;
		maxElem = arr[startScan];
		for(int index = startScan + 1; index < size; index++){
			if(*(arr[index]) > *maxElem){ //Reverse the sort
				maxElem = arr[index];
				minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = maxElem;
	}
}
/************************************************************
 * Definition of function showArray.						*
 * this function displays the contents of arr, size is the	*
 * number of elements.										*
 ************************************************************/

void showArray(const int arr[], int size)
{
	for (int count = 0; count < size; count++)
		cout << arr[count] << " ";
	cout << endl;
}
/****************************************************************
 * Definition of function showArrPtr.							*
 * This function displays the contents of the array pointed to	*
 * by arr. size is the number of elements.						*
 ****************************************************************/

void showArrPtr(int *arr[], int size)
{
	for(int count = 0; count < size; count++)
		cout << *(arr[count]) << " ";
	cout << endl;
}




