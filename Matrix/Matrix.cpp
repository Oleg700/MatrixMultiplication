
#include "stdafx.h"
#include <iostream>
#include <Locale>
#include <thread>
#include <cstdio>
using namespace std;

int firstMatrix[10][10];
int secondMatrix[10][10];
int resultMatrix[10][10];
int rowNumberFirstMatrix;
int	columnNumberFirstMatrix;
int	rowNumberSecondMatrix;
int	columnNumberSecondMatrix;

void inputInitialValues() {
	cout << "enter number of rows for 1 matrix ";
	cin >> rowNumberFirstMatrix;
	cout << "enter number of columns for 1 matrix ";
	cin >> columnNumberFirstMatrix;
	cout << "enter number of rows for 2 matrix ";
	cin >> rowNumberSecondMatrix;
	cout << "enter number of columns for 2 matrix ";
	cin >> columnNumberSecondMatrix;

	while (columnNumberFirstMatrix != rowNumberSecondMatrix)
	{
		cout << "Error, number of columns 1 matrix is not equal to number of rows 2 matrix";
		cout << "enter number of rows for 1 matrix ";
		cin >> rowNumberFirstMatrix;
		cout << "enter number of columns for 1 matrix ";
		cin >> columnNumberFirstMatrix;
		cout << "enter number of rows for 2 matrix ";
		cin >> rowNumberSecondMatrix;
		cout << "enter number of columns for 2 matrix ";
		cin >> columnNumberSecondMatrix;
	}
}

void fillRandomFirstMatrix() {
	cout << endl << "enter value to 1 matrix:" << endl;
	for (int i = 0; i < rowNumberFirstMatrix; ++i)
		for (int j = 0; j < columnNumberFirstMatrix; ++j)
		{
			firstMatrix[i][j] = rand() % 100 + 1;
		}
}

void printFirstMatrix() {
	cout << endl << "generated first matrix:";
	for (int i = 0; i < rowNumberFirstMatrix; ++i)
	{
		cout << "\n";
		for (int j = 0; j < columnNumberFirstMatrix; ++j)
		{
			cout << firstMatrix[i][j] << " ";
		}
	}
}


void fillRandomSecondMatrix() {
	cout << endl << "enter value to 2 matrix:" << endl;
	for (int i = 0; i < rowNumberSecondMatrix; ++i)
		for (int j = 0; j < columnNumberSecondMatrix; ++j)
		{
			secondMatrix[i][j] = rand() % 100 + 1;
		}
}

void printSecondMatrix() {
	cout << endl << "generated second matrix:";
	for (int i = 0; i < rowNumberSecondMatrix; ++i)
	{
		cout << "\n";
		for (int j = 0; j < columnNumberSecondMatrix; ++j)
		{
			cout << secondMatrix[i][j] << " ";
		}
	}
}

void initThirdMatrix() {
	for (int i = 0; i < rowNumberFirstMatrix; ++i)
		for (int j = 0; j < columnNumberSecondMatrix; ++j)
		{
			resultMatrix[i][j] = 0;
		}
}

void multiplyMatrix(int rowNumber) {
	for (int j = 0; j < columnNumberSecondMatrix; ++j)
		for (int k = 0; k < columnNumberFirstMatrix; ++k)
		{
			resultMatrix[rowNumber][j] += firstMatrix[rowNumber][k] * secondMatrix[k][j];
		}
}

void printResult() {
	cout << endl << "result: " << endl;
	for (int i = 0; i < rowNumberFirstMatrix; ++i)
		for (int j = 0; j < columnNumberSecondMatrix; ++j)
		{
			cout << " " << resultMatrix[i][j];
			if (j == columnNumberSecondMatrix - 1)
				cout << endl;
		}
}

int main()
{
	inputInitialValues();
	fillRandomFirstMatrix();
	fillRandomSecondMatrix();
	initThirdMatrix();

	printFirstMatrix();
	printSecondMatrix();

	for (int i = 0; i < rowNumberFirstMatrix; ++i) {
		thread th(multiplyMatrix, i);
		th.detach();
	}
	printResult();

	getchar();
	system("pause");
	return 0;
}

