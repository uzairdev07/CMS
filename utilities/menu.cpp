//
// Created by uzair on 3/19/22.
//

#include "menu.h"
#include <iomanip>
#include "../objects/courses/Courses.h"
#include "../objects/subjects/Subjects.h"
#include "../objects/teachers/Teachers.h"
#include "../objects/students/Students.h"

using namespace std;

Menu::Menu() {
    displayMain(
            vector<string>{
                    "Course Menu",
                    "Subject Menu",
                    "Teacher Menu",
                    "Student Menu",
                    "Library Menu"
            }
    );
}

void Menu::displayMain(vector<string> list) const {
    for (int i = 0; i < list.size(); i++)
        cout << setw(50) << i + 1 << ". " << list.at(i) << endl;
    int choice = 0;
    cout << "Enter Number: ";
    cin >> choice;
    switch (choice) {
        case 1:
            courseMenu();
        case 2:
            subjectMenu();
        case 3:
            teacherMenu();
        case 4:
            studentMenu();
        case 5:
            libraryMenu();
    }
}



void Menu::courseMenu() const {
    Courses courses;
    courses.select();
}

void Menu::subjectMenu() const {
    Subjects subjects;
    subjects.select();
}

void Menu::teacherMenu() const {
    Teachers teachers;
    teachers.select();
}

void Menu::studentMenu() const {
    Students students;
    students.select();
}

void Menu::libraryMenu() const {
}


Menu::~Menu() {

}