/*
FileName: BITF19M541.cpp
Written By: Naveed Amjad
ID: BITF19M541
Description: DSA Lab1
Date: March 3,2021
*/
#include <iostream>
using namespace std;

class collection 
{
	int* data;
	int size;
public:
	collection(int size)
	{
		this->size = size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}
	collection(int size, int* arry)
	{
		this->size = size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arry[i];
		}
	}

	collection(const collection& obj)
	{
		this->size = obj.size;
		this->data = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = obj.data[i];
		}
	}
	int getSize()
	{
		return size;
	}
	int setElement(int k, int i)
	{
		if (i >= 0 && i < size)
			data[i] = k;
		else
			cout << "Invalid index.";
	}
	int countElement(int key)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (data[i] == key)
				count++;
		}
		if (count == 0)
			return count - 1;
		return count;
	}
	void operator=(collection obj)
	{
		if (size == obj.size)
		{
			for (int i = 0; i < size; i++)
				data[i] = obj.data[i];
		}
		else
			cout << "Sizes are not equal.";
	}
	collection operator+(collection& obj)
	{
		collection addition(size);
		if (size == obj.size)
		{
			for (int i = 0; i < size; i++)
				addition.data[i] = data[i] + obj.data[i];
			return addition;
		}
		cout << "Addition is not possible because sizes are not equal.";
		return addition;
	}
	bool operator==(collection obj)
	{
		if (size != obj.size)
			return false;
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] != obj.data[i])
					return false;
			}
		}
		return true;
	}
	friend ostream& operator<<(ostream& out, collection obj);
	friend istream& operator>>(istream& in, collection& obj);
};
ostream& operator<<(ostream& insert, collection obj)
{
	insert << "Size: " << obj.size << endl;
	insert << "Array: " << endl;
	for (int i = 0; i < obj.size; i++)
	{
		insert << obj.data[i];
		insert << " ";
	}
	insert << endl;
	return insert;
}
istream& operator>>(istream& extract, collection& obj)
{
	cout << "Enter Data\n\n";
	for (int i = 0; i < obj.size; i++)
	{
		extract >> obj.data[i];

	}
	return extract;
}
