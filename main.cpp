#include <iostream>
#include <vector>
#include "Student.h"
#include "AttendanceSession.h"

using namespace std;

void markAttendanceForStudents(vector<Student>& students, AttendanceSession& session);

int main() {
    vector<Student> students;
    int choice;

    AttendanceSession session("EEE227", "2026-02-20", "10:00", 2);

    do {
        cout << "\n===== Digital Attendance System =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Mark Attendance\n";
        cout << "4. View Attendance Report\n";
        cout << "5. View Summary\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name, index;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Index Number: ";
            cin >> index;

            students.push_back(Student(name, index));
            cout << "Student Registered!\n";
            break;
        }

        case 2:
            for (int i = 0; i < students.size(); i++) {
                cout << students[i].getName()
                     << " - "
                     << students[i].getIndexNumber()
                     << endl;
            }
            break;

        case 3:
            markAttendanceForStudents(students, session);
            break;

        case 4:
            session.displayAttendance();
            break;

        case 5:
            session.displaySummary();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

void markAttendanceForStudents(vector<Student>& students, AttendanceSession& session) {
    for (int i = 0; i < students.size(); i++) {
        string status;

        cout << "Student: " << students[i].getName() << endl;
        cout << "Enter status (P/A/L): ";
        cin >> status;

        if (status == "P") session.markAttendance(students[i].getIndexNumber(), "Present");
        else if (status == "A") session.markAttendance(students[i].getIndexNumber(), "Absent");
        else if (status == "L") session.markAttendance(students[i].getIndexNumber(), "Late");
        else {
            cout << "Invalid input. Marked Absent.\n";
            session.markAttendance(students[i].getIndexNumber(), "Absent");
        }
    }
}
