#ifndef Student_H
#define Student_H
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Student
{
	private: 
		string name;
		int age;
		bool gender;
		int id;

	public:
		Student ();
		Student (string name, int age, bool gender, int id);
		string get_name();
		int get_age();
		bool get_gender();
		int get_id();
};
#endif 
