
/* 
 * File:   main.cpp
 * Author: Gordon Ascensio
 * based on From From Control Structures 9th edition.
 * Created on February 26, 2018, 5:16 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

const float YEN_PER_DOLLAR = 98.93;
const float EUROS_PER_DOLLAR = 0.74;

int main() {
    float dollars;
    float yen, euros;
    cout << "Enter units in dollars to convert? " ;
    cin >> dollars;
    yen = dollars * YEN_PER_DOLLAR;
    euros = dollars * EUROS_PER_DOLLAR;
    cout << fixed << setprecision(2) << dollars << " dollars is equal to " << yen 
            << " yen and " << euros << " euros" << endl;
    return 0;
}

