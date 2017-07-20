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

class Progression {
	virtual long nextValue() = 0;

};

class SqrtProgression:public Progression {
public:
	SqrtProgression(double a)
	{
		firstVal = a;
	}
	long nextValue()
	{
		firstVal *= firstVal;
		return firstVal;
	}
	void printVal() {
		printf("First value: %f \n", firstVal);

	}

private:
	long double firstVal = 65536.0;
};


int main() 
{
	SqrtProgression* test = new SqrtProgression(2.0);
	test->nextValue();
	test->printVal();
	cout << "Enter key to exit." << endl;
	cin.get();

	return 0;
}