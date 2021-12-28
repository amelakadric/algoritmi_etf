#ifndef ALGORITMI_ETF_HASHTABLE_H
#define ALGORITMI_ETF_HASHTABLE_H
#include <iostream>
#include "student.h"
#include <string>

using namespace std;

enum Type{Full, Empty, NotEmpty, Deleted};

struct StudentNode{
    Student* student;
    enum Type info=Empty;
    StudentNode *next= nullptr, *prev= nullptr;
//    StudentNode(Student *st){
//        student=st;
//        info=NotEmpty;
//    }
};

struct HashNode{
    int size;
    StudentNode* head= nullptr;
    enum Type info;
};

class HashTable {
    int velicina;
    int p, c;
    int brKljuceva=0;
    HashNode* buckets;

public:
    HashTable(int k, int p, int c);
    ~HashTable();

    int HashFunc(int key);

    StudentNode* findKey(int k);
    StudentNode* bucketTraverse(HashNode* b, int k)const;
    bool insertKey( int key, Student *s);
    bool deleteKey(Student* s);
    void clear();
    int keyCount()const;
    int tableSize()const;
    double fillRatio()const;
    friend ostream& operator <<(ostream& os, HashTable &ht);

};


#endif //ALGORITMI_ETF_HASHTABLE_H
