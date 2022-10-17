/*
File Name: BITF19M541.cpp
Written By: Naveed Amjad
ID: BITF19M541
Date: 31 March 2021
Description: Lab 5
*/

#include <iostream>
#include <string>
using namespace std;


template <class T>
class Stack
{
	T* data;
	int top;
	const int MAX_SIZE;
public:
	Stack(int MAX_SIZE):MAX_SIZE(MAX_SIZE)
	{
		data = new T[MAX_SIZE];
		top = -1;
	}
	void push(T newItem)
	{
		if (isFull())
			return;
		top = top + 1;
		data[top] = newItem;
	}
	T pop()
	{
		if (isEmpty())
		{
			return 0;
		}
		T topValue = data[top];
		top--;
		return topValue;
	}
	T Top() //
	{
		if (top == -1)
		{
			cout << "Stack is Empty." << endl;
			return 0;
		}
		return data[top];

	}
	void clear()
	{
		top = -1;
		cout << "Stack has been cleared successfully." << endl;
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			cout << "Stack is Empty." << endl;
			return true;
		}
		return false;
	}
	bool isFull()
	{
		if (top == MAX_SIZE - 1)
		{
			cout << "Stack is Full."<<endl;
			return true;
		}
		return false;
	}
	void showStructure() const
	{
		cout << "Top --> ";
		for (int i = top; i >=0; i--)
		{
			cout << data[i] << endl;
		}
		cout << endl;
	}
	~Stack()
	{
		delete []data;
	}
};
int main()
{
	//Testing

	//Stack<string> obj(4);
    //obj.push("Naveed");
	//obj.push("Amjad");
	//obj.push("BITF19M541");
	//obj.pop();
	//obj.isFull();
	//obj.clear();
	//obj.isEmpty();
	//obj.push("abc");
	//string m=obj.Top();
	//cout << m;
	//obj.pop();
	//obj.pop();
	//obj.showStructure();
	//cout << endl;

	//Stack<int> ob(4);
	//ob.isEmpty();
	//ob.push(1);
	//ob.push(2);
	//ob.push(3);
	//ob.pop();
	
	//ob.showStructure();


}