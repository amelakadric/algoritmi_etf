#ifndef ALGORITMI_ETF_STUDENT_H
#define ALGORITMI_ETF_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    unsigned int brIndexa;
    string imePrezime;
    string listaPredmeta;

    unsigned int getBrIndexa() const;
    const string &getImePrezime() const;
    const string &getListaPredmeta() const;
    Student();
    Student(int brInd, string imePrez, string sviPred);
    Student(const Student *student);
    ~Student();

    void printStudent();

};


#endif //ALGORITMI_ETF_STUDENT_H
