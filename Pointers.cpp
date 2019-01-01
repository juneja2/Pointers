#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

struct studentInfo {
	string firstName;
	string lastName;
	double gpa;
	unsigned id;
	string email;
};
const int arraySize = 10;

int readingFile(studentInfo student[], studentInfo * ptr[], int sizeOfArray);
void sort(studentInfo * ptr[], int sizeOfArray, int choice);
void printUnsorted(studentInfo student[], int sizeOfArray);
void printSorted(studentInfo * ptr[], int sizeOfArray, int choice);

int main(){
	int option;
	studentInfo student[arraySize];
	studentInfo * ptr[arraySize];
	cout << left;
	int actualArraySize = readingFile(student, ptr, arraySize);
	do {
		cout << "1. Print records unsorted\n"
				"2. Sort by various fields\n"
				"3. Quit the program ";
		cin >> option;
		switch (option) {
		case 1:
			printUnsorted(student, actualArraySize);
			break;
		case 2:
			cout << "What do you wanna sort by\n"
				"1. FirstName\n2. LastName\n3. GPA\n"
				"4. Id\n5. Email\n";
			int sortChoice;
			cin >> sortChoice;
			sort(ptr, actualArraySize, sortChoice);
			printSorted(ptr, actualArraySize, sortChoice);
			break;
		case 3:
			cout << "Quitting\n";
			break;
		default:
			cout << "Invalid option\n";
		}
	}while (option != 3);
    return 0;
}
int readingFile(studentInfo student[], studentInfo * ptr[], int sizeOfArray) {
	string fileName;
	cout << "What file you want to open ";
	cin >> fileName;
	ifstream inFile;
	inFile.open(fileName.c_str());
	if (!inFile) {
		cout << "Error while opening the file\n";
		exit(EXIT_FAILURE);
	}
	else cout << "File opened successfully\n";
	int i = 0;
	for (; i < sizeOfArray && !inFile.eof(); i++) {
		inFile >> student[i].firstName >> student[i].lastName >> student[i].gpa
			>> student[i].id >> student[i].email;
		ptr[i] = &student[i];
	}
	return i;
}
void sort(studentInfo * ptr[], int sizeOfArray, int choice) {
	for(int i = 0; i < sizeOfArray - 1; i++)
		for (int j = i + 1; j < sizeOfArray; j++) {
			switch (choice) {
			case 1:
				if (ptr[i]->firstName > ptr[j]->firstName) {
					studentInfo * temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
				break;
			case 2:
				if (ptr[i]->lastName > ptr[j]->lastName) {
					studentInfo * temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
				break;
			case 3:
				if (ptr[i]->gpa > ptr[j]->gpa) {
					studentInfo * temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
				break;
			case 4:
				if (ptr[i]->id > ptr[j]->id) {
					studentInfo * temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
				break;
			case 5:
				if (ptr[i]->email > ptr[j]->email) {
					studentInfo * temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
				break;
			default :
				cout << "Invalid sort choice\n";
			}
		}
}
void printUnsorted(studentInfo student[], int sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++)
		cout << setw(15) << student[i].firstName << setw(15) << student[i].lastName << setw(6) << student[i].gpa
		<< setw(14) << student[i].id << setw(20) << student[i].email << endl;
}
void printSorted(studentInfo * ptr[], int sizeOfArray, int choice) {
	switch (choice) {
	case 1:
		for (int i = 0; i < sizeOfArray; i++)
			cout << setw(15) << ptr[i]->firstName << setw(15) << ptr[i]->lastName << setw(6) << ptr[i]->gpa
			<< setw(14) << ptr[i]->id << setw(20) << ptr[i]->email << endl;
		break;
	case 2:
		for (int i = 0; i < sizeOfArray; i++)
			cout << setw(15) << ptr[i]->lastName << setw(15) << ptr[i]->firstName << setw(6) << ptr[i]->gpa
			<< setw(14) << ptr[i]->id << setw(20) << ptr[i]->email << endl;
		break;
	case 3:
		for (int i = 0; i < sizeOfArray; i++)
			cout << setw(6) << ptr[i]->gpa << setw(15) << ptr[i]->firstName << setw(15) << ptr[i]->lastName
			<< setw(14) << ptr[i]->id << setw(20) << ptr[i]->email << endl;
		break;
	case 4:
		for (int i = 0; i < sizeOfArray; i++)
			cout << setw(14) << ptr[i]->id << setw(15) << ptr[i]->firstName << setw(15) << ptr[i]->lastName 
			     << setw(6) << ptr[i]->gpa << setw(20) << ptr[i]->email << endl;
		break;
	case 5:
		for (int i = 0; i < sizeOfArray; i++)
			cout << setw(20) << ptr[i]->email << setw(15) << ptr[i]->firstName << setw(15) << ptr[i]->lastName 
			     << setw(6) << ptr[i]->gpa << setw(14) << ptr[i]->id << endl;
		break;
	}
}