

/* 
 * File:   main.cpp
 * Author: Gordon Ascensio
 * based on From From Control Structures 9th edition
 * Created on February 28, 2018, 9:55 AM
 */

#include <iostream>

using namespace std;

float ftoc(float fahr);

/*
 * 
 */
int main() {
    
    float fahrenheit;

    cout << "This program converts Fahrenheit to Celsius." << endl;
    cout << "Enter Temperature in Fahrenheit? ";
    cin >> fahrenheit;
    cout << fahrenheit << " degrees Fahrenheit is " << ftoc(fahrenheit) << " Celsius." << endl;
    return 0;
}
/* Function converts Fahrenheit to celsius.
 */
float ftoc(float fahr)
{
    float celsius;
    
    celsius = 5.0 / 9.0 * (fahr - 32);
    return celsius;
}
