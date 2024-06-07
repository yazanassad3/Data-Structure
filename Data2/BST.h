#pragma once
#include <iostream>
using namespace std;

struct node {
    node* right, * left;
    int data;
    node(int el, node* l = 0, node* r = 0) {
        right = r;
        left = l;
        data = el;
    }
};

class BST {
    node* root;
    bool add(int el, node*& r);
    void pre(node* r);
    void in(node* r);
    void post(node* r);
    int size(node* r);
    //int pleft(node* r);
    //int pright(node* r);
    bool search(int el, node* r);
    void delete_tree(node*& r);
    void copy(node* r);
    int min_bst(node *r);
    int sum_of_internal(node *l ,node *r);

    //void copy(BST& o);
    //bool checkBST(node *r);
    //bool checkbst(node* r);
public:
    BST();
    int min_bst();
    int height(node* r);
    bool add(int el);
    void  preorder();
    void  inorder();
    void  postorder();
    int sum_of_internal();

    int size();
    node* getroot();
    //bool checkBST(BST bst);
    void height();
    bool search(int el);
    void delete_tree();
    ~BST();
    BST(BST& o);
    //void operator=(tree &o);
};

// sum of internal:
int BST::sum_of_internal() {
    return BST::sum_of_internal(root->left,root->right);
}
int  BST::sum_of_internal(node* l,node *r ) {
    if (r== 0)
        return 0;
    /*if (r->right == 0)
        return r->left->data;
    if (r->left == 0)
        return r->right->data;
    */
    return sum_of_internal(l->left,l->right)+ sum_of_internal(r->left, r->right)+l->data +r->data;
}


///  minimum data no. in tree
int BST::min_bst() {
    return min_bst(root);
}
int  BST::min_bst(node* r) {
    if (r == 0)
        return 0;
    if (r->left == 0)
        return r->data;
    min_bst(r->left);
}
node* BST::getroot() {
    return root;
}
bool checkbst(node* r) {
    if (r == 0)
        return true;
    if(r->left < r->right) {
        
        return true;

    }
    if (r->left > r->right) {
        return false;
    }
}

void BST::postorder() {
    return post(root);
}
void BST::post(node *r) {
    if (r != 0) {
        post(r->left);
        post(r->right);
        cout << r->data<<" ";
    }
}


bool checkBST(BST bst) {
   
    return checkbst(bst.getroot());

}


BST::BST(BST& o) {
    node* o1 = o.root;
    copy(o1);
}
void BST::copy(node* o1) {
    if (o1 != 0) {
        add(o1->data);
        copy(o1->left);
        copy(o1->right);
    }

}

//~destructor function
BST::~BST() {
    delete_tree(root);
    cout << "~BST" << endl;
}

//delete tree
void BST::delete_tree() {

    delete_tree(root);

}
void BST::delete_tree(node*& r) {


    if (r != 0)
    {
        delete_tree(r->left);
        delete_tree(r->right);
        delete r;
        r = 0;
    }


}



//search
bool BST::search(int el) {
    return search(el, root);
}

bool BST::search(int el, node* r)
{
    if (r == 0)
        return false;
    if (r->data == el)
        return true;
    if (r->data > el)
        return search(el, r->left);
    if (r->data < el)
        return search(el, r->right);



}

//height 
void BST::height()
{
    cout << height(root);
}

int BST::height(node* r)
{
    if (r == 0)
        return 0;
    int hl = height(r->left);
    int hr = height(r->right);
    cout << hl << "  " << hr << endl;
    if (hl > hr)
        return hl + r->data;
    return hr + r->data;
}
// constuctor for class:

BST::BST() {
    root = 0;
}

//method return count node in tree

int BST::size() {

    return size(root);

}

//method counter node in tree

int BST::size(node* r) {
    if (r != 0)
    {
        return 1 + size(r->right) + size(r->left);
    }
    return 0;

}

// method return function add new element:

bool BST::add(int el) {
    return add(el, root);
}

// method add element on tree:

bool BST::add(int el, node*& r)
{
    if (r == 0)
    {
        r = new node(el);
        return true;
    }
    else
        if (r->data == el)
            return false;
        else
            if (r->data > el) {
                return add(el, r->left);
            }
            else
                if (r->data < el) {
                    return add(el, r->right);

                }
}



void BST::preorder() {
    pre(root);
}

void BST::pre(node* r) {
    if (r != 0) {
        cout << r->data << endl;
        pre(r->left);
        pre(r->right);

    }
}
void BST::inorder() {
    in(root);
}

void BST::in(node* r) {
    if (r != 0) {

        in(r->left);
        cout << r->data << endl;
        in(r->right);

    }
}