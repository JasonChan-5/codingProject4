#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BST.h"

using namespace std;

int main(){
    BST *x = new BST();
    x->insert(5);

    x->insert(2);
    x->insert(8);

    x->insert(1);
    x->insert(3);
    x->insert(7);
    x->insert(9);

    x->printInOrder();
    cout<<endl;
    x->remove(5);
    x->printInOrder();



}