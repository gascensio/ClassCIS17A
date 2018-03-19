/*
 * main.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Moving data plus profits with structures 
 */
// Include header files
#include <iostream>
#include <iomanip>
using namespace std;

// Constant Definitions
const int LINE = 40;

// Structures and global declarations
struct MovieData {
	char title[LINE];
	char director[LINE];
	int year;
	int langth;
        int cost;
        int revenue; 
};
// Function prototypes
void DisplayMovieDat(MovieData Movie);

int main(int argc, char** argv) 
{
	MovieData Movie1 = {"Diamonds Are Forever","Guy Hamilton", 1971, 120, 7500000, 120000000};
	MovieData Movie2 = {"The Right Stuff","Philip Kaufman", 1983, 192, 27000000, 21100000 };

	DisplayMovieDat(Movie1);
	cout << endl;
	DisplayMovieDat(Movie2);
        return 0;

}
void DisplayMovieDat(MovieData Movie)
{
	const int TABOVER = 20;
	cout << right << setw(TABOVER)<< "Title: " << Movie.title << endl;
	cout << setw(TABOVER) << "Director: " << Movie.director << endl;
	cout << setw(TABOVER) << "Year Released: " << Movie.year << endl;
	cout << setw(TABOVER) << "Running Time: " << Movie.langth << " minutes." << endl;
        cout << setw(TABOVER) << "Profits: " << Movie.revenue - Movie.cost << endl;
	return;
}


