#include "myString.h"
/* Επειδή δεν μπόρεσα να βρω τρόπο να συσχετίσω τα μαθήματα μόνο από το Courses.csv, έφτιαξα
 * χειρόγραφα ένα άλλο αρχείο (MatchedCourses.csv) που περιέχει τις αντιστοιχίες των μαθημάτων. Κάθε αντικείμενο
 * αυτής της κλάσης αντιπροσωπεύει μια αντιστοιχία μαθήματος από αυτό το αρχείο */

class MatchedCourse
{
private:
    mystring oldName;
    mystring oldId;
    mystring newName;
    mystring newId;
public:
    MatchedCourse (mystring, mystring, mystring, mystring);
    MatchedCourse (const MatchedCourse &);
    mystring getOldName () const {return oldName;}
    mystring getOldId () const {return oldId;}
    mystring getNewName () const {return newName;}
    mystring getNewId () const {return newId;}
};

