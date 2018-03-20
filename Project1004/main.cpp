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
using namespace std;

const int LINESIZE = 250;

//Function prototype
void getline(char *);
int wordlettercount(char *, float &);

int main()
{
	char str[LINESIZE];
	float avrg = 100;

	cout << "enter string:";
	getline(str);
	cout << str << endl;
	cout << " Word count is " << wordlettercount(str, avrg) << " Average number of letters ";
	cout << fixed << setprecision(2) << avrg << endl;

}
/**********************************************************
 * Function definition getline(char *)
 * Gets alpha numeric input from keyboard and places
 * it in to the c-string str.
 */
void getline(char *str)
{
	int index = 0;
	//cin.ignore();
	do{
		str[index] = cin.get();
	}while(str[index++] != '\n');
	str[index-1] = '\0';
}
/**********************************************************
 * Function definition for wordlettercount(char *)
 * Counts the number of words in a c-string and returns the
 * average number of letters
 *
 */
int wordlettercount(char *str, float &avrgletters)
{
	int wcount = 0;
	int i = 0, letters = 0;

	while(*(str+i) != '\0'){
		if(isalpha(*(str+i))|| isdigit(*(str+i))){
			wcount++;
			while(isalpha(*(str+i)) || isdigit(*(str+i))){
				letters++;
				i++;
			}
		}
		while(isspace(*(str+i)) || ispunct(*(str+i)))
		    i++;
	}
	avrgletters = (float)letters / wcount;
	return wcount;
}
