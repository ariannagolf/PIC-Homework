//
//  TreeNode.h
//  Homework 7
//
//  Created by Milu on 6/8/18.
//  Copyright (c) 2018 Milu. All rights reserved.
//

#ifndef __Homework_7__TreeNode__
#define __Homework_7__TreeNode__

#include "BinarySearchTree.h"

class TreeNode {
public:
    /* finds the node with value n
     - @param n - int
     - @return TreeNode
     */
    TreeNode* find(int n) const;
    //void insert(int n); // creates a new node and inserts into Tree
    void insert_node(TreeNode* pos);
    void print() const;
    
private:
    int data;
    TreeNode* parent;
    TreeNode* right;
    TreeNode* left;
    friend class BinarySearchTree;
    friend class TreeIterator;
};


#endif /* defined(__Homework_7__TreeNode__) */
