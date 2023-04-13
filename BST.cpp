#include <iostream>
#include <stdio.h>
#include "BST.h"
using namespace std;

BST::BST(){
    root = nullptr;
}

BST::BST(int val){
    root = new Node(val);
}

void BST::insert(int val){
    Node* curr = root;
    while (curr != nullptr){
        if (curr->val == val){
            break;
        }
        if (val < curr->val){
            if (curr->left != nullptr && val < curr->left->val){
                curr = curr->left;
                continue;
            }
            else if (curr->left != nullptr){
                Node* temp = new Node(val);
                temp->left = curr->left;
                curr->left = temp;
                break;
            }
            else{
                Node* temp = new Node(val);
                curr->left = temp;
                break;
            }
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
                break;
            }
            else{
                Node* temp = new Node(val);
                curr->right = temp;
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
        if (curr->val = val){
            if (curr->left == nullptr && curr->right == nullptr){
                delete curr;
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
                break;
            }
            else{                       //need to make whatever node points at succ go to nullptr unless succ is prev
                Node* succ = curr->right;
                Node* succPrev = nullptr;
                if (succ == nullptr){
                    succ = prev;
                }
                else{
                    while (succ->left != nullptr){
                        succPrev = succ;
                        succ = succ->left;
                    }
                    if (succPrev != nullptr){
                        succPrev->left = nullptr;
                    }
                }
                if (succ != prev){
                    if (l){
                        prev->left = succ;
                    }
                    else{
                        prev->right = succ;
                    }
                    succ->left = curr->left;
                    succ->right = curr->right;
                }
                else{
                    prev->left = curr->left; //if succ == prev it curr shouldnt have a right
                }
                delete curr;
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
        if (curr->val = val){
            return curr;
        }
        if (val < curr->val){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return new Node(-1);
}