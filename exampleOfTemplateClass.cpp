// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <limits>
using namespace std;


template <class T, class U> class Pair
{
public:
	Pair(T val1, U val2)
	{
		a = val1;
		b = val2;
	}

	void printVal()
	{
		cout << a << endl;
		cout << b << endl;
	}
private:

	T a;
	U b;
};




int main() 
{
	Pair<int, double> test(2, 3.0);
	test.printVal();
	cout << "Enter key to exit." << endl;
	cin.get();

	return 0;
}
