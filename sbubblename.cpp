#include<iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float SGPA;
};

void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].rollNo > arr[j + 1].rollNo) {
                // Swap elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayStudents(Student arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Roll No: " << arr[i].rollNo << ", Name: " << arr[i].name << ", SGPA: " << arr[i].SGPA << endl;
    }
}

void searchStudentByName(Student arr[], int n, string key) {
    bool found = false;
    cout << "Students with name '" << key << "':" << endl;
    for (int i = 0; i < n; ++i) {
        if (arr[i].name == key) {
            cout << "Roll No: " << arr[i].rollNo << ", Name: " << arr[i].name << ", SGPA: " << arr[i].SGPA << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student with the given name found." << endl;
    }
}

int main() {
    const int maxSize = 15;
    Student students[maxSize];
    int numStudents;

    cout << "Enter the number of students (max 15): ";
    cin >> numStudents;

    if (numStudents > maxSize || numStudents <= 0) {
        cout << "Invalid input for number of students.";
        return 1;
    }

    cout << "Enter student details (Roll No, Name, SGPA):" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].SGPA;
    }

    // Sort students based on roll number
    bubbleSort(students, numStudents);

    cout << "\nSorted Roll Call List:" << endl;
    displayStudents(students, numStudents);

    string searchName;
    cout << "\nEnter the name to search: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, searchName);

    // Search for a student by name
    searchStudentByName(students, numStudents, searchName);

    return 0;
}
