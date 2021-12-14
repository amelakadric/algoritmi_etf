#include "node.h"



Node::Node(int n, bool lf, bool rt) {
    minKeys=((2*n-1)/3)-1;
    maxKeys=n-1;
    maxChild=n;
    minChild=(2*n-1)/3;
    minChildRoot=2;
    maxChildRoot=(2*(2*n-2)/3)+1;
    maxKeysRoot=2*(2*n-2)/3;
    leaf=lf;
    isRoot=rt;
    kljucevi=new string [maxKeysRoot];
    children=new Node*[n];
    br=0;
}

void Node::traverse() {
    int i;
    for(i=0; i<br; i++){
        if(!leaf) children[i]->traverse();
        cout<<" "<< kljucevi[i];
    }
    cout<<"|";
    if(!leaf)

        children[i]->traverse();
}

Node *Node::search(string k) {
    int i=0;
    while (i<br && k>kljucevi[i]) i++;

    if(kljucevi[i]==k) return this;

    if(leaf) return nullptr;

    return children[i]->search(k);
}
Node::~Node() {
//    int i;
//    for(i=0; i<br; i++;){
//        if(!leaf) children[i]->Node::~Node();
//        delete kljucevi[i];
//    }
//    if(!leaf)
//        children[i]->Node::~Node();
}
int Node::findKey(string k) {
    int i=0;
    while(i<br && kljucevi[i]<k){
        ++i;
    }
    return i;
}


bool Node::insertNepun(string k) {
    int i=br-1;
    if(leaf){
        while(i>=0 && kljucevi[i]>=k){
            if (kljucevi[i]==k)return false;
            kljucevi[i+1]=kljucevi[i];
            i--;
        }
        kljucevi[i+1]=k;
        br++;
        return true;
    }
    else{
        while (i >= 0 && kljucevi[i] >= k){
            if (kljucevi[i]==k)return false;
            i--;
        }

        if(children[i+1]->br==children[i+1]->maxKeys){

            return children[i+1]->insertPun(k);
        }
        else {

            return children[i+1]->insertNepun(k);
        }

    }
}
int Node::findCurrInd(Node* par){
//    int max, i;
//    bool f=true;
//    if(par->parent==nullptr)max=par->maxChildRoot;
//    else max=par->maxChild;
//    cout<<par->br;
//    for(i=0; i<par->br; i++){
//        if(par->children[i]==this){
//            return i;
//        }
//    }
//    return -1;
    int i=par->br-1;
    while (i >= 0 && par->kljucevi[i] >= this->kljucevi[0]){
        i--;
    }

    return i;

}
bool Node::pun() {
    if (this->br==this->maxKeys) return true;
    else return false;
}

bool Node::insertPun(string k) {
    if(leaf) {
        if (isRoot) this->splitChild(k);
        else{

            int currInd=this->findCurrInd(parent);
            int m;
            //ima desnog brata
            if (parent->isRoot)m=parent->maxChildRoot;
            else m=parent->maxChild;

            if (db && (!db->pun())){

                //desni brat prelivanje
                array<string, 100>niz;
                int i=0, size;
                for(int p=0; p<this->br; p++){
                    niz[i++]=this->kljucevi[p];
                }
                niz[i++]=k;
                niz[i++]=parent->kljucevi[currInd];
                Node* desnibrat=db;
                for(int p=0; p<desnibrat->br; p++){
                    niz[i++]=desnibrat->kljucevi[p];
                }
                size=i;
                //uredjivanje niza;
                for (int j=0; j<(size-1); j++){
                    for(int l=j; l<size; l++){
                        if (niz[l]< niz[j]){
                            string tmp=niz[l];
                            niz[l]=niz[j];
                            niz[j]=tmp;
                        }
                    }
                }
                //pronalazenje sredisnjeg;
                int sr=((size+1)/2)-1;
                for(int p=0; p<sr; p++){
                    kljucevi[p]=niz[p];
                }
                parent->kljucevi[currInd]=niz[sr++];
                desnibrat->br=0;
                for(int p=0; sr<size; p++){
                    desnibrat->kljucevi[p]=niz[sr++];
                    desnibrat->br++;
                }
                return true;
            }//nema desnog brata ili je on pun
            else if((lb) && (!lb->pun())){

                //levi brat prelivanje
//                int ma=2*maxKeys+2
                array<string, 100>niz;
                int i=0, size;
                Node* levibrat=lb;

                for(int p=0; p<levibrat->br; p++){
                    niz[i++]=levibrat->kljucevi[p];
                }

                niz[i++]=k;
                if(currInd==m)currInd--;
                niz[i++]=parent->kljucevi[currInd];


                for(int p=0; p<this->br; p++){
                    niz[i++]=this->kljucevi[p];
                }
                size=i;

                //uredjivanje niza;
                for (int j=0; j<size-1; j++){
                    for(int l=j; l<size; l++){
                        if (niz[l]<niz[j]){
                            string tmp=niz[l];
                            niz[l]=niz[j];
                            niz[j]=tmp;
                        }
                    }
                }

                //pronalazenje sredisnjeg;
                int sr=((size+1)/2)-1;
                levibrat->br=0;
                for(int p=0; p<sr; p++){
                    levibrat->kljucevi[p]=niz[p];
                    levibrat->br++;
                }

                parent->kljucevi[currInd]=niz[sr++];
                this->br=0;
                for(int p=0; sr<size; p++){
                    kljucevi[p]=niz[sr++];
                    this->br++;
                }
                return true;
            }
            else {
                return splitChild(k);
            }

        }
    }
    else{

        int i=maxKeys-1;
        while ( i >= 0 && kljucevi[i] >= k ){
            if (kljucevi[i]==k)return false;
            i--;
        }

        if(children[i+1]->br==maxKeys){
            return children[i+1]->insertPun(k);
        }
        else return children[i+1]->insertNepun(k);
    }
    return false;
}

bool Node::splitChild(string k) {
    if (isRoot) {
        Node *noviKoren = new Node(maxChild, true, false);
        Node *desnodete=new Node(maxChild, true, false);
        array<string, 120>niz;
        int i=0, size=0;
        for(int p=0; p<this->br; p++){
            niz[i++]=this->kljucevi[p];
        }
        niz[i++]=k;
        size=i;
        //uredjivanje niza
        for (int j=0; j<(size-1); j++){
            for(int l=j; l<(size); l++){
                if (niz[l]<niz[j]){
                    string tmp=niz[l];
                    niz[l]=niz[j];
                    niz[j]=tmp;
                }
            }
        }
        //pronalazenje sredisnjeg;

        int sr=((size+1)/2)-1;
//        cout<<sr;

        this->kljucevi[0]=niz[sr];
        for(int f=1; f<br; f++)kljucevi[f]="";
        this->br=1;
        this->children[0]=noviKoren;
        this->children[1]=desnodete;
        this->leaf=false;
        noviKoren->parent=this;
        noviKoren->db=desnodete;
        desnodete->parent=this;
        desnodete->lb=noviKoren;

        for(int p=0; p<sr; p++){
            noviKoren->kljucevi[p]=niz[p];
            noviKoren->br++;
        }
        sr++;
        for(int p=0; sr<size; p++) {
            desnodete->kljucevi[p] = niz[sr++];
            desnodete->br++;
        }
//        Node* tmp=this;
//        this=noviKoren;
//        noviKoren=tmp;
        return true;
    }
    else{
        //nije koren nego su braca puna
        int currInd= findCurrInd(parent);
        int m, size;


        if (parent->isRoot)m=parent->maxChildRoot;
        else m=parent->maxChild;
        if(!db){
            //splituje se preko levog brata
//            currInd--;//ovo je sad indeks u kljucu;
            int n=maxKeys*2+2;
            array<string, 100>niz;
            Node* levibrat=lb;
            int i=0;
            for(int p=0; p<levibrat->br; p++){
                niz[i++]=levibrat->kljucevi[p];
            }

            niz[i++]=parent->kljucevi[currInd];
            niz[i++]=k;

            for(int p=0; p<br; p++){
                niz[i++]=kljucevi[p];
            }

            size=i;
            //uredjivanje niza
            for (int w=0; w<(i-1); w++){
                for(int l=w; l<i; l++){
                    if (niz[l]<niz[w]){
                        string tmp=niz[l];
                        niz[l]=niz[w];
                        niz[w]=tmp;
                    }
                }

            }

            //pronalazenje 2 za u koren i rasporedjivanje ostalih po novim cvorovima
            int prvi=(2*maxChild-2)/3;
            int drugi=(2*maxChild-1)/3;
            int treci=(2*maxChild)/3;
            i=0;
            levibrat->br=0;
            for (int j=0; j<prvi; j++){
                levibrat->kljucevi[j]=niz[i++];
                br++;
            }
            string strJedan=niz[i++];
            this->br=0;
            this->children[0]=levibrat;
            this->isRoot=true;
            this->kljucevi[0]=strJedan;
            this->br++;
            levibrat->parent=this;

            Node* noviCvor=new Node(maxChild, true, false);
            for (int j=i; j<drugi; j++){
                noviCvor->kljucevi[j]=niz[i++];
                noviCvor->br++;
            }
            string strDva=niz[i++];
            this->kljucevi[1]=strDva;
            this->br++;
            this->children[1]=noviCvor;

            Node* desnibrat=new Node(maxChild, true, false);
            for (int j=0; j<treci; j++){
                desnibrat->kljucevi[j]=niz[i++];
                desnibrat->br++;
            }

            noviCvor->parent=this;
            noviCvor->lb=levibrat;
            levibrat->db=noviCvor;
            desnibrat->lb=noviCvor;
            noviCvor->db=desnibrat;
//            parent->kljucevi[currInd]=strJedan;
            if(parent->br==m){
                return parent->insertPun(strDva);
            }
            else return parent->insertNepun(strDva);

        }
        else{
//            int n=maxKeys*2+2;
            array<string, 100>niz;
            Node* desnibrat=parent->children[currInd+1];
            int i=0, size;
            for(int p=0; p<br; p++){
                niz[i++]=kljucevi[p];
            }
            niz[i++]=k;
            niz[i++]=parent->kljucevi[currInd];
            for(int p=0; p<desnibrat->br; p++){
                niz[i++]=desnibrat->kljucevi[p];
            }
            size=i;
            //uredjivanje niza
            for (int j=0; j<(size-1); j++){
                for(int l=j; l<size; l++){
                    if (niz[l]<niz[j]){
                        string tmp=niz[l];
                        niz[l]=niz[j];
                        niz[j]=tmp;
                    }
                }
            }
            //pronalazenje 2 za u koren i rasporedjivanje ostalih po novim cvorovima
            int prvi=(2*maxChild-2)/3;
            int drugi=(2*maxChild-1)/3;
            int treci=(2*maxChild)/3;
            i=0;
            this->br=0;
            for (int j=0; j<prvi; j++){
                this->kljucevi[j]=niz[i++];
                br++;
            }
            string strJedan=niz[i++];
            Node* noviCvor=new Node(maxChild, true, false);
            for (int j=i; j<drugi; j++){
                noviCvor->kljucevi[j]=niz[i++];
                noviCvor->br++;
            }
            string strDva=niz[i++];
            desnibrat->br=0;
            for (int j=i; j<treci; j++){
                desnibrat->kljucevi[j]=niz[i++];
                desnibrat->br++;
            }
            parent->children[currInd+1]=noviCvor;
            parent->children[currInd+2]=desnibrat;
            noviCvor->parent=parent;
            noviCvor->lb=this;
            this->db=noviCvor;
            desnibrat->lb=noviCvor;
            noviCvor->db=desnibrat;

            parent->kljucevi[currInd]=strJedan;
            if(parent->br==m){
                return parent->insertPun(strDva);
            }
            else return parent->insertNepun(strDva);
        }

    }

    return false;

}
void Node::nadjiKti(string* niz, int &z) {
    int i;
    for(i=0; i<br; i++){
        if(!leaf) children[i]->nadjiKti(niz, z);
        niz[z++]=kljucevi[i];
    }
    if(!leaf)
        children[i]->nadjiKti(niz, z);
}


