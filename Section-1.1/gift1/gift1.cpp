/*
ID: ldkn_291
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	
	vector<string> giverNames;
	vector<string>::iterator it;
	map<string, pair<int, int> > givers;
	
	int numGivers;
	fin >> numGivers;
	
	string name;
	for (int i = 0; i < numGivers; i++) {
		fin >> name;
		giverNames.push_back(name);
		givers[name] = pair<int, int>(0, 0);
	}
	
	for (int i = 0; i < numGivers; i++) {
		fin >> name;
		int initial, toBeGiven, numRecipient;
		fin >> initial >> numRecipient;
		
		givers[name].first = initial;
		
		if (numRecipient != 0) {
 			toBeGiven = initial / numRecipient;
			givers[name].second += initial % numRecipient;
		}
		
		for (int j = 0; j < numRecipient; j++) {
			fin >> name;
			givers[name].second += toBeGiven;
		}
	}
	
	for (it = giverNames.begin(); it != giverNames.end(); it++) {
		fout << *it << " " << givers[*it].second - givers[*it].first << endl;
	}
	
	return 0;
}