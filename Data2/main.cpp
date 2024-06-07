// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
#include <Recursion.h>
#include <BST.h>

// return function calculate the taller height 


int main() {
    // Write C++ code here
    BST t;
    Recursion r1;
   
    //r1.NSU(9);
    //cout << r1.Power(3, 3);
    //cout << endl;
    //cout << r1.Multiplication(3, 0) << endl;
    //cout<<r1.GCD(9, 5)<<endl;
    //int a[] = { 2,3 ,1,5,9};
    //r1.back_array(a, 5);
    //cout << r1.sum_arr(a, 5);
    //cout<<r1.sum_digits(122551);
    //cout << r1.sum_first_even(3);
    //cout<< r1.min_array(a, 5, a[0]);
    
    t.add(55); 
    t.add(56);
    t.add(53);
    t.add(59);
    t.add(64);
    t.add(52);
    t.add(57);
    t.add(60);
    //t.postorder();
    //cout<<t.min_bst()<<endl;
    cout << t.sum_of_internal();
    /*
   // t.preorder();
    //cout << "inorder::" << endl;
   // t.inorder();
   // t.height();
   // cout<<t.search(60);
    //t.delete_tree();
    /*cout << "preorder::" << endl;
    t.preorder();
   // cout << "size::" << t.size() << endl;
   // cout << "size::"<< t.tallerpath()<< endl;
    BST t2(t);
    cout << "preorder::" << endl;
    t2.preorder();
    */
    return 0;
}