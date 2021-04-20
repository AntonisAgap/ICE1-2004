#include "error.h"

Error::Error (mystring _am, mystring _firstName, mystring _lastName, mystring _oldID, mystring _oldName, mystring _newID, mystring _newName, float _grade)
{
    am = _am;
    firstName = _firstName;
    lastName = _lastName;
    oldID = _oldID;
    oldName = _oldName;
    newID = _newID;
    newName = _newName;
    grade = _grade;

}

Error::Error (const Error &E)
{
    am = E.am;
    firstName = E.firstName;
    lastName = E.lastName;
    oldID = E.oldID;
    oldName = E.oldName;
    newID = E.newID;
    newName = E.newName;
    grade = E.grade;

}