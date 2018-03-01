
/* 
 * File:   main.cpp
 * Author: Gordon Ascensio
 * based on From From Control Structures 9th edition.
 * Created on February 27, 2018, 5:49 PM
 */

#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "Enter first numbers: " ;
    cin >> a;
    cout << "Enter second number: " ;
    cin >> b;
    if(a > b)
        cout << b << " is the smaller number and " << a 
                << " is the larger number."  << endl;
    else if (a < b)
        cout << a << " is the smaller number and " << b 
                << " is the larger number." << endl;
    else 
        cout << "both numbers are the same." << endl;
    return 0;
    
}

