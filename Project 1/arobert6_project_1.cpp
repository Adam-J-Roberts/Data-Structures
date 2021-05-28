#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"

using namespace std;

void print_menu();
void get_selection(Student* &student, int (&student_count), int (&student_size));
void input_new_student(Student* &student, int (&student_count), int (&student_size));
void resize_array(Student* &original, int count, int (&size));
int assign_id(Student* &student, int (&student_count), int (&student_size));
void show_array(int student_count, int student_size);
void delete_student(Student* &student, int (&student_count), int (&student_size));

int main()
{
	int student_size = 3;
	int student_count = 0;
	Student* student = new Student[student_size];

	get_selection(student, student_count, student_size);

	return 0;

}
void print_menu() 
{
	cout << endl << endl << endl << "Welcome to Gladys's Only-Kill Animal... Errr, Student Records!" << endl;
	cout << "Sorry, that was my old job" << endl;
	cout << "We can regester and withdraw your student here." << endl;
	cout << "What woukd you like to do today?" << endl;
	cout << "1.  Add" << endl;
	cout << "2.  Delete." << endl;
	cout << "3.  Report." << endl;
	cout << "4.  Exit" << endl;
}
void get_selection(Student* &student, int (&student_count), int (&student_size))
{
	int choice;
	do{
		print_menu(); 
		do {
			cout << "Please select one. : ";
			cin >> choice;
		} while (choice > 0 && choice > 4);
		
		if (choice == 1)
		{
			input_new_student(student, student_count, student_size);
		}
		else if (choice == 2)
		{
			delete_student(student, student_count, student_size);
		}
		else if (choice == 3)
		{
			show_array(student_count, student_size);
		}
	}while (choice != 4);		
}
void input_new_student(Student* &student, int (&student_count), int (&student_size))
{
	bool gender1;
	string name1;
	int id1;
	int age1;
	
	cout << "What is the students name? : ";
	cin.ignore();
	getline(cin, name1);
	
	cout << "Is " << name1 << " a 1)male or 0)female?";
	cin >> gender1;
	
	cout << "How old is "<< name1 << " ? : ";
	cin >> age1;

	id1 = assign_id(student, student_count, student_size);

	cout << "=================================" << endl;
	cout << name1 << "'s new id number is " << id1 << "." << endl;  
	cout << "=================================" << endl;
	
	Student d(name1, age1, gender1, id1);
	student[student_count] = d;
	++student_count;
	resize_array(student, student_count, student_size);
}
void resize_array(Student* &original, int count, int (&size))
{
	float div =  1.0 * count/size;
	int percentage = div*100;
	
	if (percentage < 50 && size > 3|| percentage > 75 && size > 2)
	{
		size = ((count*100)/65);
		Student* resized = new Student[size];
		for (int i = 0; i < count; i++)
			resized[i] = original[i];
		delete[] original;
		original = resized;
	}
}
int assign_id(Student* &student, int (&student_count), int (&student_size)) 
{
	int id;
	int count;

	srand(time(NULL));
	
		do {
			id = rand()%1000000000;
			for (int i = 0; i < student_count; i++)
			{
				if (id == student[i].get_id())
				{
					id = 0;
					break;
				}
			}
		}while (id == 0);

	return id;
}
void show_array(int student_count, int student_size)
{

	float div =  1.0 * student_count/student_size;
	int percentage = div*100;
	
	cout << "Your array is hard coded at " << percentage << "%." << endl;
}	
void delete_student(Student* &student, int (&student_count), int (&student_size))
{
	int i = 0;
	string to_be_deleted;
	char choice;
	int stop;

	cout << endl << endl << "                                      Students" << endl;
	cout << "================================================================================" << endl;
	cout << "ID";
	cout << setfill(' ') << setw(15) << " ";
	cout << "Name" << endl;
	cout << "================================================================================" << endl;

	if (student_count > 0)
	{
		do {
			cout << student[i].get_id();
			cout << setfill(' ') << setw(8) << " ";
			cout << student[i].get_name() << endl;
			++i;
		} while (i < student_count);
	}
	
	i = 0;

	cout << endl << "What student is dropping out? ";
	cin.ignore();
	getline(cin, to_be_deleted);
	
	do{
		if(i > student_count)
		{
			cout << "Sorry, it appears the student you are looking for does not exist." << endl;
			stop = 1;
		}
		else if (student[i].get_name() != to_be_deleted)
		{
			++i;
		}
		else if (student[i].get_name() == to_be_deleted)
		{
			cout << "Does your " << student[i].get_name()  << " have an id # of " << student[i].get_id()  << " ? Y/N :";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				--student_count;
				student[i] = student[student_count]; 

				cout << to_be_deleted << " has been deleted!" << endl;
				stop = 1;
			}
			else
			{
				++i;
			}
		}
		
	}while (stop != 1);
	resize_array(student, student_count, student_size);
}
