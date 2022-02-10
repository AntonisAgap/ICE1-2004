#include "myString.h"
/* Αυτή είναι η κλάση Grade. Η κλάση grade φτιάχνει αντικείμενα τα οποία αντικατοπτρίζουν
 * έναν βαθμό ενός φοιτητή. Γι αυτόν τον λόγο περιέχει το id του μαθήματος και όχι του φοιτητή,
 * αφού αποθηκεύεται στο κατάλληλο αντικειμένα φοιτητή που ανήκει. Επίσης όπως φαίνεται ο βαθμός αποθηκεύεται
 * σαν float,άρα μπορούν να γίνουν διάφορες πράξεις με αυτόν. */

class Grade
{
private:
    mystring date1;
    mystring date2;
    mystring date3;
    mystring id;
    float grade;
public:
    Grade (mystring,mystring,mystring,mystring,float);
    Grade (const Grade &);
    mystring getId () const {return id;}
    float getGrade () const {return grade;}
    mystring getDate1 () const {return date1;}
    mystring getDate2 () const {return date2;}
    mystring getDate3 () const {return date3;}
};