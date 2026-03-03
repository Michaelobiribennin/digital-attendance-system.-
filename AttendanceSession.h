#ifndef ATTENDANCESESSION_H
#define ATTENDANCESESSION_H

#include <iostream>
#include <map>
using namespace std;

class AttendanceSession {
private:
    string courseCode;
    string date;
    string startTime;
    int duration;

    map<string, string> attendanceRecord;

public:
    AttendanceSession(string code, string d, string time, int dur) {
        courseCode = code;
        date = d;
        startTime = time;
        duration = dur;
    }

    void markAttendance(string indexNumber, string status) {
        attendanceRecord[indexNumber] = status;
    }

    void displayAttendance() {
        cout << "\nAttendance List:\n";
        for (auto record : attendanceRecord) {
            cout << record.first << " - " << record.second << endl;
        }
    }

    void displaySummary() {
        int present = 0, absent = 0, late = 0;

        for (auto record : attendanceRecord) {
            if (record.second == "Present") present++;
            else if (record.second == "Absent") absent++;
            else if (record.second == "Late") late++;
        }

        cout << "\nSummary:\n";
        cout << "Present: " << present << endl;
        cout << "Absent: " << absent << endl;
        cout << "Late: " << late << endl;
    }
};

#endif
