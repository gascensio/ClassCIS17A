/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gordon Ascensio
 * based on From From Control Structures 9th edition.
 * Created on February 28, 2018, 9:05 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    float tanksize; // the capacity of the gas tank.
    float range;    // number of miles on full tank of gas.
    float mpg;      // Miles per gallon.
    
    cout << "This program will calculates MPG." << endl;
    cout << "Enter gas tank size? ";
    cin >> tanksize;
    cout << "Enter gas range on full tank? ";
    cin >> range;
    mpg = range / tanksize;
    cout << "The MPG is " << mpg << endl;
    return 0;
}

