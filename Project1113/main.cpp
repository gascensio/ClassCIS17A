/*
 *  Created on: Mar 20, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 *     Purpose: Simulates a drink vending machine.
 */

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

struct Drink {
	char name[15];
	float cost;
	int numofdrinks;
};

const int NUMDRINKS = 5;

void PrintMenu(Drink Machine[], int size);

int main()
{
	Drink Machine[NUMDRINKS] = {{"Cola", 0.75, 20},
						{"Root Beer", 0.75, 20},
						{"Lemon-Line", 0.75, 20},
						{"Grape Soda", 0.80, 20},
						{"Cream Soda", 0.80, 20}
						};
	char choise = '\040';
	float amount = 0;

	while(toupper(choise) != 'Q' ){
		PrintMenu(Machine, NUMDRINKS);
		cout << "Make a selection? ";
		choise = cin.get();
		if(toupper(choise) >= 65 && toupper(choise) < (65 + NUMDRINKS)){
			cout << "Enter cash up to $1.00?";
			cin >> amount;
			while (amount > 1.00 || amount < 0){
				cout << amount << " Invalid amount try again";
				cin >> amount;
			}
			if(Machine[toupper(choise) - 65].numofdrinks > 0){
			//	cout << "number of drinks is " << Machine[toupper(choise) - 65].numofdrinks << endl;
				if (amount >= Machine[toupper(choise) - 65].cost ){
					Machine[toupper(choise) - 65].numofdrinks -= 1;
					amount = amount - Machine[toupper(choise) - 65].cost;
					cout << "Your change is " << fixed << setprecision(2) << amount << endl;
				}else
					cout << "insufficient funds" << endl;
			} else {
				cout << "Machine is out of " << Machine[choise - 65].name
						<< "." << endl;
			}
		}else if(toupper(choise) != 'Q'){
			cout << "invalid choice try again." << endl;
		}
		cin.ignore();
	}
	cout << "Exit";
}
/**********************************************************
 *
 */
void PrintMenu(Drink Machine[], int size)
{
	const int KEY = 5;
	int count;
	char ch = 65;

	cout << left << setw(KEY+1)<< "key" << setw(20) << "Drink Name" << 
                setw(15) << "Cost" << "Number in Machine" << endl;
	for(int c = 0; c < 60; c++){
		cout << "-";
	}
	cout << endl;
	for(count = 0;count < size; count++, ch++){
		cout << left << setw(KEY)<< ch << " " 
                    << setw(20)<< Machine[count].name
                    << setw(15) << Machine[count].cost
                    << Machine[count].numofdrinks << endl;
	}
}
