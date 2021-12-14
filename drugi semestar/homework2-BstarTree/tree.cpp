#include "tree.h"
Tree::Tree(int n) : red(n){

    root= nullptr;

}

ostream &operator<<(ostream &os, Tree &t) {

    if(t.root!= nullptr) t.root->traverse();
    return os;
}


bool Tree::searchKey(string key) {
    if(root==nullptr) return false;
    else{
        if(root->Node::search(key)!= nullptr)return true;
        else return false;
    }
return false;
}

Tree::~Tree() {
//    root->&~Node;
}

bool Tree::insert(string k) {
    if(root== nullptr){
        root=new Node(red, true, true);
        root->kljucevi[0]=k;
        root->br=1;
    }
    else{
        if(root->br==root->maxKeysRoot) {
//            //splitovanje
//            Node *s= new Node(red, false);
//            s.children[0] = root;
//            s.splitChild(0, root);
//            int i = 0;
//            if (s.kljucevi[0] < k) i++;
//            s.children[i]->insertNepun(k);
//
//            root = s;
//            s->parent=root;
            return root->insertPun(k);
        }
        else
           return root->insertNepun(k);

    }
    return false;
}

string Tree::findKthLeastKey(int k) {
    string *niz=new string[100];
    int z=0;
    if(root!= nullptr) root->nadjiKti(niz, z);

    return niz[k-1];
}


