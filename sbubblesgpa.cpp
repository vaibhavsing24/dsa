#include <iostream>
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
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void searchBySGPA(Student arr[], int n, float key) {
    bool found = false;

    cout << "Students with SGPA " << key << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (arr[i].SGPA == key) {
            cout << "Roll No: " << arr[i].rollNo << ", Name: " << arr[i].name << ", SGPA: " << arr[i].SGPA << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No student found with SGPA: " << key << endl;
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

    bubbleSort(students, numStudents);

    cout << "\nRoll Call List (Sorted by Roll Numbers):" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].SGPA << endl;
    }

    float searchSGPA;
    cout << "\nEnter the SGPA to search: ";
    cin >> searchSGPA;

    searchBySGPA(students, numStudents, searchSGPA);

    return 0;
}
