//
//  TreeNode.cpp
//  Homework 7
//
//  Created by Milu on 6/8/18.
//  Copyright (c) 2018 Milu. All rights reserved.
//

#include "TreeNode.h"

TreeNode* TreeNode::find(int n) const { //returns actual location of where the data must be found
//    if(data == n) {
//        return pos;
//    }
    if (n < data) {
        if (left) {
            return left->find(n);
        }
        else {
            return nullptr;
        }
    }
    else {
        if(right)
            return right->find(n);
        else
            return nullptr;
    }
}

void TreeNode::insert_node(TreeNode* pos) {
    if(pos->data < data) {
        if(left == nullptr) {
            left = pos;
        }
        else {
            left->insert_node(pos);
        }
    }
    else if (data < pos->data) {
        if(right == nullptr) {
            right = pos;
        }
        else {
            right->insert_node(pos);
        }
    }
}

void TreeNode::print() const { // good method for destructor
    if(left != nullptr) left->print();
    std::cout << data << ",";
    if (right != nullptr) right->print();
}
