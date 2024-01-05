#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float SGPA;
};

int partition(Student arr[], int low, int high) {
    float pivot = arr[high].SGPA;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j].SGPA >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void findTopTenToppers(Student arr[], int n) {
    cout << "Top Ten Toppers:" << endl;
    for (int i = 0; i < min(n, 10); ++i) {
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

    quickSort(students, 0, numStudents - 1);

    findTopTenToppers(students, numStudents);

    string searchName;
    cout << "\nEnter the name to search: ";
    cin.ignore();
    getline(cin, searchName);

    searchStudentByName(students, numStudents, searchName);

    return 0;
}
