/*
 * main.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Weather Data Structure.
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
	JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

struct monthlyweather{
	float Rainfall;
	float HighTemp;
	float LowTemp;
	float AverageTemp;
};

void EnterWeather(monthlyweather month[]);
void Computyearrainfall(monthlyweather year[], float &average, float &total);
int findhighesttemp(monthlyweather year[]);
int findlowesttemp(monthlyweather year[]);
void printmonth(month m);

int main()
{
	monthlyweather yearofweather[12];	// One years weather records.
	float TotalRain;		// Total yearly rainfall
	float AverageRain;		// Monthly average for the year
	float AverageTemp = 0.0;	// Average temperature
	int index; 			// Month index


	EnterWeather(yearofweather);
	Computyearrainfall(yearofweather, AverageRain, TotalRain);
	index = findhighesttemp(yearofweather);

	cout << "Average monthly rainfall is " << AverageRain << " inches" << endl;
	cout << "The total rainfall for the year is " << TotalRain << " inches" << endl;
	cout << "The highest temperature of the year was " << yearofweather[index].HighTemp
			<< " degrees in the month of ";
	printmonth((month)index);
	cout << "." << endl;
	index = findlowesttemp(yearofweather);
	cout << "The lowest temperature of the year was " <<yearofweather[index].LowTemp <<
			" degrees in the month ";
	printmonth((month)index);
	cout << "." << endl;
	for(index = 0; index < 12; index++){
		AverageTemp += yearofweather[index].AverageTemp;
	}
	AverageTemp = AverageTemp / 12;
	cout << "The average of all monthly averages is " << AverageTemp << " degrees." << endl;
}
/*********************************************************************************
 * Function definition EnterWeather
 * This function lets the user enter monthly weather data for a year.
 */
void EnterWeather(monthlyweather m[])
{
	int c;

	for(c = 0; c < 12; c++){
		cout << "For the month of ";
		printmonth((month)c);
		cout << endl;
		cout << "Enter monthly rainfall: ";
		cin >> m[c].Rainfall;
		while(m[c].Rainfall < 0.0){
			cout << "Error Try again";
			cin >> m[c].Rainfall;
		}
		cout << "Enter monthly high: ";
		cin >> m[c].HighTemp;
		cout << "Enter monthly low: ";
		cin >> m[c].LowTemp;
		m[c].AverageTemp = (m[c].HighTemp + m[c].LowTemp) / 2.0;
	}
}
/********************************************************************************
 * Function definition Computyearrainfall
 * Computes the years monthly average and total rainfall.
 */
void Computyearrainfall(monthlyweather year[], float &average, float &total)
{
	int month;

	total = 0.0;
	for(month = 0; month < 12; month++){
		total += year[month].Rainfall;
	}
	average = total / 12;

}
/*********************************************************************************
 * Function definition findhighesttemp
 * Finds the highest temperature in a year and returns an index to the
 * month that it happened in.
 */
int findhighesttemp(monthlyweather year[])
{
	int m = JANUARY;
	int temp;
	int itmp;

	temp = year[0].HighTemp;
	itmp = m;
	for(m = 1; m <= DECEMBER; m++){
		if(temp < year[m].HighTemp){
			temp = year[m].HighTemp;
			itmp = m;
		}
	}
	return (itmp);
}
/***************************************************************************
 * Function definition findlowesttemp
 * finds the month with the lowest temperature of the year and returns an
 * an index to that month.
 */
int findlowesttemp(monthlyweather year[])
{
	int m = JANUARY;
	int temp;
	int itmp;

	temp = year[0].HighTemp;
	itmp = m;
	for(m = 1; m <= DECEMBER; m++){
		if(temp > year[m].LowTemp){
			temp = year[m].LowTemp;
			itmp = m;
		}
	}
	return (itmp);
}
/****************************************************************************
 * Function definition printmonth
 * function prints a month on the console depending on m
 */
void printmonth(month m)
{
	switch(m){
		case JANUARY:
			cout << "January";
			break;
		case FEBRUARY:
			cout << "February";
			break;
		case MARCH:
			cout << "March";
			break;
		case APRIL:
			cout << "April";
			break;
		case MAY:
			cout << "May";
			break;
		case JUNE:
			cout << "June";
			break;
		case JULY:
			cout << "June";
			break;
		case AUGUST:
			cout << "August";
			break;
		case SEPTEMBER:
			cout << "September";
			break;
		case OCTOBER:
			cout << "October";
			break;
		case NOVEMBER:
			cout << "November";
			break;
		case DECEMBER:
			cout << "December";
			break;
		default:
			cout << "error no such month";
			break;
	}
}
