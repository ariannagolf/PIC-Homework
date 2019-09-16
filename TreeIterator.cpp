//
//  TreeIterator.cpp
//  Homework 7
//
//  Created by Milu on 6/8/18.
//  Copyright (c) 2018 Milu. All rights reserved.
//

#include "TreeIterator.h"
#include "TreeNode.h"

TreeIterator::TreeIterator(TreeNode* p, const BinarySearchTree* c):pos(p),currentTree(c) {}

int TreeIterator::operator*() const {
    return pos->data;
    return 0;
}

TreeIterator TreeIterator::operator++() {
    TreeNode* n = nullptr;
    if(pos->right != nullptr) {
        pos = pos->right;
        while(pos->left != nullptr) {
            pos = pos->left;
        }
    }
    else {
        n = pos->parent;
        while(n != nullptr && pos == n->right) {
            pos = n;
            n = n->parent;
        }
        pos = n;
    }
    return *this;
}

bool TreeIterator::operator==(TreeIterator n) {
    TreeIterator* p = &n;
    return this->pos == p->pos;
}

bool TreeIterator::operator!=(TreeIterator n) {
    TreeIterator* p = &n;
    return this->pos != p->pos;
}