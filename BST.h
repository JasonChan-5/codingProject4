#include <iostream>
#include <stdio.h>
#include "Node.h"

class BST{
    public:
        BST();
        BST(int val);
        void insert(int val);
        void remove(int val);
        Node* find(int val);
        Node* root;
};