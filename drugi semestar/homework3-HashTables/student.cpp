#include "student.h"

void Student::printStudent(){

    cout<<this->brIndexa<<", "<<this->imePrezime<<", "<<listaPredmeta<< " || ";
//    cout<<"ovde si";

}

Student::Student(int brInd, string imePrez, string sviPred){
    this->brIndexa=brInd;
    this->imePrezime=imePrez;
    this->listaPredmeta=sviPred;

}

unsigned int Student::getBrIndexa() const {
    return brIndexa;
}

Student::~Student() {

}

const string &Student::getImePrezime() const {
    return imePrezime;
}

const string &Student::getListaPredmeta() const {
    return listaPredmeta;
}

Student::Student(const Student *student) {
    this->imePrezime=student->getImePrezime();
    this->listaPredmeta=student->getListaPredmeta();
    this->brIndexa=student->getBrIndexa();
}

Student::Student() {

}

