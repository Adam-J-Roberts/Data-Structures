#include "Student.h"

Student::Student(){}
Student::Student (string name, int age, bool gender, int id)
{
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->id = id;
}
string Student::get_name() 
{
	return name;
}
int Student::get_age()
{
	return age;
}
bool Student::get_gender()
{
	return gender;
}
int Student::get_id()
{
	return id;
}
