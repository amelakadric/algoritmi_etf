//
// Created by sejo9 on 30.11.2021..
//

#ifndef DOM2ASP_NODE_H
#define DOM2ASP_NODE_H
#include <string>
#include <iostream>
#include <array>


using namespace std;

class Node {

    string *kljucevi;
    Node** children;
    Node* parent= nullptr;
    Node* db= nullptr;
    Node* lb= nullptr;
    bool leaf;
    bool isRoot;

    int br=0;
    int maxChild;
    int minChild;
    int maxKeys;
    int minKeys;
    int maxKeysRoot;
    int maxChildRoot;
    int minChildRoot;
public:
    Node(int n, bool lf, bool rt);
    ~Node();

    void traverse();

    Node* search(string k);

    friend class Tree;

    int findKey(string k);


    bool insertNepun(string k);
    bool insertPun(string k);
    bool splitChild(string k);
    int findCurrInd(Node* parent);
    void nadjiKti(string* niz, int &z);
    bool pun();


};




#endif //DOM2ASP_NODE_H
