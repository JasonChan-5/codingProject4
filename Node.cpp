#include <iostream>
#include <stdio.h>
#include "Node.h"

Node::Node(int value, Node* leftt, Node* rightt){
    val = value;
    left = leftt;
    right = rightt;
}

Node::~Node(){
}