
// cs270, HW7
// Name: Pablo Fernandez
// username: fernanpa


// File BST.h


#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

template <class T>
class BST{
   private: 
        struct Node{
			T key;
			Node *left;
			Node *right;
        };
    
        Node *root;
	
		void inOrder(Node *);
		void preOrder(Node *);
		void postOrder(Node *);
	
    
   public:
	  BST(){ root = NULL; }
	 // Precondition: none
	 // Postcondition: The tree is empty.
	
	void insertNode(T val);
	// Precondition: val is any data to be inserted. 
	// Modifies: the tree itself.
	// Postcondition: A new BST node with data equals to val has been added to
	//                the tree.
	
	 
		
	void inOrderTraversal(){inOrder(root); }
	// Precondition: none
	// Postcondition: If the root is is not NULL, then the data of 
	//   the entire tree has been written to cout, using a in-order traverval.
	
	void preOrderTraversal(){preOrder(root); }
	// Precondition: none
	// Postcondition: If the root is is not NULL, then the data of 
	//   the entire tree has been written to cout, using a pre-order traverval.
	
	void postOrderTraversal(){postOrder(root); }
	// Precondition: none
	// Postcondition: If the root is is not NULL, then the data of 
	//   the entire tree has been written to cout, using a post-order traverval.	
	
    void destroyRecursively(Node *node);
    void remove(T t){
        deleteNode(t, root);
    }
	  // Precondition: none
  	  // Modifies: the tree itself.
	  // Postcondition: If target is in the tree, the corresponding BST node
	  //       has been removed. Otherwise, the tree remain unchanged.
    //does not work because our Node struct contains no parent node
    void transplant(Node* u, Node* v);
    void deleteNode(T item, Node *&nodePtr){
        if (item < nodePtr->key)
            deleteNode(item, nodePtr->left);
        else if (item > nodePtr->key)
            deleteNode(item, nodePtr->right);
        else
            makeDeletion(nodePtr);
    }
    void makeDeletion(Node *&nodePtr){
        // Define a temporary pointer to use in reattaching
        // the left subtree
        Node *tempNodePtr;
        
        if (nodePtr == NULL)
            cout << "Cannot delete empty node.\n";
        else if (nodePtr->right == NULL){
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left;    // Reattach the left child
            delete tempNodePtr;
        }
        else if (nodePtr->left == NULL){
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;   // Reattach the right child
            delete tempNodePtr;
        }
    }

    Node* minimum(Node* x){
        while (x->left != NULL)
            x = x->left;
        return x;
    }
    /*
     • T is balanced if it is empty.
     • T is balanced if it has only one child, and the height of T is ≤ 1.
     • Otherwise, T is balanced if:
     (1) Left subtree of T is balanced.
     (2) Right subtree of T is balanced.
     (3) The difference between heights of left subtree and right subtree is no more
     than 1.
     */
    int treeHeight(Node *node){
        if (node == NULL){
            return 0;
        }
        
        int left = treeHeight(node->left);
        int right = treeHeight(node->right);
        
        if (left > right)
            return 1 + left;
        else
            return 1 + right;
    }
    bool isBalanced(){
        return balanced(root);
    }
    
    
    bool balanced(Node * node){
        //T is balanced if it is empty.
        if(node == NULL)
            return true;
        
        int left = treeHeight(node->left);
        int right= treeHeight(node->right);
        //The difference between heights of left subtree and right subtree is no more
        //than 1.
        return abs(left - right) <= 1 && balanced(node->left) && balanced(node->right);
    }
    
    
	 // Precondition: none
	 // Postcondition: return true if the tree is balanced; return false otherwise.	
	
    ~BST(){
        destroyRecursively(root);
    }
	//Precondition: none
	//Postcondition: Memory addresses allocated for bst object has been returned to heap.

};

#endif

#include "BST.cpp"

