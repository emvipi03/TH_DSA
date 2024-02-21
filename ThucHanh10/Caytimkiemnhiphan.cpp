#include <iostream>
//#include <conio.h>
#include <assert.h>

using namespace std;

template <class T>
struct NodeBST {
    NodeBST(T k){
        key = k;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    T key;
    NodeBST<T> *parent;
    NodeBST<T> *left;
    NodeBST<T> *right;
};

template <class T>
NodeBST<T> * find(NodeBST<T> * n, T k);

template <class T>
void insert(NodeBST<T> * & n, T k);

template <class T>
void erase(NodeBST<T> * & n, T k);

template <class T>
T min(NodeBST<T> * n);

template <class T>
T max(NodeBST<T> * n);

template <class T>
T predecessor(NodeBST<T> * n, T k);

template <class T>
T successor(NodeBST<T> * n, T k);

template <class T>
void inOrder(NodeBST<T> * n);

template <class T>
bool isLeave(NodeBST<T> * n);

template <class T>
bool isRoot(NodeBST<T> * n);

template <class T>
bool isLeftChild(NodeBST<T> * n);

template <class T>
bool isRightChild(NodeBST<T> * n);

template <class T>
void createBST(NodeBST<T> * & n) {
    insert(n, 4); cout << "4\n";
    insert(n, 2); cout << "2\n";
    insert(n, 6); cout << "6\n";
    insert(n, 1); cout << "1\n";
    insert(n, 3); cout << "3\n";
    insert(n, 5); cout << "5\n";
    insert(n, 7); cout << "7\n";
    insert(n, 8); cout << "8\n";
}

// Chuong trinh chinh
int main(){
	NodeBST<int> * node = NULL;
	createBST(node);
	cout << "inOrder: "; inOrder(node); cout << "\n";
	cout << "min = " << min(node) << "\n";
	cout << "max = " << max(node) << "\n";
	cout << "predecessor = " << predecessor(node, 1) << "\n";
	cout << "successor = " << successor(node, 7) << "\n";
	cout << "erase 4"; erase(node, 4);
	cout << "inOrder: "; inOrder(node); cout << "\n";
	
	
    
	cout << "erase 8 "; erase(node, 8);
	cout << "inOrder: "; inOrder(node); cout << "\n";
    cout << "erase 1 "; erase(node, 1);
	cout << "inOrder: "; inOrder(node); cout << "\n";
    
	return 0;
}

template <class T>
NodeBST<T> * find(NodeBST<T> *n, T k) {
    NodeBST<T> *tmp = n;
    while (tmp->key != k) {
        if (tmp->key > k) {
        	tmp = tmp->left;
		}
		else tmp = tmp->right;
    }
    return (tmp);
}

template <class T>
void insert(NodeBST<T> * & n, T k) {
    if (n == NULL) {
        n = new NodeBST<T>(k);
        return;
    }
    else {
        NodeBST<T> *tmp = n;
        do {
            if (tmp->key >= k) {
                if (tmp->left == NULL) {
                	NodeBST<T> *p = new NodeBST<T>(k);
                	p->parent = tmp;
                	tmp->left = p;
                	return;
 				} else tmp = tmp->left;
            }
            else {
                if (tmp->right == NULL) {
                	NodeBST<T> *p = new NodeBST<T>(k);
                	p->parent = tmp;
                	tmp->right = p;
                	return;
 				} else tmp = tmp->right;
            }
        // sua dieu kien cua while
        } while (true);
    }
}

template <class T>
void erase(NodeBST<T> * & n, T k) {
    NodeBST<T> *node = find(n, k);

    // khong tim thay gia tri can xoa
    if (node == NULL) return;

    // nut can xoa (node) la la
    if (isLeave(node)) {
        if (node->parent == NULL) {
            // This is the root node
            delete node;
            return;
        }
        if (node->parent->left == node) {
            // This is the left child of its parent
            node->parent->left = NULL;
        } else {
            // This is the right child of its parent
            node->parent->right = NULL;
        }
        delete node;
        return;
    }

    // nut can xoa (node) la dinh trong khong co con trai (left = NULL)
    if (node->left == NULL) {
        if (isLeftChild(node)) {
        	node->parent->left = node->right;
		} else node->parent->right = node->right;
        return;
    }

    // nut can xoa (node) la dinh trong khong co con phai (right = NULL)
    if (node->right == NULL) {
        if (isLeftChild(node)) {
        	node->parent->left = node->left;
		} else node->parent->right = node->left;
        return;
    }

    // nut can xoa (node) la dinh trong co 2 con
    NodeBST<T> *tmp = node->right;
    while(tmp->left->left != NULL) {
    	tmp = tmp->left;
	}
	node->key = tmp->left->key;
	tmp->left = NULL;
	delete tmp->left;
	return;
    
    
}

template <class T>
T min(NodeBST<T> *n) {
    assert(n != NULL);
    NodeBST<T> *tmp = n;
    while (tmp->left != NULL) {
    	tmp = tmp->left;
	}
    return (tmp->key);
}

template <class T>
T max(NodeBST<T> * n) {
    assert(n != NULL);
    NodeBST<T> * tmp = n;
    while (tmp->right != NULL) {
    	tmp = tmp->right;
	}
    return (tmp->key);
}

template <class T>
T predecessor(NodeBST<T> * n, T k) {
    NodeBST<T> * node = find(n, k);
    assert (node != NULL);
    NodeBST<T> * tmp = node;
    /*
        ma cua ban vao day
    */
    return (tmp->key);
}

template <class T>
T successor(NodeBST<T> * n, T k) {
    NodeBST<T> * node = find(n, k);
    assert (node != NULL);
    NodeBST<T> * tmp = node;
    
    return (tmp->key);
}

template <class T>
bool isLeave(NodeBST<T> *node) {
	if (node->left == NULL && node->right == NULL)
    return true;
    else return false;
}

template <class T>
bool isRoot(NodeBST<T> *node) {
    if (node->parent == NULL)
    return true;
    else return false;
}

template <class T>
bool isLeftChild(NodeBST<T> *node) {
    if (node->parent->left->key == node->key)
        return true;
    else return false;    
}

template <class T>
bool isRightChild(NodeBST<T> *node) {
    if (node->parent->right->key == node->key)
    return true;
    else return false;
}

template <class T>
void inOrder(NodeBST<T> * node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}

/*
void insert(NodeBST<T> * & n, T k) {
    if (n == NULL) {
        n = new NodeBST<T>(k);
        return;
    }
    else {
        NodeBST<T> *tmp = n;
        if (k <= tmp->key) {
            if (tmp->left == NULL) {   
        	    tmp->left = new NodeBST<T>(k);
            	tmp->left->parent = tmp;
        	} else {
            insert(tmp->left, k);
        	}
    	}
    	else {
        	if (tmp->right == NULL) {  
            	tmp->right = new NodeBST<T>(k);
            	tmp->right->parent = tmp;
        	}
        	else {
            	insert(tmp->right, k);
        	}
    	}
	}
}
*/
