#include <list>
#include "grade.h"

/* Τα αντικείμενα αυτής της κλάσης αντιπροσωπεύουν τον κάθε μαθητή που διαβάζεται από το Students.csv. Κάθε μαθητής
 * έχει όνομα,επίθετο,αριθμό μητρώου και μία λίστα με όλους τους βαθμούς τους (αντικείμενα Grade). Η εισαγωγή βαθμού
 * σε αυτήν την λίστα πραγματοποιείται με την public μέθοδο insertGrade()*/


class Student
{
private:
    mystring am;
    mystring firstName;
    mystring lastName;
    list<Grade> gradesList;
public:
    Student (mystring, mystring , mystring);
    Student (const Student &);
    mystring getAm () const {return am;}
    mystring getfirstName () const {return firstName;}
    mystring getlastName () const {return lastName;}
    list<Grade> getGradesList()  {return gradesList;}
    void insertGrade(const Grade &);
};

