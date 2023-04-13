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
        if (curr->val == val){
            compCount++;
            break;
        }
        compCount++;
        if (val < curr->val){
            if (curr->left != nullptr && val < curr->left->val){
                curr = curr->left;
                continue;
            }
            else if (curr->left != nullptr){
                Node* temp = new Node(val);
                temp->left = curr->left;
                curr->left = temp;
                numNode++;
                break;
            }
            else{
                Node* temp = new Node(val);
                curr->left = temp;
                numNode++;
                break;
            }
            compCount++;
        }
        else{
            if (curr->right != nullptr && val > curr->right->val){
                curr = curr->right;
                continue;
            }
            else if (curr->right != nullptr){
                Node* temp = new Node(val);
                temp->right = curr->right;
                curr->right = temp;
                numNode++;
                break;
            }
            else{
                Node* temp = new Node(val);
                curr->right = temp;
                numNode++;
                break;
            }
            compCount++;
        }
        compCount++;
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
                delete curr;
                numNode--;
                break;
            }
            if (curr->left == nullptr){
                if (l){
                    prev->left = curr->right;
                }
                else{
                    prev->right = curr->right;
                }
                delete curr;
                numNode--;
                break;
            }
            else if (curr->right == nullptr){
                if (l){
                    prev->left = curr->left;
                }
                else{
                    prev->right = curr->left;
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
                }
                // }
                //if (succ != prev){
                if (l){
                    prev->left = succ;
                }
                else{
                    prev->right = succ;
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
        compCount++;
    }
}

Node* BST::find(int val){
    Node* curr = root;
    while (curr != nullptr){
        if (curr->val = val){
            compCount++;
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

void BST::insertVector(vector<int> n){
    for (int i = 0; i < n.size(); i++){
        this->insert(n.at(i));
    }
}

void BST::removeVector(vector<int> n){
    for (int i = 0; i < n.size(); i++){
        this->remove(n.at(i));
    }
}

void BST::shuffle(vector<int> &n, int S){
    while(S > 0){
        int index1 = rand() % n.size();
        srand(time(NULL));
        int index2 = rand() % n.size();
        srand(time(NULL));

        int temp = n.at(index1);
        n.at(index1) = n.at(index2);
        n.at(index2) = temp;

        S--;
    }
}

void BST::shake(vector<int> &n, int S, int R){
    while (S > 0){
        int startIndex = rand() % n.size();
        srand(time(NULL));
        int nextSwap = startIndex + 1;

        int swaps = rand() % (R+1);
        srand(time(NULL));
        
        while(swaps > 0){
            if(nextSwap == n.size()){
                nextSwap = 0;
            }
            
            int temp = n.at(startIndex);
            n.at(startIndex) = n.at(nextSwap);
            n.at(nextSwap) = temp;

            startIndex = nextSwap;
            nextSwap++;
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
        return currDepth + avgDepthHelp(root->left, newDepth) + avgDepthHelp(root->right, newDepth);
    }
}

int BST::getHeight(){
    return getHeightHelp(root);
}

int BST::getHeightHelp(Node* curr){
    return 1 + max(getHeightHelp(curr->left), getHeightHelp(curr->right));
}

void BST::reset(){
    compCount = 0;
}

int BST::getCount(){
    return compCount;
}