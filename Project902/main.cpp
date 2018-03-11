/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * main.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        days: MW Time: 12:45p - 2:30
 *
 */
#include <iostream>

using namespace std;


//Function prototype
int *putScores(int &size);
void sortArray(int Array[], int size);
void printScores(int array[], int size);
float averageScores(int array[], int size);

int main()
{
	int *array, size = 0;

	array = putScores(size);
	sortArray(array, size);
	printScores(array, size);
	cout << "Average score is " << averageScores(array, size) << endl;
}
/*********************************************************************
 * Function putScores lets the user allocate a dynamic array
 * and enter a number of scores.
 */
int *putScores(int &size)
{
	int count, *array;

	// do while loop gets and validates the size of
	// the array for holding the scores.
	do{
		cout << "type in size of score list?" ;
		cin >> size;
	}while( size < 2);

	array = new int[size];

	for(count = 0; count < size; count++)
	{
		do{
			cout << "enter score #" << count + 1 << "? ";
			cin >> *(array + count);
		}while(*(array + count) < 0);
	}
	return array; // returns the size of the array;
}
/******************************************************************
 * The sortArray function bubble sorts an array of integers
 * using pointer notation.
 */
void sortArray(int array[], int size)
{
	bool swap;
	int temp;

	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++){
			if(*(array + count) > *(array + count + 1))
			{
				temp = *(array + count);
				*(array + count) = *(array + count + 1);
				*(array + count + 1) = temp;
				swap = true;

			}
		}
	}while(swap);
}
/*******************************************************************
 * the printScores function prints a array of integers of
 * any size.
 */
void printScores(int array[], int size)
{
	cout << "Test score list:" << endl;
	for(int count = 0; count < size; count++)
		cout << "node "<< count << " > " << array[count] << endl;
}
/********************************************************************
 * The averageScores computes the average of an array on integers
 * the array is the size passed to it from the calling function.
 */
float averageScores(int array[], int size)
{
	int total = 0;
	int count;
	float average;

	// Total scores in array.
	for(count = 0; count < size; count++)
	{
		total += array[count];
	}

	average = (float)total / (float)size; 	// calculate average.
	return average;
}
