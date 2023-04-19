#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BST.h"

using namespace std;

int main(){
    BST *x = new BST();
    vector<int> n = {5, 2, 8, 1, 3, 7, 9};
    vector<int> q = {1, 2, 3, 5, 6, 7, 7};
    x->insertVector(n);
    // vector<int> m = {5, 2, 8};
    // x->removeVector(m);
    // x->shake(n, 7, 7);
    // for (int i = 0; i < n.size(); i++){
    //     cout << n.at(i) << " ";
    // }
    // cout << endl;

    x->printInOrder();
    cout << endl;

    cout << x->getCount() << endl;
    x->reset();
    cout << x->getCount() << endl;
    
}