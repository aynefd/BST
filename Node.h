//
//  Node.h
//  binary_search_tree
//
//  Created by Ayne Delgado on 3/8/15.
//  Copyright (c) 2015 Ayne Delgado. All rights reserved.
//


struct Node
{
    int data;
    Node *right;
    Node *left;
    
    // Constructor
    // Postcondition: set data in the node & set left and right node to nullptr
    Node (int d);
    
    bool is_leaf();
};
