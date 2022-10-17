/*
File Name: BITF19M541-DSALab3
Written By: Naveed Amjad
ID: BITF19M541
Date: March 18,2021
Description: DSA Lab 3 
*/

#include <iostream>
using namespace std;

struct Point
{
	float x, y;
	Point()
	{
		x = 0, y = 0;
	}
	Point(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};
class PointList
{
	Point* arry; //holds an array of points
	int maxSize; //to store maximum number of elements in list
	int curSize; //to hold the current number of the elements in the list
	int cursor; //to hold the current position (index). If the list is empty it should hold -1
public:
	PointList(int maxSize)
	{
		this->maxSize = maxSize;
		arry = new Point[maxSize];
		curSize = 0;
		cursor = -1;
		for (int i = 0; i < maxSize; i++)
			arry[i] = Point();
	}
	bool isEmpty()
	{
		if (curSize == 0)
			return true;
		return false;
	}
	bool isFull()
	{
		if (curSize == maxSize)
			return true;
		return false;
	}
	void insert(Point newPoint)
	{
		if (isEmpty())
		{
			arry[0] = newPoint;
			curSize = 1;
			cursor = 0;
		}
		else
			if (!isEmpty())
			{
				if (isFull())
				{
					cout << "List if full. Increase maxSize to insert objects more than " <<curSize<< endl;
					return;
				}
				arry[curSize] = newPoint;
				curSize++;
				cursor = curSize - 1;
			}
	}
	void showStructure()
	{
		if(isEmpty())
		{
			cursor = -1;
			cout << "Empty List."<<endl;
			cout << "Cursor = " << cursor << endl;
			return;
		}
		else
		{
			cout << "Maximum Size = " << maxSize << endl;
			cout << "Current Size = " << curSize << endl;
			cout << "Cursor = " << cursor << endl;
			cout << "List: ";
			for (int i = 0; i < curSize; i++)
				cout << "(" << arry[i].x << "," << arry[i].y << ")" <<" ";
		}
	}
	Point getCursor()
	{
		return arry[cursor];
	}
	void gotoBeginning()
	{
		if (!isEmpty())
			cursor = 0;
	}
	void gotoEnd()
	{
		if (!isEmpty())
			cursor = maxSize - 1;
	}
	bool gotoNext()
	{
		if (cursor != maxSize)
		{
			cursor++;
			return true;
		}
		return false;
	}
	bool gotoPrior()
	{
		if (cursor != 0)
		{
			cursor--;
			return true;
		}
		return false;
	}
	void clear()
	{
		curSize = 0;
		cursor = -1;
	}
	void replace(Point newPoint)
	{
		arry[cursor] = newPoint;
	}
	void remove()
	{
		arry[cursor] = Point();
		cursor--;
		if (!isEmpty())
			cursor++;
		else if (cursor == curSize - 1)
			cursor = 0;
	}
	~PointList()
	{
		delete arry;
	}

};

