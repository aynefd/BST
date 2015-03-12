//
//  main.cpp
//  binary_search_tree
//
//  Created by Ayne Delgado on 3/8/15.
//  Copyright (c) 2015 Ayne Delgado. All rights reserved.
//

#include <iostream>
#include "Tree.h"

int main()
{
    
    Tree myTree(100);
    myTree.insert(120);
    myTree.insert(60);
    myTree.insert(70);
    
    
    //myTree.insert(20);
   
    myTree.print();
    cout<<endl;
    myTree.pre_order();
    cout<<endl;
    myTree.post_order();
    cout<<endl;
    myTree.in_order();
    
    if(myTree.erase(100))
        cout<<"erased"<<endl<<endl;
    
//    if(myTree.is_in(9))
//        cout<<"FOUND IT"<<endl;
//    else
//        cout<<"NOT THERE"<<endl;
    
    
   // cout<<myTree.size()<<endl;
    
    myTree.print();
    
    return 0;
    
}
