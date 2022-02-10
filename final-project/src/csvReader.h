#include "student.h"
#include "matchedCourse.h"
#include "course.h"
#include <vector>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "myString.h"

/* Το διάβασμα των αρχείων .csv το υλοποιήσα με μεθόδους αυτής της κλάσης, αφού μου φάνηκε πιο
 * "αντικειμεντροφικά" λογικό να φτιάχνω αντικείμενα reader και writers, όπως π.χ οι κλάσεις FileReader και
 * FileWriter της Java. Σε αυτήν την κλάση διαβάζονται τα αρχεία, των οποιών το path δίνεται στον κατασκευαστή της
 * κλάσης σαν παραμέτρος. Με τις μεθοδόυς makeStudentsData κτλπ, διαβάζω τα αρχεία, φτιάχνω το κατάλληλο αντικείμενο
 * και το αποθηκεύω στην κατάλληλη λίστα. Επισής όταν διαβάζω τους βαθμούς, χρησιμοποιώ τις private συναρτήσεις που
 * έχω ορίσει courseIdExists,checkIfDuplicate για να τσεκάρω αν η γραμμή του βαθμού περιέχει κωδικό μαθήματος που δεν
 * υπάρχει, ή έχει ξαναπεραστεί. Ο έλεγχος για μαθητή που δεν ύπαρχει γίνεται μέσα στην makeStudentsData με ένα if.
 * Τα errors αυτά τα αποθηκεύω σε κατάλληλες λίστες για να μπορέσω να τα ξεχωρίσω μεταξύ τους όταν θα τα γράφω στο
 * report αρχείο.*/

class CsvReader
{
private:
    mystring filePath1;
    mystring filePath2;
    mystring filePath3;
    mystring filePath4;
    list<Student> studentsList;
    list<Course> coursesList;
    list<MatchedCourse> matchedCoursesList;
    list<mystring> studentErrorList;
    list<mystring> gradeErrorList;
    list<mystring> duplicateErrorList;
    bool courseIdExists(mystring);
    bool checkIfDuplicate(mystring,list<Grade>);
public:
    CsvReader (mystring, mystring, mystring, mystring);
    CsvReader (const CsvReader &);
    bool makeStudentsData();
    bool makeCoursesData();
    bool makeGradesData();
    bool makeMatchedData();
    list<Student> getStudentsList()  {return studentsList;}
    list<Course> getCoursesList()  {return coursesList;}
    list<MatchedCourse> getMatchedCoursesList()  {return matchedCoursesList;}
    list<mystring> getStudentErrorList() { return studentErrorList;}
    list<mystring> getGradeErrorList() { return gradeErrorList;}
    list<mystring> getDuplicateErrorList() { return duplicateErrorList;}
    mystring getFilepath1() const { return filePath1;};
    mystring getFilepath2() const { return filePath2;};
    mystring getFilepath3() const { return filePath3;};
    mystring getFilepath4() const { return filePath4;};

};
