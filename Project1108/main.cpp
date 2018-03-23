/*
 *  Created on: Mar 21, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Customer Accounts.
 */
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

using namespace std;

const int NUMBER_OF_CUSTOMER = 20;

struct Customer {
	char name[32];
	char address[40];
	char city[20];
	char state[20];
	char zip[6];
	char phone[15];
	float balance;
    char date[11];
};

void EnterAccount(Customer &Account);
void PrintAccount(Customer Account);
void PrintAllAccounts(Customer Accounts[], int size);
void getline(char *);
void FindAccount(Customer Accounts[], int size, char *str);

int main()
{
	Customer Accounts[NUMBER_OF_CUSTOMER] = {{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"},
												{ "\0", "\0", "\0", "\0", "\0", "\0", 0.0, "\0"}};
	char ch, *str = new char[32];
	int newaccindex = 0;
	int accnumber;


	while(toupper(ch) != 'Q'){
		cout << "MENU" << endl;
		cout << "A: Enter new account." << endl;
		cout << "B: Print an account." << endl;
		cout << "C: Print all accounts." << endl;
                cout << "D: Find Account" << endl;
		cout << "Q: Quit." << endl;
		ch = cin.get();
		if(toupper(ch) == 'A'){
			EnterAccount(Accounts[newaccindex]);
			newaccindex++;
		}else if(toupper(ch) == 'B'){
			cout << "Enter Account number 1 to 20? ";
			cin >> accnumber;
			while (accnumber >= NUMBER_OF_CUSTOMER || accnumber < 1){
				cout << "pick a number between 1 and 20? ";
				cin >> accnumber;
			}
			PrintAccount(Accounts[accnumber-1]);
		}else if(toupper(ch) == 'C'){
			PrintAllAccounts(Accounts, NUMBER_OF_CUSTOMER);
		}else if(toupper(ch) == 'D'){
                    cout << "Search for name? ";
                    getline(str);
                   FindAccount(Accounts, NUMBER_OF_CUSTOMER, str);
                }
		cin.ignore();
	}
	return 0;
}
/**********************************************************
 * Function definition EnterAccount() lets the user
 * input a structure of type Customer
 */
void EnterAccount(Customer &Account)
{
	cout << "Enter name? ";
	getline(Account.name);
	cout << "Enter Address? ";
	getline(Account.address);
	cout << "Enter the city? ";
	getline(Account.city);
	cout << "Enter the state? ";
	getline(Account.state);
	cout << "Enter the ZIP? ";
	getline(Account.zip);
	cout << "Enter a telephone number? ";
	getline(Account.phone);
	cout << "Enter balance? $";
	cin >> Account.balance;
	while(Account.balance < 0){
		cout << "You can not enter Negative balance try again? $";
		cin >> Account.balance;
	}
	cout << "Enter date of last payments? ";
	//cin.ignore();
	getline(Account.date);
}
/**********************************************************
 * Function Definition PrintAccount() Prints one account
 * of Customer type.
 */
void PrintAccount(Customer Account)
{
	cout << "Name: " << Account.name << endl;
	cout << "Address: " << Account.address << endl;
	cout << "City: " << Account.city
			<< " State: " << Account.state
			<< " and ZIP: " << Account.zip << endl;
	cout << "Telephone: " << Account.phone << endl;
	cout << "Balance: " << Account.balance << endl;
	cout << "Date of Last Payment: " << Account.date << endl << endl;
}
/**********************************************************
 * Function definition PrintAllAccounts() prints an array
 * of type Customer.
 */
void PrintAllAccounts(Customer Accounts[], int size)
{
	int i;

	for(i = 0;i < size;i++){
		PrintAccount(Accounts[i]);
	}
}
/**********************************************************
 * Function Definition getline() lets the user input
 * a char pointer ,
 */
void getline(char *line)
{
	int i = 0; // index

	line[i] = cin.get();
	if(line[i] == '\n' )
		line[i] = cin.get();
	while(line[i] != '\n'){
		i++;
		line[i] = cin.get();
	}
	line[i] = '\0';
}
void FindAccount(Customer Accounts[], int size, char *str)
{
    int i = 0;
    bool found = false;

    if(strcmp(Accounts[i].name, str) == 0){
        found = true;
    }
    while(strcmp(Accounts[i].name, str) != 0 && i < size){
        i++;
        if(strcmp(Accounts[i].name, str) == 0){
            found = true;
        }
    }
    if (found == true)
        PrintAccount(Accounts[i]);
    else
    	cout << "Can't Find Account";
}
