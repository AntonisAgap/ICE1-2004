#include "csvWriter.h"
#include <fstream>
#include <iostream>


CsvWriter::CsvWriter (char *_filePath)
{
    filePath = new char[strlen (_filePath) + 1];
    strcpy (filePath, _filePath);
}

CsvWriter::CsvWriter (const CsvWriter &CW)
{
    filePath = CW.filePath;
}


/* διαγραφή του allocated space για να μην ενφανιστούν
 * προβλήματα memory leak*/

CsvWriter::~CsvWriter ()
{
    delete []filePath;
}


bool CsvWriter::writeReportFile(list<Error> errorsList){
    std::ofstream file;
    file.open (filePath, ios::out);
    // check if file can open
    if(file.is_open()) {
        for (list<Error>::iterator it = errorsList.begin(); it != errorsList.end(); ++it) {
            file << it->getAm().tocstr() << "," << it->getFirstName().tocstr() << "," << it->getLastName().tocstr()
                 << "," << it->getOldID().tocstr() << ","
                 << it->getOldName().tocstr() << "," << it->getNewID().tocstr() << "," << it->getNewName().tocstr()
                 << "," << it->getGrade() << "\n";
        }
        file.close();
        return true;
    } else
        return false;

}

bool CsvWriter::writeDataReportFile(list<mystring> studentErrorList, list<mystring> gradeErrorList, list<mystring> duplicateErrorList) {
    std::ofstream file;
    file.open(filePath, ios::out);
    // check if file can open
    if (file.is_open()) {
        for (list<mystring>::iterator it = studentErrorList.begin(); it != studentErrorList.end(); ++it) {
            file << it->tocstr() << "," << "Non Existent Student" << "\n";
        }

        for (list<mystring>::iterator it = gradeErrorList.begin(); it != gradeErrorList.end(); ++it) {
            file << it->tocstr() << "," << "Non Existent Grade" << "\n";
        }

        for (list<mystring>::iterator it = duplicateErrorList.begin(); it != duplicateErrorList.end(); ++it) {
            file << it->tocstr() << "," << "Duplicate Grade" << "\n";
        }
        file.close();
        return true;
    } else
        return false;
}