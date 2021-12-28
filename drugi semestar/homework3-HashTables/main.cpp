#include <iostream>
#include "HashTable.h"
#include "student.h"
#include <fstream>
#include <string>

using  namespace std;

void readFile(char* name, int k, int p, int c){
    HashTable ht=HashTable(4, 3, 3);
    char tekst [256];
    FILE* file;
    int tmp;
    char tmpStr1[100], tmpStr2[100];
    file=fopen( name, "r");

    fscanf(file, "%s\n", tekst);

    while(fscanf(file, "%d,%[^,],%[^\n]\n", &tmp, tmpStr1, tmpStr2)>=1){
        std::string t1(tmpStr1);
        std::string t2(tmpStr2);
//        cout<<t1;
        Student stud=new Student(tmp, t1, t2);
//        Student stud=Student(tmp, t1, t2);
//        stud.printStudent();
//        cout<<endl;
        ht.insertKey(stud.getBrIndexa(), &stud);
        strcpy(tmpStr2, "");
    }

    fclose(file);

    cout<<ht;

}

int main() {
//    Student stud1=Student(20110451,"Zeljko Milinkovic","13S052SIS 13S114MUPS 13S111ASP1 13S111ORT1 13S082VS");
//    Student stud2=Student(20060089,"Sergej Isic","13S112OS1 13S112ASP2 13S091EJV");
//    Student stud3=Student(20200245,"Milijan Jovicevic","13S114MIPS 13S113AOR1 13S032PMT 13S082VS 13S112VD");
//    Student stud4=Student(19980735,"Milijan Mako","13S074IOA 13S042ODE 13S113AOR1 13S114PP1 13S114MIPS");
//    Student stud5=Student(19960486,"Luka Urosevic","");
//    HashTable ht=HashTable(4, 3, 3);
//    ht.insertKey(stud1.getBrIndexa(), &stud1);
//    ht.insertKey(stud2.getBrIndexa(), &stud2);
//    ht.insertKey(stud3.getBrIndexa(), &stud3);
//    ht.insertKey(stud4.getBrIndexa(), &stud4);
//    ht.insertKey(stud5.getBrIndexa(), &stud5);
//    cout<<ht<<endl;




//    readFile("students_5.csv", 0, 0, 0);
//    cout<<"ovde si";

HashTable ht=HashTable(0, 0, 0);
    while(true){
        cout << "\n----MENI----\n"
                "1. Napravi tabelu\n"
                "2. Dodaj kljuc\n"
                "3. Pronadji kljuc\n"
                "4. Izbrisi kljuc\n"
                "5. Isprazni tabelu\n"
                "6. Ispisi tabelu\n"
                "7. Broj kljuceva\n"
                "8. Velicina tabele\n"
                "9. Popunjenost\n"
                "0. Kraj programa\n";

        int izbor, iz;
        int k, p, c;
        cin>>izbor;
        string str1, str2, str3;
        switch (izbor) {
            case 1:
                cout<<"1.Unos iz terminala\n"
                      "2.Unos iz datoteke\n";
                cin>>iz;
                if(iz==1){
                    cout<<"Parametri tabele: ";
                    cin>>k>>p>>c;
                    ht=HashTable(k, p, c);

                }
                else{
                    char* name;
                    cout<<"Ime datoteke: ";
                    cin>>name;
                    cout<<"Parametri tabele: ";
                    cin>>k>>p>>c;
                    readFile(name, k, p, c);
                }
                break;
            case 2:
            {
                cout<<"Unesite kljuc: ";
                cin>>k;
                cout<<"Unesite ime i prezime: ";
                cin>>str1;
                cout<<"Unesite listu predmeta: ";
                cin>>str2;
                Student stu=Student(k, str1, str2);

                ht.insertKey(k, &stu);}

                break;
            case 3:
                cout<<"Unesite kljuc: ";
                cin>>k;
                cout<<ht.findKey(k);
                break;
            case 4: {
                cout << "Unesite kljuc: ";
                cin >> k;
                Student s = new Student(k, "", "");
                ht.deleteKey(&s);
                break;
            }
            case 5:
                ht.clear();
                cout<<"Tabela je ispraznjena";
                break;
            case 6:
                cout<<ht;
            case 7:
                cout<<"Broj kljuceva: "<<ht.keyCount();
                break;
            case 8:
                cout<<"Velicina tabele: "<<ht.tableSize();
                break;
            case 9:
                cout<<"Popunjenost: "<<ht.fillRatio();
                break;
            case 0:
                exit(1);
                break;


        }
    }

    return 0;
}
