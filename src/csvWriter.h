#include "error.h"
#include "string.h"
#include "list"
#include "myString.h"

class CsvWriter
{
private:
    char* filePath;
public:
    CsvWriter (char *);
    CsvWriter (const CsvWriter &);
    virtual ~CsvWriter ();
    bool writeReportFile(list<Error>);
    bool writeDataReportFile(list<mystring>, list<mystring>, list<mystring>);
};
