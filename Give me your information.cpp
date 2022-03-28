#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	// The input variables
	string name;
	string lastName;

	string birthDay;
	string birthMonth;
	string birthYear;

	// The input conversion variables
	string fullName;
	string fullBirthDate;

	// The variables that will hold the text from the text file
	string line1;
	string line2;
	
	//simple counter to check which line the code is at
	int counter = 0;

	// initializes fstream
	fstream pInformation;
	
	// checks if the file exists or not
	pInformation.open("Personal Information.txt", ios::in);

	if (pInformation.is_open()) {

		// if the file is found it will paste the name and the birth date to the variables line1 and line 2
		string currentLine;
		while (getline(pInformation, currentLine)) {
			counter++;

			if (counter == 1) {
				line1 = currentLine;
			}
			else {
				line2 = currentLine;
			}
		}

		// Just a greeting
		cout << "Welcome " << line1 << endl;
		cout << "A file already exists, do you wish to overwrite it(O), append(A) or quit(Q)?" << endl;

		string oaq;

		// unfinished code for now
		while (true) {

			cin >> oaq;

			if (oaq == "O") {
				break;
			}
			else if (oaq == "A") {
				break;
			}
			else if (oaq == "Q") {
				exit(0);
			}
			else {
				cout << "Please enter a valid option: ";
			}
		}
	}

	// If the program is opened for the first time this code gets executed
	else {
		cout << "Do you wish to create a txt file containing some basic personal information? Y/N" << endl;

		string createFileOption;

		// If Y a file gets created and the rest of the code is executed
		// If N the program quits
		while (true) {
			cin >> createFileOption;

			if (createFileOption == "Y") {
				break;
			}
			else if (createFileOption == "N") {
				exit(0); 
			}
			else {
				cout << "Please enter a valid option: ";
			}
		}
	}

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
	pInformation.open("Personal Information.txt", ios::out);

	// if the file is open it shall paste in the information
	if (pInformation.is_open()) {
		pInformation << fullName << "\n";
		pInformation << fullBirthDate << "\n";
	}
	else {
		cout << "File opening failed" << endl;
	}
	
	// closes the file
	pInformation.close();
}
