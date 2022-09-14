//
//  roster.cpp
//  C867_PA
//
//  Created by John Sigvertsen on 8/20/22.
//

#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

Roster::Roster() {
    index = -1;
    numStudents = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int numStudents) {
    index = -1;
    this->numStudents = numStudents;
    this->classRosterArray = new Student*[numStudents];
};

Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i] = nullptr;
    }
    cout << "\nMemory allocated in Roster has been released." << endl;
};

void Roster::add(string studentID, string first_name, string last_name, string email_address, int age, int days_in_course_1, int days_in_course_2, int days_in_course_3, DegreeProgram degree_program) {
    
    index += 1;
    
    int days_in_course [3] = {days_in_course_1, days_in_course_2, days_in_course_3};
    
    classRosterArray[index] = new Student (studentID, first_name, last_name, email_address, age, days_in_course, degree_program);

};

void Roster::remove(string studentID) {
    
    cout << "\nRemoving ID: " << studentID << "\n" << endl;
    
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            cout << "The student with ID: " << studentID << " was not found." << endl;
            break;
        }
        else if (classRosterArray[i]->get_studentID() == studentID) {
            classRosterArray[i] = nullptr;
        }
    }
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else {
            classRosterArray[i]->print();
        }
    };
}

void Roster::printAverageDaysInCourse(string studentID) {
    
    int average = 0;
    int counter = 0;
    string id;
    
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->get_studentID() == studentID) {
            id = classRosterArray[i]->get_studentID();
            for (int j = 0; j < 3; j++) {
                counter += classRosterArray[i]->get_days_in_course()[j];
            }
            average = counter / 3;
            cout << "\nStudent ID: " << id << ", average days in course is: " << average << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    
    cout << "\nDisplaying invalid emails: \n" << endl;
    
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->get_email_address().find(" ") != string::npos) {
            cout << classRosterArray[i]->get_email_address() << " - is invalid." << endl;
        }
        else if (classRosterArray[i]->get_email_address().find(".") == string::npos) {
            cout << classRosterArray[i]->get_email_address() << " - is invalid." << endl;
        }
        else if (classRosterArray[i]->get_email_address().find("@") == string::npos) {
            cout << classRosterArray[i]->get_email_address() << " - is invalid." << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degree_program) {
    string program;
    
    if (degree_program == 0) {
        program = "SECURITY";
    }
    else if (degree_program == 1) {
        program = "NETWORK";
    }
    else {
        program = "SOFTWARE";
    }
    
    cout << "\nShowing students in degree program: " << program << "\n" << endl;
    
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->get_degree_program() == degree_program) {
            classRosterArray[i]->print();
        }
    }
};

