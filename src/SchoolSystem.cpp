#include "SchoolSystem.h"
#include <conio.h>
using namespace std;

void SchoolSystem::Run()
{
	InitData();  //FÖr att skapa lite ingående elever
	int input;

	while (true)
	{
		cout << "\033[2J\033[1;1H";

		cout << "::School System::\n\n";

		cout << "1.) Add New Student\n";
		cout << "2.) Add New Class\n";
		cout << "3.) Remove Student\n";
		cout << "4.) Check Student info\n";
		cout << "0.) Exit\n";
		cout << "\n";

		cin >> input;

		switch (input)
		{
		case 1:
			AddStudent();
			break;
		case 2:
			AddClass();
			break;
		case 3:
			RemoveStudent();
			break;
		case 4:
			CheckStudent();
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
}

void SchoolSystem::AddStudent()             //skapar helt nya elever och sätter dem in i en klass som finns 
{
	Student student;

	string temp;

	cout << "Enter Students Name: ";
	cin >> student.name;

	cout << "Enter Age: ";
	cin >> student.age;

	cout << "Enter Class: ";
	cin >> temp;// student.klass;
	if (std::find(schoolClasses.begin(), schoolClasses.end(), temp) != schoolClasses.end())
	{
		student.klass = temp;
		students.push_back(student);
		cout << "Student Created!\n";
	}
	else
	{
		cout << "Class Not Available - Student Register Not Created!\n";
	}
	
	_getch();
}

void SchoolSystem::AddClass()          //Lägger till nya klasser
{
	string temp;
	cout << "Enter Class name: ";
	cin >> temp;
	schoolClasses.push_back(temp);
	cout << "Class : " << temp << " added!";

}

void SchoolSystem::RemoveStudent()         // Tar bort elever överhuvudtaget (Eller från klasser(?))
{
	string name;
	int i=0;
	cout << "Enter Student Name to Delete: ";
	cin >> name;

	bool found = false;
	// Iterate over all elements in Vector
	for (auto& elev : students)
	{
		if (elev.name == name)
		{
			students.erase(students.begin()+i);
			found = true;
			
			break;
		}
		i++;
	}
	if(found)
		cout << "Student : " << name << " Removed!";
	else
		cout << "Student : " << name << " not found!";
	_getch();
}

void SchoolSystem::CheckStudent()         // kollar om elever finns och vilka klasser de tillhör
{
	string name;
	cout << "Enter Student Name to Check: ";
	cin >> name;

	bool found = false;
	// Iterate over all elements in Vector
	for (auto & elev : students)
	{
		if (elev.name == name)
		{
			cout << "Student Found!" << endl;
			cout << "Name: " << elev.name << endl;
			cout << "Age: " << elev.age << endl;
			cout << "Class: " << elev.klass << endl;

			found = true;
			break;
		}
	}
	if (!found)
		cout << "Student Not Found" << endl;

	_getch();
}

void SchoolSystem::InitData()  // Skapa lite grunddata att leka med
{
	Student student;

	schoolClasses.push_back("TE21");
	schoolClasses.push_back("TE22");
	schoolClasses.push_back("TE23");

	student.name = "Adam";
	student.age = 17;
	student.klass = "TE21";

	students.push_back(student);

	student.name = "Bertil";
	student.age = 18;
	student.klass = "TE21";

	students.push_back(student);

	student.name = "Caesar";
	student.age = 19;
	student.klass = "TE22";

	students.push_back(student);

	student.name = "David";
	student.age = 17;
	student.klass = "TE22";

	students.push_back(student);

	student.name = "Erik";
	student.age = 18;
	student.klass = "TE23";

	students.push_back(student);

	student.name = "Filip";
	student.age = 19;
	student.klass = "TE23";

	students.push_back(student);
}



