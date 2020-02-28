#include "student.h"

#include <string>
#include<vector>
#include<iostream>
#include <fstream>

using namespace std;

int main()
{
	student::set_date();
	student::is_present();
	student::output_attendance(0);
}

//counter in output_ATTENDANCE FUNCTION WHICH KEEPS TRACK OF WHERE TO START
//INVALID function starts at the counter for a new
//INVALID function takes to parameters: value of i and size of iterator
//value of i comes from counter in output_attendance function 
//value of iterator comes from number of students - i - 1(to account for the binary offset)