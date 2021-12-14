#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <stack>

// binary search tree implementation 

using namespace std;

struct Node{
    string key;
    string info;
    int ponavljanje;
    struct Node *left, *right, *parent;

    Node(string key, string info){
        this->key=key;
        this->info=info;
        this->left=this->right= this->parent= nullptr;
        this->ponavljanje=1;
    }
};

//definisanje funkcija
struct Node* formTree();
int getLevel(struct Node* s);
void printTree(struct Node* root);
string* findKey(struct Node* root, string k);
struct Node* insert(struct node* root, string k, string i);
struct Node* deleteKey(struct Node* root, string k);
struct Node* deleteNode(struct Node* root, string k);
void deleteTree(struct Node* &root);
string maxTrans(struct Node* root);

//funkcije
struct Node* formTree() {
    int izbor;
    string k, i, m;
    struct Node *root = nullptr, *q = root, *p, *r;
    cout<<"1. Unos sa standardnog ulaza\n"
          "2. Unos iz datoteke\n";
    cin>>izbor;
    if(izbor==1){
        getline(cin, m);
        cout << "Unesite rec i prevod, za kraj unosa unesite '//' : ";

        while (getline(cin, k)) {
            if (k == "//") break;
            getline(cin, i);
            q = root;
            if (root == nullptr) {
                root = new Node(k, i);
            } else {
                while (q != nullptr) {
                    if (k < q->key) {
                        r = q;
                        q = q->left;
                    } else if (k == q->key) {
                        while (q != nullptr) {
                            if (k == q->key) {
                                r = q;
                                q->ponavljanje++;
                                q = q->right;
                            } else break;
                        }
                        p = new Node(k, i);
                        p->ponavljanje = r->ponavljanje;
                        p->left = r->left;
                        p->right = r->right;
                        p->parent = r;
                        r->left = nullptr;
                        r->right = p;
                        break;
                    } else {
                        r = q;
                        q = q->right;
                    }
                }
                q = new Node(k, i);
                q->parent = r;
                if (q->key < r->key)r->left = q;
                else r->right = q;
            }
        }
    }
    else if(izbor==2){
        string nameOfFile;
        cout<<"Unesite ime datoteke: ";
        cin >>nameOfFile;
        ifstream file(nameOfFile);
        while (getline(file, k)) {
            if (k =="//") break;
            getline(file, i);
            q = root;
            if (root == nullptr) {
                root = new Node(k, i);
            } else {
                while (q != nullptr) {
                    if (k < q->key) {
                        r = q;
                        q = q->left;
                    } else if (k == q->key) {
                        while (q != nullptr) {
                            if (k == q->key) {
                                r = q;
                                q->ponavljanje++;
                                q = q->right;
                            } else break;
                        }
                        p = new Node(k, i);
                        p->ponavljanje = r->ponavljanje;
                        p->left = r->left;
                        p->right = r->right;
                        p->parent = r;
                        r->left = nullptr;
                        r->right = p;
                        break;
                    } else {
                        r = q;
                        q = q->right;
                    }
                }
                q = new Node(k, i);
                q->parent = r;
                if (q->key < r->key)r->left = q;
                else r->right = q;
            }
        }
        file.close();
    }
    else cout<<"Nevalidan broj!";
    return root;
}
int getLevel(struct Node* s){
    int level=0;
    struct Node* p=s->parent;
    while (p){
        level++;
        p=p->parent;
    }
    return level;
}
void printTree(struct Node* root){
    if(!root){cout<<"Nema stabla";return;}
    int b=getLevel(root);
    string razmak="";
    while(b){razmak+="  "; b--;}
    string t="/";
    string prefiks=razmak+(root->parent? "|__": "");
    string r=root->key+t+root->info;
    string str="";
    if(root->parent){
        struct Node* p=root->parent;
        if(root==p->left) str="1";//levi sin
        else str="2";//desni sin
    }
    cout<<prefiks<<r<<t+str<<endl;
    if(root->left!= nullptr){
        printTree(root->left);
    }
    if(root->right!= nullptr){
        printTree(root->right);
    }
}
string* findKey(struct Node* root, string k){
    string lista[10];
    int duz=0;
    struct Node* p=root;
    while(p!=nullptr){
        if(p->key==k){
            lista[duz++]=p->info;
            p=p->right;
        }
        else if(k < p->key){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    for(int i=0; i<duz; i++){
        cout<<lista[i]+" ";
    }
    cout<<endl;
    return lista;
}
void printFoundKeys(string* lista){
    for (int i=0; i<10; i++){
        if(lista[i]!="") cout<<lista[i];
        else break;
    }

}
struct Node* insert(struct Node* root, string k,string i){
    struct Node *p=root, *q=nullptr;
    while(p!= nullptr){
        q=p;
        if(k==p->key){
            struct Node *next= nullptr;
            next=new Node(k, i);
            next->right=p->right;
            next->left=p->left;
            p->ponavljanje++;
            p->right=next;
            p->left= nullptr;
            next->ponavljanje=p->ponavljanje;
            next->parent=p;
            if(next->left!= nullptr)next->left->parent=next;
            if(next->right!= nullptr)next->right->parent=next;

            return root;
        }
        else {
            if(k<p->key) p=p->left;
            else p=p->right;
        }
    }
    if(q==nullptr) {
        root= new Node(k, i);
    }
    else {
        if(k<q->key){
            struct Node* next;
            next=new Node(k, i);
            q->left=next;
            next->parent=q;
        }
        else{
            struct Node* next;
            next=new Node(k, i);
            q->right=next;
            next->parent=q;
        }
    }
    return root;
}
struct Node* deleteKey(struct Node* root, string k){
    struct Node *p=root, *q= nullptr;
    while(p!= nullptr && k!=p->key){
        q=p;
        if(k<p->key){
            p=p->left;
        }
        else
            p=p->right;
    }
    if(p==nullptr){
        cout<<"Nema trazenog kljuca!"<<endl;
        return root;
    }
    int b=p->ponavljanje;
    for(int i=0; i<b; i++){
        root=deleteNode(root, k);
    }
    return root;
}
struct Node* deleteNode(struct Node* root, string k){
    struct Node *p=root, *q= nullptr;
    while(p!= nullptr && k!=p->key){
        q=p;
        if(k<p->key){
            p=p->left;
        }
        else
            p=p->right;
    }
    if(p==nullptr){
        cout<<"Nema trazenog kljuca!"<<endl;
        return root;
    }
    struct Node* rp;
    if(p->left==nullptr){
        rp=p->right;
    }
    else {
        if(p->right== nullptr){
            rp=p->left;
        }
        else {
            struct Node *f = p;
            rp = p->right;
            struct Node* s=rp->left;
            while(s!= nullptr){
                f=rp;
                rp=s;
                s=rp->left;
            }
            if(f!=p){
                f->left=rp->right;
                rp->right=p->right;
            }
            rp->left=p->left;
        }
    }
    if(q==nullptr){
        root=rp;
    }
    else {
        if(p==q->left){
            q->left=rp;
            if(rp)rp->parent=q;
        }
        else {
            q->right = rp;
            if(rp)rp->parent = q;
        }
    }
    delete p;
    return root;
}
void deleteTree(struct Node* &root)
{
    if (root == nullptr) {
        return;
    }
    queue <struct Node*> queue;
    queue.push(root);
    Node* front = nullptr;
    while (!queue.empty())
    {
        front = queue.front();
        queue.pop();
        if (front->left) {
            queue.push(front->left);
        }
        if (front->right) {
            queue.push(front->right);
        }
        delete front;
    }
    root = nullptr;
}
string maxTrans(struct Node* root){
    //inorder obilazak
    stack<struct Node*> stack;
    int max=0;
    string maxStr;
    struct Node* next=root;
    while(true){
        while(next!= nullptr){
            stack.push(next);
            next=next->left;
        }
        if(!stack.empty()){
            next=stack.top();
            stack.pop();
            if(next->ponavljanje>max) {
                max=next->ponavljanje;
                maxStr=next->key;
            }
            next=next->right;
        }
        else {
            if (max == 1) maxStr = root->key;
            return maxStr;
        }
    }
}


int main() {
    struct Node* root;
    bool b=true;
    while(b){
        cout << "----Izaberite opciju----\n"
                "1.Formiraj stablo\n"
                "2.Ispisi stablo\n"
                "3.Pronadji kljuc\n"
                "4.Dodaj cvor\n"
                "5.Izbrisi cvor\n"
                "6.Nadji rec sa najvecim brojem prevoda\n"
                "7.Izbrisi stablo\n"
                "0.Zavrsi rad\n";
        int a;
        string i, j, k, m, n;
        string* lista;
        cin >> a;
        switch(a){
            case 1:
                root=formTree();
                break;
            case 2:
                printTree(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Unesite kljuc koji trazite: ";
                cin >> n;
                lista= findKey(root,n);
                for(int br=0; br<100; br++){
                    if(lista[br]!="")cout<<lista[br]<<" ";
                    else break;
                }
                break;
            case 4:
                cout<<"Unesite rec i prevod: ";
                cin >> k >> i;
                root=insert(root, k, i);
                printTree(root);
                break;
            case 5:
                cout<<"Unesite kljuc koji zelite da izbrisete: ";
                cin >> j;
                root=deleteKey(root, j);
                printTree(root);
                break;
            case 6:
                m= maxTrans(root);
                printTree(root);
                cout<<m<<endl;
                break;
            case 7:
                deleteTree(root);
                break;
            case 0:
                b=false;
                break;
            default:
                cout<<"Unesite ispravan broj!\n";
                break;
        }
    }
    return 0;
}