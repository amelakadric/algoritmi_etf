#include <iostream>
#include "HashTable.h"
#include "student.h"

using  namespace std;

int main() {
    Student stud1=Student(20110451,"Zeljko Milinkovic","13S052SIS 13S114MUPS 13S111ASP1 13S111ORT1 13S082VS");
    Student stud2=Student(20060089,"Sergej Isic","13S112OS1 13S112ASP2 13S091EJV");
    Student stud3=Student(20200245,"Milijan Jovicevic","13S114MIPS 13S113AOR1 13S032PMT 13S082VS 13S112VD");
    HashTable ht=HashTable(4, 3, 3);
    ht.insertKey(stud1.getBrIndexa(), &stud1);
    ht.insertKey(stud2.getBrIndexa(), &stud2);
    ht.insertKey(stud3.getBrIndexa(), &stud3);

    cout<<ht;
    return 0;
}
