#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    string course;
    float marks;

public:
    Student(int id, string name, int age, string course, float marks) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->course = course;
        this->marks = marks;
    }

    int getId() const { return id; }
    float getMarks() const { return marks; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setCourse(string course) { this->course = course; }
    void setMarks(float marks) { this->marks = marks; }

    string calculateGrade() const {
        if (marks >= 90) return "A+";
        else if (marks >= 75) return "A";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else return "Fail";
    }

    void display() const {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nCourse: " << course;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << calculateGrade() << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id, age;
        string name, course;
        float marks;

        cout << "Enter ID: ";
        cin >> id;

        // Duplicate ID Check
        for (const Student &s : students) {
            if (s.getId() == id) {
                cout << "Student with this ID already exists!\n";
                return;
            }
        }

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Course: ";
        cin >> course;

        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(id, name, age, course, marks));

        cout << "Student Added Successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No Students available.\n";
            return;
        }

        for (const Student &s : students) {
            s.display();
        }
    }

    void searchStudent() {
        int searchId;
        cout << "Enter student ID to search: ";
        cin >> searchId;

        for (const Student &s : students) {
            if (s.getId() == searchId) {
                cout << "\nStudent Found:\n";
                s.display();
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void deleteStudent() {
        int deleteId;
        cout << "Enter student ID to delete: ";
        cin >> deleteId;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == deleteId) {
                students.erase(students.begin() + i);
                cout << "Student Deleted Successfully.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void sortByMarks() {
        sort(students.begin(), students.end(), [](Student a, Student b) {
            return a.getMarks() > b.getMarks();
        });

        cout << "Students sorted by marks (Descending).\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n====== Student Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Sort by Marks\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.deleteStudent(); break;
            case 5: manager.sortByMarks(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}