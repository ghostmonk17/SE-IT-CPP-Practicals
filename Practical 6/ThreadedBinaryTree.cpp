// Assignment 6- Threaded Binary Tree
// AIM : Implementation In-order Threaded Binary Tree (TBT)

#include <iostream>
using namespace std;
 
struct TBTNode {
    int data;
    TBTNode *left, *right;
    bool lt, rt; 
};
 
class TBT {
private:
    TBTNode *root;
 
    TBTNode* createNode(int data) {
        TBTNode* newNode = new TBTNode();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->lt = true;  
        newNode->rt = true; 
        return newNode;
    }
 
    void insertR(TBTNode *&node, int data) {
        if (node == nullptr) {
            node = createNode(data);
            return;
        }

        if (data < node->data) {
            insertR(node->left, data);
        } else {
            insertR(node->right, data);
        }
 
        if (node->left == nullptr) {
            node->lt = true; 
        }
        if (node->right == nullptr) {
            node->rt = true;  
        }
    }
 
    void inorderT(TBTNode *node) {
        if (node == nullptr) return;
 
        while (node->left != nullptr) {
            node = node->left;
        } 
        while (node != nullptr) {
            cout << node->data << " "; 
            if (node->rt) {
                node = node->right;
            } else {
                node = node->right; 
                while (node != nullptr && node->left != nullptr) {
                    node = node->left;
                }
            }
        }
    }
 
    void preT(TBTNode *node) {
        if (node == nullptr) return;

        cout << node->data << " ";  
        if (!node->lt) preT(node->left);    
        if (!node->rt) preT(node->right);  
    }

public:
    TBT() {
        root=nullptr;
    }  
 
    void insert(int data) {
        insertR(root, data);
    }
 
    void inOrder() {
        cout << "In-order Traversal: ";
        inorderT(root);
        cout << endl;
    }
 
    void preOrder() {
        cout << "Pre-order Traversal: ";
        preT(root);
        cout << endl;
    }
};

int main() {
    TBT tree;
    int n, value;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;  

    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;  
        tree.insert(value);
    }

    tree.inOrder();  
    tree.preOrder();  

    return 0;
}

/* OUTPUT:

Enter the number of nodes to insert: 5
Enter value for node 1: 10
Enter value for node 2: 5
Enter value for node 3: 15
Enter value for node 4: 3
Enter value for node 5: 7 

In-order Traversal: 3 5 7 10 15 
Pre-order Traversal: 10 5 3 7 15 
*/
