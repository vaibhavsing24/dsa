#include <iostream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

int partition(Student students[], int low, int high) {
    float pivot = students[high].sgpa;
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        if (students[j].sgpa >= pivot) {
            ++i;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return (i + 1);
}

void quickSort(Student students[], int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);
        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

void printTopTen(Student students[], int n) {
    cout << "Top Ten Students:\n";
    int count = 0;
    for (int i = 0; i < n && count < 10; ++i) {
        cout << students[i].name << "\tSGPA: " << students[i].sgpa << "\n";
        ++count;
    }
}

void searchBySGPA(Student students[], int n, float searchSGPA) {
    bool found = false;
    cout << "Students with SGPA " << searchSGPA << ":\n";

    for (int i = 0; i < n; ++i) {
        if (students[i].sgpa == searchSGPA) {
            found = true;
            cout << students[i].name << "\n";
        }
    }

    if (!found) {
        cout << "No student found with SGPA " << searchSGPA << "\n";
    }
}

int main() {
    const int maxSize = 15;
    Student students[maxSize];
    int numStudents;
    float searchSGPA;

    cout << "Enter the number of students (max 15): ";
    cin >> numStudents;
    cin.ignore(); // Clear newline from buffer

    if (numStudents > maxSize || numStudents <= 0) {
        cout << "Invalid number of students.\n";
        return 1;
    }

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cin.ignore(); // Clear newline from buffer

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "SGPA: ";
        cin >> students[i].sgpa;
        cin.ignore(); // Clear newline from buffer
    }

    cout << "\nBefore sorting:\n";
    printTopTen(students, numStudents);

    quickSort(students, 0, numStudents - 1);

    cout << "\nAfter sorting by SGPA:\n";
    printTopTen(students, numStudents);

    cout << "\nEnter SGPA to search for: ";
    cin >> searchSGPA;
    searchBySGPA(students, numStudents, searchSGPA);

    return 0;
}
