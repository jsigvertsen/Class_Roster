//
//  student.cpp
//  C867_PA
//
//  Created by John Sigvertsen on 8/20/22.
//

#include <iostream>
#include <string>
#include "student.h"

Student::Student() {
    studentID = "default_studentid";
    first_name = "default_first_name";
    last_name = "default_last_name";
    email_address = "default_email_address";
    age = -1;
};

Student::Student(string student_ID, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree_program) {
    this->studentID = student_ID;
    this->first_name = first_name;
    this->last_name = last_name;
    this->email_address = email_address;
    this->age = age;
    this->days_in_course[0] = days_in_course[0];
    this->days_in_course[1] = days_in_course[1];
    this->days_in_course[2] = days_in_course[2];
    this->degree_program = degree_program;
};

Student::~Student(){};

string Student::get_studentID() {
    return studentID;
}

string Student::get_first_name() {
    return this->first_name;
}

string Student::get_last_name() {
    return this->last_name;
}

string Student::get_email_address() {
    return this->email_address;
}

int Student::get_age() {
    return this->age;
}

const int* Student::get_days_in_course() {
    return this->days_in_course;
}

DegreeProgram Student::get_degree_program() {
    return this->degree_program;
}

void Student::set_studentID(string student_ID) {
    this->studentID = student_ID;
}

void Student::set_first_name(string first_name) {
    this->first_name = first_name;
}

void Student::set_last_name(string last_name) {
    this->last_name = last_name;
}

void Student::set_email_address(string email_address) {
    this->email_address = email_address;
}

void Student::set_age(int age) {
    this->age = age;
}

void Student::set_days_in_course(const int days_in_course[]) {
    this->days_in_course[0] = days_in_course[0];
    this->days_in_course[1] = days_in_course[1];
    this->days_in_course[2] = days_in_course[2];
}

void Student::set_degree_program(DegreeProgram degree_program) {
    this->degree_program = degree_program;
}

void Student::print() {
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
    
    cout << studentID << "\t";
    cout << first_name << "\t";
    cout << last_name << "\t";
    cout << email_address << "\t";
    cout << age << "\t";
    cout << "{ " << days_in_course[0] << ", " << days_in_course[1] << ", " << days_in_course[2] << " }" << "\t";
    cout << program << endl;
}



