/*
 * File:   main.cpp
 * Author: Gordon Ascensio
 * Created on 3/11/2018
 * Purpose:  Convert a number to English check amount
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
	unsigned short thousands, hundreds, tens, ones;
    unsigned short number;
    bool teenflag = false;

    //Input or initialize values Here
    cout<<"Input an integer [1-3000] convert to an English Check value."<<endl;
    cin>>number;

    //Calculate the 1000's, 100's, 10's and 1's
    if (number > 3000)
    	return 0;
    thousands = number / 1000;
    number -= thousands * 1000;
    hundreds = number / 100;
    number -= hundreds * 100;
    tens = number / 10;
    number -= tens * 10;
    ones = number;

    //Output the check value
    switch(thousands){
	case 3:
		cout << "Three Thousand ";
		break;
	case 2:
		cout << "Two Thousand ";
		break;
	case 1:
		cout << "One Thousand ";
		break;
	case 0:
		break;
	default:
		cout << "ERROR ";
		break;
  }
// Prints hundreds
  switch(hundreds){
  case 9:
	  cout << "Nine Hundred ";
	  break;
  case 8:
	  cout << "Eight Hundred ";
 	  break;
  case 7:
	  cout << "Seven Hundred ";
 	  break;
  case 6:
	  cout << "Six hundred ";
 	  break;
  case 5:
	  cout << "Five Hundred ";
	  break;
  case 4:
	  cout << "Four Hundred ";
 	  break;
  case 3:
	  cout << "Three Hundred ";
 	  break;
  case 2:
	  cout << "Two Hundred ";
 	  break;
  case 1:
	  cout << "One Hundred ";
 	  break;
  case 0:
 	  break;
  default:
	  cout << "ERROR ";
	  break;
  }
  // Prints tens
  switch(tens){
   case 9:
	  cout << "Ninety ";
 	  break;
   case 8:
	  cout << "Eighty ";
  	  break;
   case 7:
	  cout << "Seventy ";
  	  break;
   case 6:
	  cout << "Sixty ";
  	  break;
   case 5:
	  cout << "Fifty ";
 	  break;
   case 4:
	  cout << "Forty ";
  	  break;
   case 3:
	  cout << "Thirty ";
  	  break;
   case 2:
	  cout << "Twenty ";
  	  break;
   case 1:
	  teenflag = true;
  	  break;
   case 0:
  	  break;
   default:
 	  cout << "ERROR ";
 	  break;
   }

 // Prints teens and ones
  switch(ones){
   case 9:
	   if(teenflag == true)
		   cout << "Nineteen ";
	   else
		   cout << "Nine ";
 	  break;
   case 8:
	   if(teenflag == true)
		   cout << "Eighteen ";
	   else
		   cout << "Eight ";
  	  break;
   case 7:
	   if(teenflag == true)
		   cout << "Seventeen ";
	   else
		   cout << "Seven ";
  	  break;
   case 6:
	   if(teenflag == true)
		   cout << "Sixteen ";
	   else
		   cout << "Six ";
  	  break;
   case 5:
	   if(teenflag == true)
		   cout << "Fifteen ";
	   else
		   cout << "Five ";
 	  break;
   case 4:
	   if(teenflag == true)
		   cout << "Fourteen ";
	   else
		   cout << "Four ";
  	  break;
   case 3:
	   if(teenflag == true)
		   cout << "Thirteen ";
	   else
		   cout << "Three ";
  	  break;
   case 2:
	   if(teenflag == true)
		   cout << "Twelve ";
	   else
		   cout << "Two ";
  	  break;
   case 1:
	   if(teenflag == true)
		   cout << "Eleven ";
	   else
		   cout << "One ";
  	  break;
   case 0:
	   if(teenflag == true)
		   cout << "Ten ";
  	  break;
   default:
 	  cout << "ERROR ";
 	  break;
   }
    cout<<"and no/100's Dollars"<<endl;

    //Exit
    return 0;
}
