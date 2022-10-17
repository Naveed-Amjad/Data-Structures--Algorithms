#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
	// Task 1 => to write data to a file named student.txt
	int Roll_no, marks;
	string fname, lname;
	fstream EnterStudentRecord;
	EnterStudentRecord.open("student.txt");
	do
	{
		cout << "Please Enter Roll Number of Student:";
		cin >> Roll_no;
		if (Roll_no != -999)
		{
			cout << "Enter student First name Last name and marks(follow same order. Press -999 to quit) ";
			cin >> fname >> lname >> marks;
			EnterStudentRecord << Roll_no << "   " << fname << " " << lname << "   " << marks << endl;
		}
	} while (Roll_no != -999);

	EnterStudentRecord.close();

	// Task 2 => to det data from student.txt file created in task1

	fstream getStudentRecord;
	getStudentRecord.open("student.txt");
	if (!getStudentRecord.is_open())
	{
		cout << "Unable to open file.";
	}
	else
		cout << "Roll No." << "   " << "Name" << "      " << "Marks" << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
	while (getStudentRecord >> Roll_no >> fname >> lname >> marks)
	{
		cout << Roll_no << " " << fname << " " << lname << " " << marks << endl;
	}

	getStudentRecord.close();

	// Task 3 => to get marks of quizes from given file input.txt and display highest marks

	fstream inputFile;
	int quiz1, quiz2, quiz3, quiz4, quiz5, quiz6, quiz7, quiz8, quiz9, quiz10, highestScore = 0;
	inputFile.open("input.txt");
	if (!inputFile.is_open())
		cout << "File not open." << endl;
	else
		while (inputFile >> Roll_no >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> quiz5 >> quiz6 >> quiz7 >> quiz8 >> quiz9 >> quiz10)
		{
			int arr[10] = { quiz1,quiz2,quiz3,quiz4,quiz5,quiz6,quiz7,quiz8,quiz9,quiz10 };
			for (int i = 0; i < 10; i++)
			{
				if (arr[i] > highestScore)
				{
					highestScore = arr[i];
				}
			}
			cout << Roll_no << " " << highestScore << endl;
			highestScore = 0;
		}
	inputFile.close();

	// Task 4 => to get two highest scores

	ofstream outputFile;
	int highscore1 = 0, highscore2 = 0;
	outputFile.open("output.txt");
	if (!outputFile.is_open())
	{
		cout << "File not open." << endl;
	}
	else
		inputFile.open("input.txt");
	if (!inputFile.is_open())
	{
		cout << "File not open." << endl;
	}
	else
	{
		while (inputFile >> Roll_no >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> quiz5 >> quiz6 >> quiz7 >> quiz8 >> quiz9 >> quiz10)
		{
			int arr[10] = { quiz1,quiz2,quiz3,quiz4,quiz5,quiz6,quiz7,quiz8,quiz9,quiz10 };
			for (int i = 0; i < 10; i++)
			{
				if (arr[i] > highscore1)
				{
					highscore1 = arr[i];
				}
			}
			outputFile << Roll_no << " " << highscore1;
			for (int i = 0; i < 10; i++)
			{
				if (arr[i] > highscore2 && arr[i] < highscore1)
				{
					highscore2 = arr[i];
				}
			}
			outputFile << " " << highscore2 << endl;
			cout << Roll_no << " " << highscore1 << " " << highscore2 << endl;


		}
	}
}
