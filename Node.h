#include <iostream>
#include <stdio.h>

class Node{ 
    public:
        Node(int value, Node* leftt = nullptr, Node* rightt = nullptr);
        ~Node();
        int val;
        Node* left;
        Node* right;
};