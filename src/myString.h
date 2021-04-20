#ifndef FINALWITHSTRING_MYSTRING_H
#define FINALWITHSTRING_MYSTRING_H

#include <vector>
#include <string.h>

/* Αυτή είναι η custom κλάση string, η οποία ανέβηκε σαν αρχείο στα έγγραφα του μαθήματος. Είχα κολλήσει
 * σε αυτό το σημείο και δεν μπορούσα να φτιάξω μια δική μου κλάση String και είχα μπλέξει με περίπλοκες
 * υλοποιήσεις που συμβουλευόμουν απο το διαδίκτυο. Αυτή η κλάση χρησιμοποιείται παντού σαν αντικατάσταση της
 * string*/

using namespace std;

class mystring
{

private:
    vector <char> s;
public:
    mystring ();
    mystring (char *);
    mystring (const mystring &);
    bool operator == (const mystring &);
    mystring operator += (char );
    int size ();
    char * tocstr ();
};

#endif