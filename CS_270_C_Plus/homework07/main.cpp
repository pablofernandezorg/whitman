//Pablo Fernandez
//Copyright 2016, www.pablofernandez.com


#include <stdio.h>
#include "BST.h"

int main(){

    BST<int> a;
    //adding three elements to the tree
    cout<<"is empty tree balanced: "<<a.isBalanced()<<endl;
    a.insertNode(1);
    a.insertNode(2);
    a.insertNode(3);
    cout<<"(after adding three element)is tree balanced: "<<a.isBalanced()<<endl;
    
    cout<<"Displaying the tree in order"<<endl;
    a.inOrderTraversal();
    cout<<"Removing the element with a value of 1"<<endl;
    a.remove(1);
    cout<<"Displaying the tree in order after the deletion"<<endl;
    a.inOrderTraversal();
    cout<<"is tree balanced: "<<a.isBalanced()<<endl;
    return 0;
    
}
