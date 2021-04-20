#include "csvReader.h"
#include "csvWriter.h"
#include <iostream>
#include "myString.h"


void matchCourse(mystring, list<MatchedCourse>,mystring&, mystring& ,
                 mystring& , mystring&);

int main(){
    list<Grade> gradesList;
    list<Error> errorsList;
    list<Student> studentsList;

    CsvReader reader("C:\\Users\\green\\Desktop\\Students.csv","C:\\Users\\green\\Desktop\\Courses.csv","C:\\Users\\green\\Desktop\\Grades.csv","C:\\Users\\green\\Desktop\\MatchedCoursesGr.csv");
    CsvWriter writer("C:\\Users\\green\\Desktop\\Errors.csv");
    CsvWriter writer2("C:\\Users\\green\\Desktop\\DataErrors.csv");

    cout << ". Making Students data from the .csv file..." << endl;
    if (reader.makeStudentsData())
    {
        cout << "   Making Students data completed!" << endl;
        cout << "   Students: " << reader.getStudentsList().size() << endl;
    } else {
        cout << "   Couldn't open " << reader.getFilepath1().tocstr() << endl;
        return 0;
    }

    cout << ". Making Courses data from the .csv file..." << endl;
    if(reader.makeCoursesData()) {
        cout << "   Making Courses data completed!" << endl;
        cout << "   Courses: " << reader.getCoursesList().size() << endl;
    } else {
        cout << "   Couldn't open " << reader.getFilepath2().tocstr() << endl;
        return 0;
    }

    /* Η μόνη αλλαγή που έκανα σε αυτό το αρχείο είναι να αντικαταστήσω το , με .  για να φτιάξω τους float αριθμούς
     * και να μην μπερδεύεται με τον delimiter μου (,) */

    cout << ". Making Grades data from the .csv file..." << endl;
    if(reader.makeGradesData()) {
        cout << "   Making Grades data completed!" << endl;

        cout << "   Student errors: " << reader.getStudentErrorList().size() << endl;
        cout << "   Grade errors: " << reader.getGradeErrorList().size() << endl;
        cout << "   Duplicate errors: " << reader.getDuplicateErrorList().size() << endl;
    }else{
        cout << "   Couldn't open " << reader.getFilepath3().tocstr() << endl;
        return 0;
    }

    cout << ". Writing data errors to file..." << endl;
    if(writer2.writeDataReportFile(reader.getStudentErrorList(),reader.getGradeErrorList(),reader.getDuplicateErrorList()))
        cout << "   Writing data errors completed!" << endl;
    else
        cout << "   Couldn't open file..." << endl;

    cout << ". Making MatchedCourses data from the .csv file..." << endl;
    if (reader.makeMatchedData()) {
        cout << "   Making MatchedCourses completed!" << endl;
        cout << "   MatchedCourses: " << reader.getMatchedCoursesList().size() << endl;
    } else{
        cout << "   Couldn't open " << reader.getFilepath4().tocstr() << endl;
        return 0;
    }

    list<MatchedCourse> matchedCoursesList = reader.getMatchedCoursesList();

    studentsList = reader.getStudentsList();

    cout << ". Finding Errors in data..." << endl;
    for (list<Student>::iterator it=studentsList.begin(); it != studentsList.end(); ++it)
    {
        gradesList = it->getGradesList();

        mystring tmpName = it->getfirstName();
        mystring tmpSName = it->getlastName();
        mystring tmpAM = it->getAm();


        for (list<Grade>::iterator it2=gradesList.begin(); it2 != gradesList.end(); ++it2)
        {
            mystring tmpId = it2->getId();

            float tmpGrade = it2->getGrade();

            mystring oldId;
            mystring oldName;
            mystring newId;
            mystring newName;

            if(tmpId.tocstr()[0] == 'P'){
                matchCourse(tmpId,reader.getMatchedCoursesList(),oldId,oldName,newId,newName);
                errorsList.push_back(Error(tmpAM,tmpName,tmpSName,oldId,oldName,newId,newName,tmpGrade));
            }
        }

        gradesList.clear();
    }

    cout << "   Finding Errors completed!" << endl;
    cout << "   Errors: " << errorsList.size() << endl;

    cout << ". Writing errors to file..." << endl;
    if(writer.writeReportFile(errorsList))
        cout << "   Writing errors completed!" << endl;
    else
        cout << "   Couldn't open file..." << endl;
    return 0;
}

/* Για να δω την αντιστοιχία του μαθήματος χρησιμοποιώ την συνάρτηση matchCourse, στην οποία χρησιμοποιώ αναφορές στα
 * αντικείμενα mystring, για να φτιάξω το κατάλληλο error. Με αυτό τον τρόπο αλλάζω πολλαπλές τιμές με μία συνάρτηση*/

void matchCourse(mystring oldCourse,  list<MatchedCourse> matchedCoursesList,mystring& oldId, mystring& oldName,
                 mystring& newId, mystring& newName) {
    for (list<MatchedCourse>::iterator it=matchedCoursesList.begin(); it!= matchedCoursesList.end(); ++it){
        if(it->getOldId() == oldCourse){
            oldId = it->getOldId();
            oldName = it-> getOldName();
            newId = it-> getNewId();
            newName = it->getNewName();
        }
    }
}