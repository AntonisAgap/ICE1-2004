#include "myString.h"

/* Αυτή είναι η κλάση Error, η Error φτιάχνει αντικειμένα που στην ουσία αντικατοπτρίζουν τις
 * γραμμές του αρχείου Error.csv. Ο κύριος λόγος που την έφτιαξα ήταν γιατι χρειαζόμουν μια δομή
 * δεδομένων για να αποθηκεύω mystring και float στην ίδια δομή.*/

class Error
{
private:
    mystring am;
    mystring firstName;
    mystring lastName;
    mystring oldID;
    mystring oldName;
    mystring newID;
    mystring newName;
    float grade;
public:
    Error (mystring, mystring, mystring, mystring, mystring, mystring, mystring, float);
    mystring getAm () const {return am;}
    mystring getFirstName () const {return firstName;}
    mystring getLastName () const {return lastName;}
    mystring getOldID () const {return oldID;}
    mystring getOldName () const {return oldName;}
    mystring getNewID () const {return newID;}
    mystring getNewName () const {return newName;}
    float getGrade () const {return grade;}
    Error (const Error &);
};