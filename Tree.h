//
//  Tree.h
//  binary_search_tree
//
//  Created by Ayne Delgado on 3/8/15.
//  Copyright (c) 2015 Ayne Delgado. All rights reserved.
//
#include "Node.h"
#include <iostream>
#include <cassert>
using namespace std;


class Tree
{
private:
//-----------------------Data Members----------------------
    Node* root=nullptr;
    //int theSize;
//---------------------Helper functions---------------------
    void destroy(Node* n);
    void print_helper(Node* n, int depth);
    void insert_helper(int d, Node* n);
    void pre_order_helper(Node* n);
    void post_order_helper(Node* n);
    void in_order_helper(Node* n);
    bool is_in_helper(int d, Node* n);
    bool erase_helper(int d, Node* parent);
    bool erase_root(Node*& n);
    
    int find_new_root(Node* n, Node* p);
    int size_helper(Node* n) const;
  

    
    
public:
    Tree(int d);
    ~Tree();
    int size() const;
    void print();
    bool erase(int d);
    void insert(int d);
    void pre_order();
    void post_order();
    void in_order();
    bool is_in(int d);
   

};
