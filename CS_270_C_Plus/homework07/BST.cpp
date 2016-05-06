
//#include "BST.h"

template <class T>
void BST<T>::preOrder(Node* nodePtr){
	
	if (nodePtr){
		
		cout << nodePtr->key << endl;
		
		preOrder(nodePtr->left);
		
		preOrder(nodePtr->right);
    }
}

template <class T>
void BST<T>::postOrder(Node* nodePtr){
	
	if (nodePtr){
		
		postOrder(nodePtr->left);
		
		postOrder(nodePtr->right);
		
		cout << nodePtr->key << endl;
    }
}


template <class T>
void BST<T>::destroyRecursively(Node *node){
    if(node){
        if(node->left)
            //destroy the left side recurisevely
            destroyRecursively(node->left);
        if(node->right)
            //destroy the right side recursively
            destroyRecursively(node->right);
        delete node;
    }
}

template <class T>
void BST<T>::inOrder(Node* nodePtr){
	
	if (nodePtr){
		
		inOrder(nodePtr->left);
		
		cout << nodePtr->key << endl;
		
		inOrder(nodePtr->right);
    }
}


template <class T>
void BST<T> ::transplant(Node* u, Node* v){
    if(u->parent == NULL)
        root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v != NULL)
        v->parent = u->parent;
}



template <class T>
void BST<T> :: insertNode(T item){
	Node *newNode,*nodePtr;
	newNode = new Node;
	newNode->key = item;
	newNode->left = newNode->right = NULL;
	if (!root){
		root = newNode;
	}
	else {
		nodePtr = root; 
		while (nodePtr != NULL){
            if (item < nodePtr->key){
                if (nodePtr->left) 
					nodePtr = nodePtr->left;
                else{
					nodePtr->left = newNode;
					break;
                }
            }
            else if (item > nodePtr->key){
                if (nodePtr->right){
					nodePtr = nodePtr->right;
                }
                else{
					nodePtr->right = newNode;
					break;
                }
			}
        } // endl while
    }// end if tree is nonempty
} //end insertNode


