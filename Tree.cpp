//
//  Tree.cpp
//  binary_search_tree
//
//  Created by Ayne Delgado on 3/8/15.
//  Copyright (c) 2015 Ayne Delgado. All rights reserved.
//

#include "Tree.h"
Node::Node(int d)
{
    data = d;
    right = nullptr;
    left = nullptr;
}
Tree::Tree(int d)
{
    root = new Node(d);
    //theSize = 1;
    
}
Tree::~Tree()
{
    if(root!=nullptr)
    {
        destroy(root);
        root->right = nullptr;
        root->left = nullptr;
    }
}
int Tree::size_helper(Node* n, int count) const //FIX DIS
{
   //count = 0;
   if(n==nullptr)
       return count;
    else
    {
        if(n->right!=nullptr)
            return size_helper(n->right, count+2);
        if(n->left!=nullptr)
            return size_helper(n->left, count+2);
        
        return ++count;
        
    }

}
int Tree::size()const
{
    if(root->is_leaf())
        return 1;
    else
        return size_helper(root, 0);
}
bool Node::is_leaf()
{
    if(right==nullptr&&left==nullptr)
        return true;
    else
        return false;
}
void Tree::print()
{
    print_helper(root, 0);
    
}
void Tree::print_helper(Node* n, int depth)
{
    
    cout.width(depth*4);
    if(n==nullptr)
    {
        cout<<"[Empty]"<<endl;
    }
    else if(n->is_leaf())
    {
        cout<<n->data<<" [leaf]"<<endl;
    }
    else
    {
        cout<<n->data<<endl;
        print_helper(n->right, depth+1);
        print_helper(n->left, depth+1);
    }
}
void Tree::insert(int d)
{
    insert_helper(d, root);
}
void Tree::insert_helper(int d, Node* n)
{
    //if d=node->data
        //return
    
    if(d == n->data)
        return;
    //check if d>node->data
    if(d>n->data)
    {
        if(n->right==nullptr)
        {
            n->right = new Node(d);
            return;
        }
        else
        {
            insert_helper(d, n->right);
        }
    }
    else
    {
        if(n->left==nullptr)
        {
            n->left = new Node(d);
            return;
        }
        else
        {
            insert_helper(d, n->left);
        }
    }
    
        //if yes then check if right is a nullptr
        //if yes then right=new Node(d)
            //else check if d>node->right
                //return insert_helper(d, node->right)
            //check if d<=root->left
                //return insert_helper(d, node->left)
    //if d<node->data
        //check if left is a nullptr
            //if yes then left = new Node(d);
        //else check if d>node->left
            //return insert_helper(d, node->right)
    //check if d<=root->left
        //return insert_helper(d, node->left)
    
}

void Tree::pre_order()
{
    pre_order_helper(root);
}
void Tree::pre_order_helper(Node* n)
{
    if(n==nullptr)
        return;
    else
    {
        cout<<n->data<<endl;
        pre_order_helper(n->left);
        pre_order_helper(n->right);
    }
}

void Tree::post_order()
{
    post_order_helper(root);
    
}
void Tree::post_order_helper(Node* n)
{
    if(n==nullptr)
        return;
    else
    {
        pre_order_helper(n->left);
        pre_order_helper(n->right);
        cout<<n->data<<endl;
    }
}
void Tree::in_order()
{
    in_order_helper(root);
}
void Tree::in_order_helper(Node* n)
{
    if(n==nullptr)
        return;
    else
    {
        
        pre_order_helper(n->left);
        cout<<n->data<<endl;
        pre_order_helper(n->right);
    }
}
bool Tree::is_in(int d)
{
    return (is_in_helper(d, root));
}

bool Tree::is_in_helper(int d, Node* n)
{
    if(n==nullptr)
        return false;
    if(n->data == d)
        return true;
    else if(n->data<d)
        return (is_in_helper(d, n->right));
    else
        return (is_in_helper(d, n->left));

    
}
void Tree::destroy(Node* n)
{
    
    if (n == nullptr)
        return;
    else
    {
        destroy(n->right);
        destroy(n->left);
        delete n;
    }
}
bool Tree::erase(int d)
{
   if(d==root->data)
       return erase_root(root);
    else
        return false;
}
bool Tree::erase(int d, Node* n)
{
    return false;
}
bool Tree::erase_root(Node* n)
{
    if(n->is_leaf())
    {
        delete root;
        root=nullptr;
        return true;
    }
    else if(n->left==nullptr && n->right!=nullptr)
    {
        Node* old = root;
        root=n->right;
        delete old;
        return true;
    }
    else if(n->left->right==nullptr)
    {
        Node* old = root;
        Node* right = root->right;
        root=n->left;
        root->right = right;
        delete old;
        return true;
        
    }
    else
    {
        int new_root = find_new_root(n->left, root);
        root->data = new_root;
        
        
        return true;
    }
}
int Tree::find_new_root(Node* n, Node* p)
{
    if(n->right==nullptr)
    {
        if(n->is_leaf())
        {
            int new_root=n->data;
            p->right=nullptr;
            return new_root;
            
        }
        else
        {
            int new_root=n->data;
            p->right=n->left;
            return new_root;
        }
            
    }
    else
        return find_new_root(n->right, n);
        
    
    
}








