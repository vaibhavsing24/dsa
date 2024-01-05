#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float SGPA;
};

void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; ++i) {
        Student key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].name > key.name) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        cin.ignore();
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].SGPA;
    }

    // Sort students alphabetically by name
    insertionSort(students, numStudents);

    cout << "\nSorted list of students alphabetically:" << endl;
    displayStudents(students, numStudents);

    string searchName;
    cout << "\nEnter the name to search: ";
    cin.ignore();
    getline(cin, searchName);

    // Search for a student by name
    searchStudentByName(students, numStudents, searchName);

    return 0;
}
