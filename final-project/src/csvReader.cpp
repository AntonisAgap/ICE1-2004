#include "csvReader.h"
#include "myString.h"


CsvReader::CsvReader (mystring _filePath1,mystring _filePath2,mystring _filePath3,mystring _filePath4)
{
    filePath1 = _filePath1;
    filePath2 = _filePath2;
    filePath3 = _filePath3;
    filePath4 = _filePath4;
}

CsvReader::CsvReader (const CsvReader &CR)
{
    filePath1 = CR.filePath1;
    filePath2 = CR.filePath2;
    filePath3 = CR.filePath3;
    filePath4 = CR.filePath4;
    studentsList = CR.studentsList;
    coursesList = CR.coursesList;
    matchedCoursesList = CR.matchedCoursesList;

}


bool CsvReader::courseIdExists(mystring courseId) {
    bool exists = false;
    for (list<Course>::iterator it=coursesList.begin(); it != coursesList.end(); ++it)
    {
        if (courseId == it->getId()) {
            exists = true;
        }
    }
    return exists;
}

bool CsvReader::checkIfDuplicate(mystring courseId, list<Grade> gradesList) {
    bool exists = false;
    for (list<Grade>::iterator it=gradesList.begin(); it != gradesList.end(); ++it)
    {
        if(courseId == it->getId()){
            exists = true;
        }

    }
    return exists;
}

/* Για να διαβάσω το αρχείο .csv χρησιμοποιώ την getline(). Με την οποία παίρνω κάθε γραμμή του αρχείου. Έπειτα διαβάζω
 * κάθε χαρακτήρα της γραμμής, και ανάλογα το flag,το οποίο αντιπροσωπεύει την λέξη που διαβάζουμε κάνω append τον
 * χαρακτήρα στο κατάλληλο αντικείμενο mystring. Μόλις εξάγουμε τις λέξεις από την γραμμή, φτιάχνουμε το κατάλληλο
 * αντικείμενο (πχ Student) και το αποθηκεύουμε στην κατάλληλα λίστα αυτών των αντικειμένων. Στην συνέχεια αρχικοποιώ
 * την flag και "μηδενίζω" τα mystring για να φτιάξω τις λέξεις της επόμενης γραμμής. */

bool CsvReader::makeStudentsData(){

    char line[1000];
    mystring wordToken1;
    mystring wordToken2;
    mystring wordToken3;
    int flag = 1;
    ifstream file(filePath1.tocstr(),ios::in);

    if(!file.is_open()){
        return false;
    }

    file.getline(line,1000,'\n'); // reading headers

    while( file.good() ){

        file.getline(line,1000,'\n');

        for (int i=0; i<strlen(line); i++){
            if(line[i] == ','){
                flag++;
            }else{
                if (flag == 1){
                    wordToken1+=line[i];
                }else if(flag == 2){
                    wordToken2+=line[i];
                }else if(flag == 3){
                    wordToken3+=line[i];
                }
            }
        }


        studentsList.push_back(Student(wordToken1,wordToken2,wordToken3));

        wordToken1="";
        wordToken2="";
        wordToken3="";
        flag = 1;
    }

    file.close();
    return true;
}

bool CsvReader::makeCoursesData(){

    char line[1000];
    mystring wordToken1;
    mystring wordToken2;
    int flag = 1;
    ifstream file(filePath2.tocstr(),ios::in);

    if(!file.is_open()){
        return false;
    }

    file.getline(line,1000,'\n'); // reading headers


    while( file.good() ){

        file.getline(line,1000,'\n');

        for (int i=0; i<strlen(line); i++){
            if(line[i] == ','){
                flag++;
            }else{
                if (flag == 1){
                    wordToken1+=line[i];
                }else if(flag == 2){
                    wordToken2+=line[i];
                }
            }
        }


        coursesList.push_back(Course(wordToken1,wordToken2));

        wordToken1="";
        wordToken2="";
        flag = 1;
    }

    file.close();
    return true;

}


/* Στην μέθοδο makeGradesData διαβάζω μια γραμμή του .csv αρχείου και αρχικά κοιτάω εάν ο κωδικός του μαθήματος
 * υπάρχει,εάν δεν υπάρχει φτιάχνει το κατάλληλο error. Εάν υπάρχει ψάχνει τον φοιτητή, του οποίου ανήκει ο βαθμός. Εάν
 * δεν βρεί τον φοιτητή, σημαίνει πως δεν υπάρχει ο φοιτητής και φτιάχνει το κατάλληλο error. Εάν υπάρχει ο φοιτητής
 * κοιτάει με βάση την λίστα των βαθμών του,εάν έχει ξαναπεραστεί ο βαθμός. Εάν έχει ξαναπεραστεί φτιάχνει το κατάλληλο
 * error. Εάν δεν έχει ξαναπεραστεί, εισάγει το αντικείμενο grade στον κατάλληλο φοιτητή.*/

bool CsvReader::makeGradesData(){
    char line[1000];
    mystring wordToken1;
    mystring wordToken2;
    mystring wordToken3;
    mystring wordToken4;
    mystring wordToken5;
    mystring wordToken6;

    int flag = 1;
    ifstream file(filePath3.tocstr(),ios::in);
    float grade;

    if(!file.is_open()){
        return false;
    }

    file.getline(line,1000,'\n'); // reading headers

    while( file.good() ){

        file.getline(line,1000,'\n');

        for (int i=0; i<strlen(line); i++){
            if(line[i] == ','){
                flag++;
            }else{
                if (flag == 1){
                    wordToken1+=line[i];
                }else if(flag == 2){
                    wordToken2+=line[i];
                }else if(flag == 3){
                    wordToken3+=line[i];
                }else if(flag == 4){
                    wordToken4+=line[i];
                }else if(flag == 5){
                    wordToken5+=line[i];
                }else if(flag == 6){
                    wordToken6+=line[i];
                }
            }
        }

        // Converting grade of student from char array to float
        grade = (float)atof(wordToken6.tocstr());
		
		int studentExists = 0;

		if (courseIdExists(wordToken5)) {

            for (list<Student>::iterator it = studentsList.begin(); it != studentsList.end(); ++it) {
                if (wordToken4 == it->getAm()) {
                    studentExists = 1;
                    if (checkIfDuplicate(wordToken5,it->getGradesList())){
                        duplicateErrorList.push_back(wordToken5);
                    } else{
                        it->insertGrade(Grade(wordToken1,wordToken2,wordToken3,wordToken5, grade));
                    }
                }

            }

            if (studentExists == 0) {
                studentErrorList.push_back(wordToken4);
            }
        } else
        {
		    gradeErrorList.push_back(wordToken5);
        }

        wordToken1="";
        wordToken2="";
        wordToken3="";
        wordToken4="";
        wordToken5="";
        wordToken6="";
        flag = 1;
    }
    file.close();
    return true;
}


bool CsvReader::makeMatchedData(){

    char line[1000];
    mystring wordToken1;
    mystring wordToken2;
    mystring wordToken3;
    mystring wordToken4;

    int flag = 1;
    ifstream file(filePath4.tocstr(),ios::in);

    if(!file.is_open()){
        return false;
    }

    file.getline(line,1000,'\n'); // reading headers

    while( file.good() ){

        file.getline(line,1000,'\n');
		
        for (int i=0; i<strlen(line); i++){
            if(line[i] == ','){
                flag++;
            }else{
                if (flag == 1){
                    wordToken1+=line[i];
                }else if(flag == 2){
                    wordToken2+=line[i];
                }else if(flag == 3){
                    wordToken3+=line[i];
                }else if(flag == 4){
                    wordToken4+=line[i];
                }
            }
        }

        matchedCoursesList.push_back(MatchedCourse(wordToken1,wordToken2,wordToken3,wordToken4));

        wordToken1="";
        wordToken2="";
        wordToken3="";
        wordToken4="";
        flag = 1;
    }

    file.close();
    return true;
}