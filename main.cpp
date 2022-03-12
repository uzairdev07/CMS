#include <iostream>
#include "objects/courses/Courses.h"
#include "objects/subjects/Subjects.h"
#include "objects/teachers/Teachers.h"
#include "objects/students/Students.h"
using namespace std;

int main() {
    cout << "=== Courses ===" << endl;
    Courses courses;
    courses.getTotalCourses();
    cout << endl;
    cout << "=== Subjects ===" << endl;
    Subjects subjects;
    subjects.getTotalSubjects();
    cout << endl;
    cout << "=== Teachers ===" << endl;
    Teachers teachers;
    teachers.getTotalTeachers();
    cout << endl;
    cout << "=== Students ===" << endl;
    Students students;
    students.getTotalStudents();
    cout << endl;
    return 0;
}