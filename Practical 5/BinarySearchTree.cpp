Assignment 5 - Binary search tree
AIM : Implementation In-order Threaded Binary Tree (TBT)

#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data=value;
        left=nullptr;
        right=nullptr;
    } 
}; 
class BST{
    private:
    struct Node * head;
    public :
    BST(){
        head=NULL;
    }
    Node* insert(Node* root, int value);
    Node* search(Node* root, int value);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, int value);
    void inOrder(Node* root);
    void postOrder(Node* root) ;
    void preOrder(Node* root) ;
    int depth(Node* root);
    void mirror(Node* root) ;
    void displayLeafNodes(Node* root);
    void displayLevelWise(Node* root);
    void displayParents(Node* root);

};
Node * BST :: insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
 
Node * BST :: search(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}
  
Node * BST ::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
 
Node * BST :: deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else { 
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
 
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 
void BST :: inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
} 
void BST :: preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
} 
void BST :: postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
} 
int BST :: depth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return max(leftDepth, rightDepth) + 1;
} 
void BST :: mirror(Node* root) {
    if (root == nullptr) {
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
} 
 
void BST :: displayParents(Node* root) {
    if (root == nullptr) return;
    if (root->left != nullptr || root->right != nullptr) {
        cout << root->data << ": ";
        if (root->left != nullptr) cout << "L" << root->left->data << " ";
        if (root->right != nullptr) cout << "R" << root->right->data << " ";
        cout << endl;
    }
    displayParents(root->left);
    displayParents(root->right);
} 
void BST :: displayLevelWise(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    if (root->left != nullptr) cout << root->left->data << " ";
    if (root->right != nullptr) cout << root->right->data << " ";
    displayLevelWise(root->left);
    displayLevelWise(root->right);
}
 
void BST :: displayLeafNodes(Node* root) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
    }
    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}
 
int main() {
    Node* root = nullptr;
    int choice, value;
    BST b;

    while (true) {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display In-Order Traversal\n";
        cout << "5. Display Tree Depth\n6. Display Leaf Nodes\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = b.insert(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = b.deleteNode(root, value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (b.search(root, value) != nullptr)
                    cout << "Value found in the tree.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 4:
                cout << "In-order Traversal: ";
                b.inOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Depth of the tree: " << b.depth(root) << endl;
                break;
            case 6:
                cout << "Leaf Nodes: ";
                b.displayLeafNodes(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
        return 0;
}


/* OUTPUT:


Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 1
Enter value to insert: 50

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 1
Enter value to insert: 30

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 1
Enter value to insert: 70

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 1
Enter value to insert: 20

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 1
Enter value to insert: 40

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 1
Enter value to insert: 60

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 1
Enter value to insert: 80

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 4
In-order Traversal: 20 30 40 50 60 70 80 

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 3
Enter value to search: 40
Value found in the tree.

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 2
Enter value to delete: 20

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 5
Depth of the tree: 3

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 6
Leaf Nodes: 40 60 80 

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display In-Order Traversal
5. Display Tree Depth
6. Display Leaf Nodes
7. Exit
Enter your choice: 7
Exiting...
*/
