/*
File Name: BITF19M541-Lab4.cpp
Written By: Naveed Amjad
ID: BITF19M541
Date: 25 March,2021
Description: Lab4
*/

#include <iostream>
using namespace std;

class Matrix
{
	int* matrix;
	int row;
	int col;
public:
	
	Matrix(int row,int col)
	{
		this->row = row;
		this->col = col;
		matrix = new int[row * col];
		for (int i = 0; i < row * col; i++)
		{
			matrix[i] = 0;
		}
	}
	int get(int i, int j)
	{
		if (i >= row || j >= col)
		{
			cout << "Error! Value of i,j should be less than row and col" << endl;
		}
		int getValue = matrix[(i * col) + j];
		return getValue;
	}
	void set(int i, int j, int v)
	{
		if (i >= row || j >= col)
		{
			cout << "Error! Value of i,j should be less than row and col" << endl;
			return;
		}
		matrix[(i * col) + j] = v;
		return;
	}
	void print()
	{
		int index = col - 1; //it will store the ending index of coloumn in single dimension array
		for (int i = 0; i < row * col; i++)
		{
			cout << matrix[i]<<" ";
			if (i == index)
			{
				cout << endl;
				index = col + index;
			}
		}
	}
	void transpose()
	{
		int* transpose;
		transpose = new int[col * row];
		for (int i = 0; i < row * col; i++)
		{
			transpose[i] = matrix[i];
		}
		int t = row;
		row = col;
		col = t;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{

				matrix[(i * col) + j] = transpose[(j * row) + i];

			}
		}
	}
	void printSubMatrix(int r1, int r2, int c1, int c2)
	{
		for (int i = r1; i <= r2; i++)
		{
			for (int j = c1; j <= c2; j++)
			{
				cout << matrix[(i * col) + j]<<" ";
			}
			cout << endl;
		}
	}
	void makeEmpty(int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[(i * col) + j] = 0;
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[(i * col) + j] = 0;
			}
		}
	}
	void subtract(Matrix first, Matrix second)
	{
		if (first.row != second.row || first.col != second.col)
		{
			cout << "Error! To subtract order of 1st and 2nd matrix should be equal.";
			return;
		}
		for (int i = 0; i < row * col; i++)
		{
			matrix[i] = first.matrix[i] - second.matrix[i];
		}
	}
	~Matrix()
	{
		delete[]matrix;
	}
};

int main()
{
   
}
