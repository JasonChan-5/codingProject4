#include <iostream>
#include <stdio.h>
#include <vector>
#include "Node.h"

using namespace std;

class BST{
    public:
        BST();
        BST(int val);
        void insert(int val);
        void remove(int val);
        Node* find(int val);
        void insertVector(vector<int> n);
        void removeVector(vector<int> n);
        void shuffle(vector<int> &n, int S);
        void shake(vector<int> &n, int S, int R);
        int avgDepth();
        int avgDepthHelp(Node* curr, int currDepth);
        int getHeight();
        int getHeightHelp(Node* curr);
        void reset();
        int getCount();
        void printInOrder();
        void printInOrderHelper(Node* curr);
        int getNumNodes();
        int compCount;
        Node* root;
        int numNode;
};