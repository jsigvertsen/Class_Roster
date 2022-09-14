//
//  student.h
//  C867_PA
//
//  Created by John Sigvertsen on 8/20/22.
//

#ifndef student_h
#define student_h
#include "degree.h"
using namespace std;

class Student {
public:
    Student();
    Student(string studentID, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree_program);
    ~Student();
    
    string studentID;
    string first_name;
    string last_name;
    string email_address;
    int age;
    DegreeProgram degree_program;
    int days_in_course[3];
    
    string get_studentID();
    string get_first_name();
    string get_last_name();
    string get_email_address();
    int get_age();
    DegreeProgram get_degree_program();
    const int* get_days_in_course();
    
    void set_studentID(string);
    void set_first_name(string);
    void set_last_name(string);
    void set_email_address(string);
    void set_age(int);
    void set_days_in_course(const int days_in_course[]);
    void set_degree_program(DegreeProgram);
    
    void print();
};

#endif /* student_h */
