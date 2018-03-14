/* 
 * File:   main.cpp
 * Author: Gordon Ascensio
 * Created on 3/9/2018
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
int read(char array[])
{
	int index = 0;

	cin >> array;

	while(array[index] != '\0')
		index++;
	return index;
}
/**************************************************************
 *  the sort() function sorts an array of char(s)
 */
void sort(char array[],int size)
{
	bool swap;
	char temp;
	short index;

	do{
		swap = false;
		for(index = 0; index < (size - 1); index++){
			if(array[index] > array[index + 1]){
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				swap = true;
			}
		}
	}while(swap);
}
/**********************************************************
 * the print() function prints a array.
 */
void print(const char array[], int size)
{
	int index;

	for(index = 0; index < size; index++)
		cout << array[index];
}
