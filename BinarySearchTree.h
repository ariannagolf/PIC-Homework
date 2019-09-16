//
//  BinarySearchTree.h
//  Homework 7
//
//  Created by Milu on 6/8/18.
//  Copyright (c) 2018 Milu. All rights reserved.
//

#ifndef __Homework_7__BinarySearchTree__
#define __Homework_7__BinarySearchTree__

#include <iostream>

class TreeNode;
class TreeIterator;

class BinarySearchTree {
public:
    /* Destructor */
    ~BinarySearchTree();
    /* searches through a BST for the node with the value n
     @param n - int
     @return TreeIterator to the node
     */
    TreeIterator find(int n) const;
    /* inserts the value inputted by the user to the tree in the correct place
     - @param data - int
     */
    void insert(int data); // calls new in Node insert fxn instead, then Treenode should call delete too
    /* finds the smallest value
     - @return Treeiterator to the smallest value
     */
    TreeIterator begin() const;
    /* finds the largest value
     - @return TreeIterator to the largest value
     */
    TreeIterator end() const;
    /* prints the BST in the correct order
     */
    void print() const;
    /* erases the node with the inputted value
     - @param data - int
     */
    void erase(int data);
    
private:
    /* private helper function for the destructor
     - @param p - TreeNode
     */
    void cleanup(TreeNode* p); 
    TreeNode* root;
    
};

#endif /* defined(__Homework_7__BinarySearchTree__) */
