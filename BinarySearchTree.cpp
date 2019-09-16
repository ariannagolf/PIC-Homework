//
//  BinarySearchTree.cpp
//  Homework 7
//
//  Created by Milu on 6/8/18.
//  Copyright (c) 2018 Milu. All rights reserved.
//

#include "BinarySearchTree.h"
#include "TreeNode.h"
#include "TreeIterator.h"


void BinarySearchTree::cleanup(TreeNode* p) {
    if(p->left) cleanup(p->left); // if p has a left child
    if (p->right) cleanup(p->right); //if p has a right child
    else delete p; // delete chldren first then delete the current node
}

BinarySearchTree::~BinarySearchTree() {
    if(root) {
        cleanup(root); //call cleanup on root itself
    }
    root = nullptr; // NO DANGLING PTRS!!!!
}

TreeIterator BinarySearchTree::find(int n) const { //use for cleanup, desctructor for new TreeNode: delete->this
    if(!root) { //root doesn't exist
        return TreeIterator();
    }
    else {
        return TreeIterator(root->find(n),this);
    }
}
void BinarySearchTree::insert(int data) { // calls new in Node insert fxn instead, then Treenode should call delete too
    TreeNode* new_node = new TreeNode;
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if(root == nullptr) {
        root = new_node;
    }
    else {
        root->insert_node(new_node);
    }
}

void BinarySearchTree::print() const { //the one you actually call, actually use iterators for hw
    if(root != nullptr) root->print();
}
TreeIterator BinarySearchTree::begin() const {
    if(root == nullptr) {
        return TreeIterator(nullptr,this);
    }
    else {
        TreeNode* node;
        node = root;
        while(node->left != nullptr) {
            node = node->left;
        }
        return TreeIterator(node, this);
    }
}
TreeIterator BinarySearchTree::end() const {
    return TreeIterator(nullptr, this);
}

void BinarySearchTree::erase(int data) {
    TreeNode* remove = root;
    TreeNode* parent = nullptr;
    
    bool found = false;
    while(!found && remove != nullptr) {
        if(remove->data < data) {
            parent = remove;
            remove = remove->right;
        }
        else if (data < remove->data) {
            parent = remove;
            remove = remove->left;
        }
        else {
            found = true;
        }
    }
    if(!found) {
        return;
    }
    if (remove->left == NULL || remove->right == NULL) {
        
        TreeNode* new_child;
        if (remove->left == NULL) {
            new_child = remove->right;
        }
        else {
            new_child = remove->left;
        }
        if (parent == NULL) { // if eraseing root
            root = new_child;
        }
        else if (parent->left == remove) {
            parent->left = new_child;
        }
        else {
            parent->right = new_child;
        }
        return;
    }
    TreeNode* smallest_parent = remove;
    TreeNode* smallest = remove->right;
    while(smallest->left != nullptr) {
        smallest_parent = smallest;
        smallest = smallest->left;
    }
    remove->data = smallest->data;
    if(smallest_parent == remove) {
        smallest_parent->right = smallest->right;
    }
    else {
        smallest_parent->left = smallest->right;
    }
}
