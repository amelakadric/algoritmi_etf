#ifndef ALGORITMI_ETF_STUDENT_H
#define ALGORITMI_ETF_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
    unsigned int brIndexa;
    string imePrezime;
    string listaPredmeta;
public:

    unsigned int getBrIndexa() const;
    Student(int brInd, string imePrez, string sviPred);
    ~Student();

    void printStudent();

};


#endif //ALGORITMI_ETF_STUDENT_H
