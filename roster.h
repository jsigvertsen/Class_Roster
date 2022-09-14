//
//  roster.h
//  C867_PA
//
//  Created by John Sigvertsen on 8/20/22.
//

#ifndef roster_h
#define roster_h
#include "student.h"
using namespace std;

class Roster {
public:
    Roster(int numStudents);
    Roster();
    ~Roster();
    
    int index;
    int numStudents;
    Student** classRosterArray;
    
    void add(string studentID, string first_name, string last_name, string email_address, int age, int days_in_course_1, int days_in_course_2, int days_in_course_3, DegreeProgram degree_program);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree_program);
};

#endif /* roster_h */
