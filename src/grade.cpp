#include "grade.h"

Grade::Grade (mystring _date1,mystring _date2,mystring _date3,mystring _id, float _grade)
{
    date1 = _date1;
    date2 = _date2;
    date3 = _date3;
    id = _id;
    grade = _grade;
}

Grade::Grade (const Grade &G)
{
    date1 = G.date1;
    date2 = G.date2;
    date3 = G.date3;
    id = G.id;
    grade = G.grade;
}
