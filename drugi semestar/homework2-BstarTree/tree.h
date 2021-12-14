#ifndef DOM2ASP_TREE_H
#define DOM2ASP_TREE_H
#include "node.h"

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Tree {
    int red;
    Node* root=nullptr;
public:
    Tree(int n);
    ~Tree();

    friend class Node;

    bool searchKey(string key);

    friend ostream& operator<<(ostream& os, Tree &t);

    bool insert(string k);
    bool deleteKey(string key);
    string findKthLeastKey(int k);


};



#endif //DOM2ASP_TREE_H
