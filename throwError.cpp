// ConsoleApplication1.cpp : Defines the entry point for the console application.
//Example of stack from Data Structures & Algorithm, Goodrich.

#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <cmath>
#include <random>
#include <string>
using namespace std;
void throw_exception() 
{
	throw 10;
}
void my_unexpected() {
	std::cout << "well - this was unexpected" << std::endl;
}
int main() 
{
	std::set_unexpected(my_unexpected);
	try {
		throw_exception();
	}
	catch (int x) {
		std::cout << "catch int: " << x << std::endl;
	}
	catch (...) {
		std::cout << "catch ..." << std::endl;
	}

	cout << "Enter key to exit." << endl;
	cin.get();

	return 0;
}
