#include <iostream>
#include <stdio.h>
#include <vector>
#include <time.h>
#include "BST.h"
using namespace std;

BST::BST(){
    root = nullptr;
    numNode = 0;
}

BST::BST(int val){
    root = new Node(val);
    numNode = 1;
}

void BST::insert(int val){
    Node* curr = root;
    if(curr == nullptr){
        root = new Node(val);
        numNode = 1;
        return;
    }
    while (curr != nullptr){
        compCount++;
        if (curr->val == val){
            break;
        }
        if (val < curr->val){
            if (curr->left != nullptr){
                curr = curr->left;
                continue;
            }
            // else if (curr->left != nullptr){
            //     Node* temp = new Node(val);
            //     temp->left = curr->left;
            //     curr->left = temp;
            //     numNode++;
            //     break;
            // }
            else if (val > curr->val){
                Node* temp = new Node(val);
                curr->left = temp;
                numNode++;
                break;
            }else {
                break;
            }
        }
        else{
            if (curr->right != nullptr){
                curr = curr->right;
                continue;
            }
            // else if (curr->right != nullptr){
            //     Node* temp = new Node(val);
            //     temp->right = curr->right;
            //     curr->right = temp;
            //     numNode++;
            //     break;
            // }
            else{
                Node* temp = new Node(val);
                curr->right = temp;
                numNode++;
                break;
            }
        }
    }
}

void BST::remove(int val){
    Node* prev = nullptr;
    bool l = true;
    Node* curr = root;
    while (curr != nullptr){
        compCount++;
        if (curr->val == val){
            if (curr->left == nullptr && curr->right == nullptr){
                if(prev == nullptr){
                    root = nullptr;
                }else{
                    if(l){
                        prev->left = nullptr;
                    }else{
                        prev->right = nullptr;
                    }
                }
                delete curr;
                numNode--;
                break;
            }
            else if (curr->left == nullptr){ 
                if(prev == nullptr){
                    root = curr->right;
                } else {
                    if (l){
                        prev->left = curr->right;
                    }
                    else{
                        prev->right = curr->right;
                    }
                }
                delete curr;
                numNode--;
                break;
            }
            else if (curr->right == nullptr){
                if(prev == nullptr){
                    root = curr->left;
                }else {
                    if (l){
                        prev->left = curr->left;
                    }
                    else{
                        prev->right = curr->left;
                    }
                }
                delete curr;
                numNode--;
                break;
            }
            else{                       //need to make whatever node points at succ go to nullptr unless succ is prev
                Node* succ = curr->right;
                Node* succPrev = nullptr;
                // if (succ == nullptr){
                //     succ = prev;
                // }
                // else{
                while (succ->left != nullptr){
                    succPrev = succ;
                    succ = succ->left;
                }
                if (succPrev != nullptr){
                    succPrev->left = nullptr;
                }else{
                    curr->right = succ->right;
                }
                // }
                //if (succ != prev){
                if(prev == nullptr){
                    root = succ;
                }else {
                    if (l){
                        prev->left = succ;
                    }
                    else{
                        prev->right = succ;
                    }
                }
                succ->left = curr->left;
                succ->right = curr->right;
                //}
                // else{
                //     prev->left = curr->left; //if succ == prev it curr shouldnt have a right
                // }
                delete curr;
                numNode--;
                break;
            }
        }
        prev = curr;
        if (val < curr->val){
            l = true;
            curr = curr->left;
        }
        else{
            l = false;
            curr = curr->right;
        }
    }
}

Node* BST::find(int val){
    Node* curr = root;
    while (curr != nullptr){
        if (curr->val == val){
            return curr;
        }
        if (val < curr->val){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
        compCount++;
    }
    return nullptr;
}

void BST::insertVector(vector<int> &n){
    for (unsigned int i = 0; i < n.size(); i++){
        this->insert(n.at(i));
    }
}

void BST::removeVector(vector<int> &n){
    for (unsigned int i = 0; i < n.size(); i++){
        this->remove(n.at(i));
    }
}

void BST::shuffle(vector<int> &n, int S){
    srand(time(NULL));
    while(S > 0){
        int index1 = rand() % n.size();
        //srand(time(NULL));
        int index2 = rand() % n.size();
        //srand(time(NULL));

        int temp = n.at(index1);
        n.at(index1) = n.at(index2);
        n.at(index2) = temp;

        S--;
    }
}

void BST::shake(vector<int> &n, int S, int R){
    srand(time(NULL));
    while (S > 0){
        int startIndex = rand() % n.size();
        int nextSwap = startIndex + 1;
        //srand(time(NULL));
        int swaps = rand() % (R+1);
        //srand(time(NULL));
        int size = n.size();

        //random direction stuff
        bool l = rand() % 2;
        
        while(swaps > 0 && (nextSwap < size && nextSwap >= 0)){
            int temp = n.at(startIndex);
            n.at(startIndex) = n.at(nextSwap);
            n.at(nextSwap) = temp;

            startIndex = nextSwap;
            if (l){
                nextSwap++;
            }
            else{
                nextSwap--;
            }
            swaps--;
        }

        S--;
    }
}

int BST::avgDepth(){
    return (avgDepthHelp(root->left, 0) + avgDepthHelp(root->right, 0)) / numNode;
}

int BST::avgDepthHelp(Node* curr, int currDepth){
    if (curr == nullptr){
        return 0;
    }
    else{
        int newDepth = currDepth + 1;
        return newDepth + avgDepthHelp(curr->left, newDepth) + avgDepthHelp(curr->right, newDepth);
    }
}

int BST::getHeight(){
    return getHeightHelp(root);
}

int BST::getHeightHelp(Node* curr){
    if(curr == nullptr){
        return -1;
    }
    return 1 + max(getHeightHelp(curr->left), getHeightHelp(curr->right));
}

void BST::reset(){
    compCount = 0;
}

int BST::getCount(){
    return compCount;
}

void BST::printInOrder(){
    printInOrderHelper(root);
}

void BST::printInOrderHelper(Node* curr){
    if(curr != nullptr){
        printInOrderHelper(curr->left);
        cout<<curr->val<<", ";
        printInOrderHelper(curr->right);
    }
}

int BST::getNumNodes(){
    return numNode;
}

BST::~BST(){
    deleteHelper(root);
}

void BST::deleteHelper(Node* x){
    if(x == nullptr){return;}

    deleteHelper(x->left);
    deleteHelper(x->right);
    delete x;
}
