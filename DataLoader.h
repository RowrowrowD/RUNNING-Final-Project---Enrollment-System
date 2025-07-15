#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Models.h"

using namespace std;

// ?? Load all students from students.txt
vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file("students.txt");
    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;
        Student s;
        stringstream ss(line);
        ss >> s.studentID >> s.lastName >> s.firstName >> s.middleName
           >> s.gender >> s.birthday >> s.address >> s.degreeProgram
           >> s.yearLevel >> s.term;
        students.push_back(s);
    }

    return students;
}

// ?? Load all courses from courses.txt
vector<Course> loadCourses() {
    vector<Course> courses;
    ifstream file("courses.txt");
    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;
        Course c;
        stringstream ss(line);
        ss >> c.courseCode;
        ss.ignore(); getline(ss, c.courseTitle, '\n');
        istringstream extract(line);
        extract >> c.courseCode;
        extract.ignore(30); // jump to column
        getline(extract, c.courseTitle);
        c.courseTitle = c.courseTitle.substr(0, 29);
        extract >> c.units >> c.yearLevel >> c.term;
        courses.push_back(c);
    }

    return courses;
}

// ?? Load all schedules from schedules.txt
vector<Schedule> loadSchedules() {
    vector<Schedule> schedules;
    ifstream file("schedules.txt");
    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;
        Schedule s;
        stringstream ss(line);
        ss >> s.courseCode;
        ss.ignore(); getline(ss, s.courseTitle, '\n');
        istringstream extract(line);
        extract >> s.courseCode;
        extract.ignore(30); // jump to column
        getline(extract, s.courseTitle);
        s.courseTitle = s.courseTitle.substr(0, 29);
        extract >> s.units >> s.yearLevel >> s.term
                >> s.section >> s.day >> ws;
        getline(extract, s.time, '\t');
        getline(extract, s.room);
        schedules.push_back(s);
    }

    return schedules;
}

// ?? Load all enrollments from enrollments.txt
vector<Enrollment> loadEnrollments() {
    vector<Enrollment> enrollments;
    ifstream file("enrollments.txt");
    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;
        Enrollment e;
        stringstream ss(line);
        ss >> e.studentID >> e.courseCode;
        ss.ignore(); getline(ss, e.courseTitle, '\n');
        istringstream extract(line);
        extract >> e.studentID >> e.courseCode;
        extract.ignore(30); // jump to course title
        getline(extract, e.courseTitle);
        e.courseTitle = e.courseTitle.substr(0, 29);
        extract >> e.section >> e.day >> ws;
        getline(extract, e.time, '\t');
        getline(extract, e.room);
        enrollments.push_back(e);
    }

    return enrollments;
}

#endif

