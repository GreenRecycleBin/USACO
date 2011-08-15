/*
ID: ldkn_291
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int valueOfChar(char c)
{
	return c - 'A' + 1;
}
int main()
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	string comet, group;
	fin >> comet >> group;

	int valueOfComet = 1, valueOfGroup = 1;
	for (int i = 0; i < comet.length(); i++) {
		valueOfComet *= valueOfChar(comet[i]);
	}

	for (int i = 0; i < group.length(); i++) {
		valueOfGroup *= valueOfChar(group[i]);
	}

	if (valueOfComet % 47 == valueOfGroup % 47) {
		fout << "GO" << endl;
	}
	else {
		fout << "STAY" << endl;
	}

	return 0;
}
