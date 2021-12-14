#include <iostream>
#include <string>

using namespace std;

double ternarySearch(double* lista, int duz){
    string a;
    int l=0, r=duz-1, m1, m2, brKoraka=0;
    m1=l+(r-l)/3;
    m2=r-(r-l)/3;

    while(r>=l){
        m1=l+(r-l)/3;
        m2=r-(r-l)/3;

        cout<<"Da li je Vas broj jednak "<<lista[m1]<<"?";
        cin>>a;
        brKoraka++;
        if(a=="j"){
            cout<<"Broj koraka je:"<<brKoraka<<endl;
            return lista[m1];
        }
        cout<<"Da li je Vas broj jednak "<<lista[m2]<<"?";
        cin>>a;
        brKoraka++;
        if(a=="j"){
            cout<<"Broj koraka je:"<<brKoraka<<endl;
            return lista[m2];
        }
        cout<< "Da li je Vas broj manji od "<<lista[m1]<<"?";
        cin>>a;
        brKoraka++;
        if(a=="j"){
            r=m1-1;
            continue;
        }
        cout<<"Da li je Vas broj veci od "<<lista[m2]<<"?";
        cin>>a;
        brKoraka++;
        if(a=="j"){
            l=m2+1;
        }
        else{
            l=m1+1;
            r=m2-1;
        }
    }
    return -1;
}

 int main() {
    bool a=true;
    while(a) {
        int izbor;
        cout << "-----Izaberite opciju-----\n"
                "1.Zapocni igru\n"
                "0.Zavrsi program\n";
        cin >> izbor;
        if (izbor == 1) {

            double a, b;
            int duz, br, f = 1;
            double resenje, decimala = 1;
            cout << "Opseg: ";
            cin >> a >> b;
            cout << "Unesite broj decimala: ";
            cin >> br;
            for (int i = 0; i < br; i++)decimala = decimala * 0.1;
            for (int i = 0; i < br; i++)f = f * 10;
            duz = (b - a) * f;
            double *lista = new double[duz];
            double j = (double) a;
            for (int i = 0; i < duz; j += decimala, i++) {
                lista[i] = j;
            }
//     for(int i=0; i<duz; i++)cout<<lista[i]<<" ";
            resenje = ternarySearch(lista, duz);

            if (resenje == -1)cout << "Nema resenja"<<endl;
            else cout << "Resenje: " << resenje<<endl;
        }
        else if(izbor==0)a=false;
        else cout<<"Unesite validan broj"<<endl;
    }
     return 0;

 }
