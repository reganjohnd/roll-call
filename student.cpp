#include "student.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> v_id;
vector<string> v_name;
string date;
string present, holder;
int c{};

int student::count()
{
	string line;
	ifstream input;
	input.open("C:/Users/Roger/Documents/students.txt");

	int count{};
	while (input)
		getline(input, line);
		count++;

	input.close();
	count--;
	return count;
}
void student::set_date()
{
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
