//
//  main.cpp
//  C867_PA
//
//  Created by John Sigvertsen on 8/20/22.
//

#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,Sigvertsen,jsigver@wgu.edu,29,30,35,40,SOFTWARE"
    };
    
    cout << "C867 - Scripting and Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 008655435" << endl;
    cout << "Name: John Sigvertsen" << endl;
    cout << endl;
    
    Roster classRoster = Roster(5);
    DegreeProgram degree_program;

    for (int i = 0; i < 5; i++) {
        
        int stop = studentData[i].find(",");
        string studentID = studentData[i].substr(0, stop);
        
        int start = stop + 1;
        stop = studentData[i].find(",", start);
        string first_name = studentData[i].substr(start, stop - start);
        
        start = stop + 1;
        stop = studentData[i].find(",", start);
        string last_name = studentData[i].substr(start, stop - start);
        
        start = stop + 1;
        stop = studentData[i].find(",", start);
        string email_address = studentData[i].substr(start, stop - start);
        
        start = stop + 1;
        stop = studentData[i].find(",", start);
        int age = stoi(studentData[i].substr(start, stop - start));
        
        start = stop + 1;
        stop = studentData[i].find(",", start);
        int days_in_course_1 = stoi(studentData[i].substr(start, stop - start));
        
        start = stop + 1;
        stop = studentData[i].find(",", start);
        int days_in_course_2 = stoi(studentData[i].substr(start, stop - start));
        
        start = stop + 1;
        stop = studentData[i].find(",", start);
        int days_in_course_3 = stoi(studentData[i].substr(start, stop - start));
        
        start = stop + 1;
        stop = studentData[i].find(",", start);
        if (studentData[i].substr(start, stop - start) == "SECURITY") {
            degree_program = SECURITY;
        }
        else if (studentData[i].substr(start, stop - start) == "NETWORK") {
            degree_program = NETWORK;
        }
        else {
            degree_program = SOFTWARE;
        }

        classRoster.add(studentID, first_name, last_name, email_address, age, days_in_course_1, days_in_course_2, days_in_course_3, degree_program);
    }
    
    classRoster.printAll();
    
    classRoster.printInvalidEmails();
    
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->get_studentID());
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    
    classRoster.printAll();
    
    classRoster.remove("A3");
    
    return 0;
}
