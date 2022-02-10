#include "myString.h"

/* Αυτή είναι η κλάση με την οποία δημιουργούνται τα αντικείμενα Courses.
 * Τα courses είναι να μαθήματα και έχουν 2 χαρακτηριστικά (όνομα και κωδικό)*/

class Course
{
private:
    mystring name;
    mystring id;
public:
    Course (mystring, mystring);
    Course (const Course &);
    mystring getName () const {return name;}
    mystring getId () const {return id;}
};