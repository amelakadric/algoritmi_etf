#include <iostream>
#include <fstream>
#include "tree.h"

// B* tree implemetation 

using namespace std;


int main() {
    Tree stablo= Tree(4);
    stablo.insert("a");
    stablo.insert("c");
    stablo.insert("b");
    stablo.insert("d");


    stablo.insert("e");
    stablo.insert("f");
    stablo.insert("g");
//    stablo.insert("i");
//    //4
//    stablo.insert("d");

//    stablo.insert("i");
//    stablo.insert("j");
    stablo.insert("h");

    cout<<stablo<<endl;
//    cout<<stablo.findKthLeastKey(2);

//    while(true) {
//        cout << "\n----MENI----\n"
//                "1. Napravi stablo\n"
//                "2. Dodaj kljuc\n"
//                "3. Ucitaj iz datoteke\n"
//                "4. Pronadji kljuc\n"
//                "5. Ispisi stablo\n"
//                "6. Obrisi kljuc\n"
//                "7. Pronadji k-ti najmanji kljuc\n"
//                "0. Kraj programa\n";
//
//        int izbor;
//        string s, k;
//        string datIme;
//
//        cin>>izbor;
//        Tree st=Tree(0);
//        switch(izbor) {
//            case 1:
//                int r;
//                cout<<"Unesite red stabla: ";
//                cin>>r;
//                st=Tree(r);
//                break;
//            case 2:
//                cout<<"Unesite kljuc: ";
//                cin>>s;
//                st.insert(s);
//                break;
//            case 3:
//                break;
//            case 4:
//                cout<<"Unesite kljuc: ";
//                cin>>s;
//                if(st.searchKey(s))cout<<"Kljuc postoji u stablu"<<endl;
//                else cout<<"Kljuc ne postoji u stablu"<<endl;
//                break;
//            case 5:
//                cout<<st;
//                break;
//            case 6: {
//                cout << "Unesite ime datoteke: ";
//                cin >> datIme;
//                ifstream file(datIme);
//                while (getline(file, k)) {
//                    if (k == "//")break;
//                    st.insert(k);
//                }
//                file.close();
//                break;
//            }
//            case 7:
//                int c;
//                cout<<"Unesite broj k: ";
//                cin>>c;
//                cout<<c<<"-ti najmanji kljuc je "<<st.findKthLeastKey(c)<<endl;
//                break;
//            case 0:
//                exit(0);
//        }
//    }

    return 0;
}
