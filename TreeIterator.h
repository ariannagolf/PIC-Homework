//
//  TreeIterator.h
//  Homework 7
//
//  Created by Milu on 6/8/18.
//  Copyright (c) 2018 Milu. All rights reserved.
//

#ifndef __Homework_7__TreeIterator__
#define __Homework_7__TreeIterator__

#include "BinarySearchTree.h"

class TreeIterator {
public:
    // Default constructor
    TreeIterator():pos(nullptr) {}
    // Constructor w/ 1 param
    // @param p - TreeNode
    TreeIterator(TreeNode *p) : pos(p) {}
    //Constructor w/ 2 params
    // @param p - TreeNode, @param c - BinarySearchTree
    TreeIterator(TreeNode* p, const BinarySearchTree* c);
    /* dereference overload
     - @return data of the node
     */
    int operator*() const;
    /* overload ++ operator to increment through BST
     - @retur TreeIterator
     */
    TreeIterator operator++();
    /* overload ==
     - @param n - TreeIterator
     - @return bool whether they are equal or not
     */
    bool operator==(TreeIterator n);
    /* overload !=
     - @param n - TreeIterator
     - @return bool whether they are equal or not
     */
    bool operator!=(TreeIterator n);
    
    
private:
    TreeNode* pos; //pts to current treenode
    const BinarySearchTree* currentTree; //pts to current binary search tree
};


#endif /* defined(__Homework_7__TreeIterator__) */
