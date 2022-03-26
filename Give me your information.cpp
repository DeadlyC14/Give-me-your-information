#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	// THe variables
	string name;
	string lastName;

	string birthDay;
	string birthMonth;
	string birthYear;

	string fullName;
	string fullBirthDate;

	//The questioning
	cout << "Please tell me your first name: ";
	cin >> name;

	cout << "Now your last name: ";
	cin >> lastName;

	cout << "What is your birth date? (day number): ";
	cin >> birthDay;

	cout << "Birth Month: ";
	cin >> birthMonth;

	cout << "Birth Year: ";
	cin >> birthYear;
	
	// converting the information inputted to easily accessible variables
	fullName = name + " " + lastName;
	fullBirthDate = birthMonth + "/" + birthDay + "/" + birthYear;

	// creation of the file
	ofstream pInformation("Personal Information.txt", ios::out);

	// if the file is open it shall paste in the information
	if (pInformation.is_open()) {
		pInformation << fullName << "\n";
		pInformation << fullBirthDate << "\n";
	}
	
	// closes the file
	pInformation.close();
}
