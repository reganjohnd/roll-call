#include "student.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> v_id;
vector<string> v_name;
string date;
string present;
int c{};

int student::count()
{
	string line;
	ifstream input;
	input.open("C:/Users/Roger/Documents/students.txt");

	int count{};
	while (input)
	{
		getline(input, line);
		count++;
	}

	input.close();
	count--;
	return count;
}
void student::set_date()
{
	cin.ignore();
	system("CLS");
	cout << "Date: ";
	getline(cin, date);
	cout << endl;
}

void student::is_present()
{
	string s_id{};
	int i_id{};
	string s_name{};

	ifstream input;
	input.open("C:/Users/Roger/Documents/students.txt");

	if (!input)
		cout << "error!";
	
	for (int i = 0; i < count(); i++)
	{
		getline(input, s_id, ',');
		getline(input, s_name, '\n');
		i_id = atoi(s_id.c_str());
		v_id.push_back(i_id);
		v_name.push_back(s_name);
	}
	input.close();
}

void student::output_attendance(int x)
{
	ofstream output;
	output.open("C:/Users/Roger/Desktop/attendance.txt", ios::app);

	for (int i = x; i < count(); i++)
	{			
			cout << v_name[i] << ": ";
			getline(cin, present);
			if (present == "A" || present == "a" || present == "H" || present == "h")
			{
				output << date << ",";
				output << v_name[i] << "," << present << endl;
				c = c + 1;
			}
			else if(present != "A" || present != "a" || present != "H" || present != "h")
			{
				cout << "Please enter a valid input!"<< endl << endl;
				output.close();
				invalid(c, count());
				break;
			}
	}
}

void student::invalid(int vector_start, int iterator)
{
	ofstream output;
	output.open("C:/Users/Roger/Desktop/attendance.txt", ios::app);
	for (static int i = vector_start; i < iterator; i++)
	{
		cout << v_name[i] << ": ";
		getline(cin, present);
		if (present == "A" || present == "a" || present == "H" || present == "h")
		{
			output << date << "," << v_name[i] << "," << present << endl;
			c = c + 1;
		}
		else if (present != "A" || present != "a" || present != "H" || present != "h")
		{
			cout << "Please enter a valid input!" << endl << endl;
			output.close();
			invalid(c, count());
		}
	}
}

void student::add_student()
{
	system("CLS");
	ofstream output;
	string name;
	int id{};

	cin.ignore();
	cout << "Name: ";
	getline(cin, name);
	cout << "Student ID: ";
	cin >> id;

	output.open("C:/Users/Roger/Documents/students.txt", ios::app);
	output << id << "," << name;
	output.close();
}

void student::delete_student()
{
	system("CLS");

	ifstream input;
	input.open("C:/Users/Roger/Documents/students.txt");
	ofstream output;
	output.open("C:/Users/Roger/Documents/temp.txt");

	string sd_id, temp_n, temp_id;
	int id_id{};

	cout << "Please enter Student ID: ";
	cin.ignore();
	getline(cin, sd_id);

for (int i = 0; i < student::count(); i++)
	{
		getline(input, temp_id, ',');
		getline(input, temp_n, '\n');

		if (sd_id != temp_id)
		{
			output << temp_id << "," << temp_n << endl;
		}
	}
	input.close();
	output.close();
	remove("C:/Users/Roger/Documents/students.txt");
	int result;
	result = rename("C:/Users/Roger/Documents/temp.txt", "C:/Users/Roger/Documents/students.txt");
}

void student::view_students()
{
	system("CLS");
	ifstream input;
	input.open("C:/Users/Roger/Documents/students.txt");

	string name, id;
	cout << "ID\t\t\tName" << endl;
	for (int i = 0; i < student::count(); i++)
	{
		getline(input, id, ',');
		getline(input, name, '\n');

		cout << id << "\t\t\t" << name << endl;
	}
	system("pause");
	input.close();
}