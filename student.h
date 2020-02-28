#pragma once
#include <string>
#include <iostream>
using namespace std;

class student
{
public:
	static void is_present();
	static void output_attendance(int x);
	static int count();
	static void set_date();
	static void invalid(int vector_start, int iterator);
};