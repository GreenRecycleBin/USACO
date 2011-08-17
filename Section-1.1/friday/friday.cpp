/*
ID: ldkn_291
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}	

int daysInMonth(int month, int year)
{
	if (month == 1) {
		return daysInMonths[month] + isLeap(year);
	}
	else {
		return daysInMonths[month];
	}
}

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	
	int datesOfWeek[7] = {0}; // Saturday is at index 0
	
	int n;
	fin >> n;
	
	int dateOfWeek = 0; // January 13, 1900 was a Saturday
	for (int i = 1900; i < 1900 + n; i++) {
		for (int j = 0; j < 12; j++) {
			datesOfWeek[dateOfWeek]++;
			dateOfWeek = (dateOfWeek + daysInMonth(j, i)) % 7;
		}
	}
	
	for (int i = 0; i < 7; i++) {
		if (i) {
			fout << " ";
		}
		
		fout << datesOfWeek[i];
	}
	
	fout << "\n";
	
	return 0;
}