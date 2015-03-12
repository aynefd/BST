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
int Tree::size_helper(Node* r, Node* l) const //FIX DIS
{
   


        
    

}
int Tree::size()const
{
    if(root->is_leaf())
        return 1;
    else
        return size_helper(root->right, root->left);
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
        return erase_helper(d, root);
}
bool Tree::erase_helper(int d, Node* parent)
{
    Node* left_child = parent->left;
    Node* right_child = parent->right;
    if(left_child==nullptr && right_child==nullptr)
        return false;
    else
    {
        if(left_child!=nullptr && left_child->data==d)
        {
            if(left_child->is_leaf())
            {
                delete left_child;
                parent->left=nullptr;
                return true;
            }
            else if(left_child->right!=nullptr && left_child->left!=nullptr)
            {
                //erase_like_root(left_child, parent, d);
                if(left_child->left->right==nullptr)
                {
                    left_child->data=left_child->left->data;
                    if(left_child->left->left==nullptr)
                        left_child->left = nullptr;
                    else
                    {
                        Node* left = left_child->left->left;
                        delete left_child->left;
                        left_child->left=left;
                        
                    }
                    
                    return true;
                }
                else
                {
                    int new_left_child = find_new_root(left_child->left, left_child);
                    left_child->data=new_left_child;
                    return true;
                }
            }
            else if(left_child->left!=nullptr && left_child->right==nullptr)
            {
                parent->left=left_child->left;
                delete left_child;
                return true;
            }
            else
            {
                parent->left=left_child->right;
                delete left_child;
                return true;
            }
        }
        else if(right_child!=nullptr && right_child->data==d)
        {
            
            if(right_child->is_leaf())
            {
                delete right_child;
                parent->right=nullptr;
                return true;
            }
            else if(right_child->right!=nullptr && right_child->left!=nullptr)
            {
                //if like root
                if(right_child->left->right==nullptr)
                {
                    right_child->data=right_child->left->data;
                    if(right_child->left->left==nullptr)
                        right_child->left = nullptr;
                    else
                    {
                        Node* left = right_child->left->left;
                        delete right_child->left;
                        right_child->left=left;
                        
                    }

                    return true;
                }
                else
                {
                    int new_left_child = find_new_root(right_child->left, right_child);
                    right_child->data=new_left_child;
                    return true;
                }
            }
            else if(right_child->left!=nullptr && right_child->right==nullptr)
            {
                parent->right=right_child->left;
                delete right_child;
                return true;
            }
            else
            {
                parent->right=left_child->right;
                delete right_child;
                return true;
            }
        }
        else
        {
            if(parent->data<d)
                return erase_helper(d, parent->right);
            else
                return erase_helper(d, parent->left);
                
        }
    
    }
    return true;
}
bool Tree::erase_root(Node*& n)
{
    if(n->is_leaf())
    {
        delete n;
        n=nullptr;
        return true;
    }
    else if(n->left==nullptr && n->right!=nullptr)
    {
        Node* old = n;
        n=n->right;
        delete old;
        return true;
    }
    else if(n->left->right==nullptr)
    {
        Node* old = n;
        Node* right = n->right;
        n=n->left;
        n->right = right;
        delete old;
        return true;
        
    }
    else
    {
        int new_root = find_new_root(n->left, n);
        n->data = new_root;
        
        
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








