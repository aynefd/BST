//
// An interactive test program taken from SAVICH book
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "Tree.h"  // With value_type defined as double
using namespace std;

// PROTOTYPES for functions used by this test program:
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters),
// and this character has been returned.


double get_number( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.


int main( )
{
    Tree test(100); // Tree to test on
    char choice;   // A command character entered by the user
    
    cout << "I have initialized a tree of integers, with a root of 100." << endl;
    
    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            
             case 'I': test.insert(get_number( ));
                break;
            case '?': if (test.is_in(get_number() ))
                cout << "The number is in the tree" << endl;
            else
                cout << "The number is not in the tree." << endl;
                break;
            case 'P': test.print();
                break;
            case 'N': test.in_order();
                break;
            case 'R': test.pre_order();
                break;
            case 'O': test.post_order();
                break;
            case 'S': cout << "Size is " << test.size( ) << '.' << endl;
                break;
            case 'E': if(test.erase(get_number()))
                    cout<<"The number was erased."<<endl;
                else
                    cout<<"Sorry, number was not in the tree."<<endl;
                
            case 'Q':
                cout << "Ridicule is the best test of truth." << endl;
                break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
    
    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " I   Insert a new number with the insert( ) function" << endl;
    cout << " ?   Find out if number is in tree from the is_in( ) function" << endl;
    cout << " P   Print the tree" << endl;
    cout << " N   Print the numbers of the tree in order"<<endl;
    cout << " R   Print the numbers of the tree in pre-order"<<endl;
    cout << " O   Print the numbers of the tree in post-order"<<endl;
    cout << " S   Print the size of the tree" << endl;
    cout << " E   Erase a number in the tree"<<endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;
    
    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character
    
    return command;
}



double get_number( )
// Library facilities used: iostream
{
    double result;
    
    cout << "Please enter an intetger: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}

























//int main()
//{
//    
//    Tree myTree(100);
//    myTree.insert(150);
//    myTree.insert(60);
//    myTree.insert(50);
//    myTree.insert(200);
//    myTree.insert(30);
//    myTree.insert(33);
//    myTree.insert(110);
//    
//    
//    //myTree.insert(20);
//   
//      myTree.print();
////    cout<<endl;
////    myTree.pre_order();
////    cout<<endl;
////    myTree.post_order();
////    cout<<endl;
////    myTree.in_order();
//    
//    cout<<endl;
//    if(myTree.erase(200))
//       cout<<"erased"<<endl<<endl;
//    
////    if(myTree.is_in(9))
////        cout<<"FOUND IT"<<endl;
////    else
////        cout<<"NOT THERE"<<endl;
//    
//    
//    cout<<"my size is: "<<myTree.size()<<endl;
//    
//    myTree.print();
//    
//    return 0;
//    
//}
