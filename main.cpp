//
//  main.cpp
//  Homework 7
//
//  Created by Milu on 5/31/18.
//  Copyright (c) 2018 Milu. All rights reserved. Collaborator: Zuan Yi Chew, Kushal Mohnot
//

#include "BinarySearchTree.h"
#include "TreeIterator.h"
#include "TreeNode.h"



int main() {
    BinarySearchTree bst;
    bst.insert(3); bst.insert(2); bst.insert(11);
    bst.insert(13); bst.insert(5); bst.insert(17); bst.insert(17);
    std::cout << "Your tree consists of : ";
    bst.print();
    //for (auto x : bst) std::cout << x << ",";
        // need to have end() fxn, == overload to check that beg() != end, and dereference overload
    std::cout << std::endl;
//    
    bst.erase(6);
    bst.erase(11);
    std::cout << "Your tree now consists of : ";
    bst.print();
    std::cout << std::endl;

    TreeIterator start = bst.begin();
    std::cout << "Checking initial value: " << *start;
    //if (start != stop) std::cout << *start++ << std::endl;
    
    
    
    
//    for(auto it = bst.begin(); it != bst.end(); it++) {}
    
    
    return 0;
}






