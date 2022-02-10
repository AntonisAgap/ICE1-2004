#include "course.h"

Course::Course (mystring _id, mystring _name)
{
    name = _name;
    id = _id;

}

Course::Course (const Course &C)
{
    name = C.name;
    id = C.id;
}

