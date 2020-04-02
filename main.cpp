#include <iostream>
#include <string>
#include <typeinfo>

#include "Student.h"
#include "FixedSizeFile.h"
#include "PreDefinedSizeFile.h"
#include "DelimitedSizeFile.h"

using namespace std;

int main()
{
    Student ahmed ;
    ahmed.setId(50);
    ahmed.setName("Ahmed");
    ahmed.setGrade(100);
    Student mohamed;
    mohamed.setId(3);
    mohamed.setName("Mohamed");
    mohamed.setGrade(60.5);

    //FixedSizeFile fixFile("Student File Fixed Size.txt");
    PreDefinedSizeFile preDefinedFile("Student File Predefined Size.txt");
    preDefinedFile.writeToFile(ahmed);
    preDefinedFile.writeToFile(mohamed);
    Student ahmed1 = preDefinedFile.getStudentDataOfId(50);
    if(ahmed1.getId() != 0) {cout << "operation done successfully for student" << ahmed1.getName() << endl;}
    else {cout << "Operation not done successfully" << endl;}

    DelimitedSizeFile delimitedFile("Student File Delimited Size.csv");
    delimitedFile.writeToFile(ahmed);
    delimitedFile.writeToFile(mohamed);
    delimitedFile.printAllStudentsData();
    Student ahmed2 = delimitedFile.getStudentDataOfId(50);
    if(ahmed2.getId() != 0) {cout << "operation done successfully for student" << ahmed2.getName() << endl;}
    else {cout << "Operation not done successfully" << endl;}


    return 0;
}
