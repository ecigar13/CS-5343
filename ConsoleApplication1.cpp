// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <cmath>
#include <random>
using namespace std;

class MatrixManipulation
{
public:
	MatrixManipulation(int i, int j);
	void swapCol(int curRow, int curCol);
	void transpose(int curRow, int curCol);
	void setVal(int curRow, int curCol, int curVal);
	void printMatrix();
private:
	int row;
	int col;
	int** matrix;
};

void MatrixManipulation::printMatrix() {
	for (int i(0); i < row; i++)
	{
		for (int j(0); j < col; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
void MatrixManipulation::setVal(int curRow, int curCol,int curVal)
{
	matrix[curRow][curCol] = curVal;
}
MatrixManipulation::MatrixManipulation(int i, int j)
{
	row = i;
	col = j;
	matrix = new int*[row];
	for (int k = 0; k < col; k++)
	{
		matrix[k] = new int[col];
	}

}

void MatrixManipulation::swapCol(int curRow, int curCol)
{
	if (curRow == curCol)
		return;

	int temp = matrix[curRow][curCol];
	matrix[curRow][curCol] = matrix[curCol][curRow];
	matrix[curCol][curRow] = temp;
	swapCol(curRow, curCol + 1);
}

void MatrixManipulation::transpose(int curRow, int curCol)
{
	if (curRow>row-1)
		return;
	
	
	swapCol(curRow, curCol);
	transpose(curRow + 1, curCol);

}

int main() 
{
	int size(5);
	MatrixManipulation test(size,size);
	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			test.setVal(i, j, rand());
		}	
	}
	test.printMatrix();
	test.transpose(0, 0);
	cout << endl<<"After transposition:\n";

	test.printMatrix();
	cout << "Enter key to exit." << endl;
	cin.get();

	return 0;
}