// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <limits>
#include <fstream>
using namespace std;




int main() 
{
	string fileName = "ConsoleApplication1.cpp";
	string line;
	fstream inFile;
	inFile.open(fileName.c_str());
	if (inFile.fail())
	{
		cout << "file doesn't exist or wrong name\n";
		exit(1);
	}

	while (getline(inFile, line))
	{
		cout << line << endl;
	}
	inFile.close();



	cout << "Enter key to exit." << endl;
	cin.get();

	return 0;
}