#include "HashTable.h"

HashTable::HashTable(int k, int p, int c) {
    this->velicina= k*pow(2,p);
    this->p=p;
    this->c=c;
    this->buckets=new HashNode[pow(2,p)];
    for(int i=0; i<pow(2,p); i++){
        this->buckets[i].info=Empty;
        this->buckets[i].size=k;
    }

}

int HashTable::HashFunc(int key) {
    int h=key%(int(pow(2, this->p)));

    return h;
}

bool HashTable::insertKey(int key, Student* s) {
    if(findKey(s->getBrIndexa())!= nullptr) return false;
    int h= HashFunc(key);
    if(this->buckets[h].info==Empty){
        StudentNode* node= new StudentNode(s);
        node->student=s;
        buckets[h].head=node;
        buckets[h].info=NotEmpty;
        this->brKljuceva++;
        if(brKljuceva==buckets[h].size)buckets[h].info=Full;
        return true;
    }
    else if(this->buckets[h].info==NotEmpty){
//        StudentNode node=StudentNode(s);
        StudentNode* node= new StudentNode(s);
        node->student=s;
        StudentNode* tmp=buckets[h].head;
        while(tmp->next!= nullptr)tmp=tmp->next;
        tmp->next=node;
        node->prev=tmp;
        tmp=tmp->next;
        brKljuceva++;
        if(brKljuceva==buckets[h].size)buckets[h].info=Full;
        return true;

    }
    else if(this->buckets[h].info==Full){
        for (int i=0; i<pow(2, this->p); i++){
            int q=(h+i*i*this->c)%(int(pow(2, this->p)));
            if (this->buckets[q].info!=Full){
                //umetanje na novu izracunatu adresu
                if(this->buckets[h].info==Empty){
                    StudentNode* node= new StudentNode(s);
                    node->student=s;
                    buckets[h].head=node;
                    buckets[h].info=NotEmpty;
                    this->brKljuceva++;
                    if(brKljuceva==buckets[h].size)buckets[h].info=Full;
                    return true;
                }
                else if(this->buckets[q].info==NotEmpty){
                    StudentNode* node= new StudentNode(s);
                    node->student=s;
                    StudentNode* tmp=buckets[q].head;
                    while(tmp->next!= nullptr)tmp=tmp->next;
                    tmp->next=node;
                    node->prev=tmp;
                    tmp=node;
                    brKljuceva++;
                    if(brKljuceva==buckets[q].size)buckets[q].info=Full;
                    return true;
                }

            }
        }

    }

    return false;
}

StudentNode* HashTable::findKey(int k) {
    int h= HashFunc(k);
    if( this->buckets[h].info==Empty ) {
        return nullptr;
    }
    else if (this->buckets[h].info==NotEmpty){
        int i=1;
        while(( bucketTraverse(&buckets[h], k))== nullptr){
            h=(h+(i*i* this->c))%(int(pow(2, this->p)));
        }
        return bucketTraverse(&buckets[h], k);
    }
    return nullptr;
}

StudentNode* HashTable::bucketTraverse(HashNode* b, int k) const{
    int i;
    StudentNode* tmp=b->head;
    for(i=0; i<b->size; i++){
        if(tmp) {
            if (tmp->student.getBrIndexa() == k) return tmp;
        }
    }
    return nullptr;
}

bool HashTable::deleteKey(Student* s) {
    int k=s->getBrIndexa();
    int h= HashFunc(k);
    if(this->buckets[h].info==Empty) return false;
    else if (this->buckets[h].info==NotEmpty){
        int i;
        StudentNode* tmp= this->buckets[h].head;
        for(i=0; i<buckets[h].size; i++){
            if(tmp->student.getBrIndexa()==k) {
                tmp->info=Deleted;
                this->brKljuceva--;
                tmp=tmp->next;
                return true;
            }
        }
        return false;
    }
        return false;

}

void HashTable::clear() {
    for(int i=0; i<pow(2,p); i++){
        buckets[i].info=Empty;
        buckets[i].head=nullptr;
    }
}

int HashTable::keyCount()const {
    return this->brKljuceva;
}

int HashTable::tableSize() const{
    return this->velicina;
}

double HashTable::fillRatio() const{
    return double(this->brKljuceva)/this->velicina;
}

ostream &operator<<(ostream &os, HashTable& ht) {
    int i;
    for(i=0; i<pow(2, ht.p); i++){
        if(ht.buckets[i].info==Empty){
            cout<<"Empty"<<endl;
            continue;
        }
        StudentNode* tmp=ht.buckets[i].head;
        for (int j = 0; j < ht.buckets[i].size; j++) {
            if(tmp){
                if(tmp->info==Deleted){
                    cout<<"DELETED ";
                    tmp=tmp->next;
                    continue;
                }
                tmp->student.printStudent();
                tmp = tmp->next;
                }
            else
                break;
        }
        cout<<endl;
    }

    return os;
}

HashTable::~HashTable() {

}





