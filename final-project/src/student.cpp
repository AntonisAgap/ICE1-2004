#include "student.h"


Student::Student (mystring _am, mystring _firstName, mystring _lastName)
{
    am = _am;
    firstName = _firstName;
    lastName = _lastName;
}

Student::Student (const Student &S)
{
    am = S.am;
    firstName = S.firstName;
    lastName = S.lastName;
    gradesList = S.gradesList;
}

void Student::insertGrade(const Grade &G)
{
    gradesList.push_back(G);
}
