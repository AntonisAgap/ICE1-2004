#include "myString.h"

mystring::mystring ()
{

}

mystring::mystring (char *x)
{
    for (int i = 0; i < strlen (x); i++)
        s.push_back (x[i]);
}

mystring::mystring (const mystring &k)
{
    s = k.s;
}

bool mystring::operator== (const mystring &x)
{
    if (s == x.s)
        return true;
    else
        return false;

}

int mystring::size ()
{
    return s.size ();
}

mystring mystring::operator += (char c)
{
    s.push_back (c);
    return *this;
}

char * mystring::tocstr ()
{
    char *tmp;
    int i;
    tmp = new char [s.size() + 1];
    for (i = 0; i < s.size(); i++)
        tmp[i] = s[i];
    tmp[i] = '\0';
    return tmp;
}