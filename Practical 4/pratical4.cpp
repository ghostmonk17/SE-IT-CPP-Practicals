/* Assignment 4 – Expression Tree and Tree Traversals
AIM : To construct an expression tree and perform recursive and non-recursive traversals.
  */

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

class ExpressionTree {
private:
    Node* root;

public:
    ExpressionTree() {
       root=nullptr;
    }
        

    Node* constructPostfix(const char* postfix) {
        Node* stack[100]; 
        int top = -1;
        for (int i = 0; postfix[i] != '\0'; i++) {
            char ch = postfix[i];
            if (isalnum(ch)) {
                stack[++top] = new Node(ch);
            } else {
                Node* node = new Node(ch);
                node->right = stack[top--];
                node->left = stack[top--];
                stack[++top] = node;
            }
        }
        root = stack[top];
        return root;
    }

    Node* constructPrefix(const char* prefix) {
        Node* stack[100];
        int top = -1;
        for (int i = strlen(prefix) - 1; i >= 0; i--) {
            char ch = prefix[i];
            if (isalnum(ch)) {
                stack[++top] = new Node(ch);
            } else {
                Node* node = new Node(ch);
                node->left = stack[top--];
                node->right = stack[top--];
                stack[++top] = node;
            }
        }
        root = stack[top];
        return root;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void inorderNonRecursive() {
        Node* stack[100];
        int top = -1;
        Node* current = root;
        while (current || top != -1) {
            while (current) {
                stack[++top] = current;
                current = current->left;
            }
            current = stack[top--];
            cout << current->data << " ";
            current = current->right;
        }
    }

    void preorderNonRecursive() {
        Node* stack[100];
        int top = -1;
        stack[++top] = root;
        while (top != -1) {
            Node* node = stack[top--];
            if (node) {
                cout << node->data << " ";
                stack[++top] = node->right;
                stack[++top] = node->left;
            }
        }
    }

    void postorderNonRecursive() {
        Node* stack1[100];
        Node* stack2[100];
        int top1 = -1, top2 = -1;
        stack1[++top1] = root;
        while (top1 != -1) {
            Node* node = stack1[top1--];
            if (node) {
                stack2[++top2] = node;
                stack1[++top1] = node->left;
                stack1[++top1] = node->right;
            }
        }
        while (top2 != -1) {
            cout << stack2[top2--]->data << " ";
        }
    }

    void inorderTraversal() {
        cout << "In-order (Recursive): ";
        inorder(root);
        cout << endl;
        cout << "In-order (Non-Recursive): ";
        inorderNonRecursive();
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Pre-order (Recursive): ";
        preorder(root);
        cout << endl;
        cout << "Pre-order (Non-Recursive): ";
        preorderNonRecursive();
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Post-order (Recursive): ";
        postorder(root);
        cout << endl;
        cout << "Post-order (Non-Recursive): ";
        postorderNonRecursive();
        cout << endl;
    }
};

int main() {
    ExpressionTree tree;
    string postfix, prefix;

    cout << "Enter postfix expression: ";
    cin >> postfix;
    tree.constructPostfix(postfix.c_str());
    cout << "\nExpression Tree from Postfix:\n";
    tree.inorderTraversal();
    tree.preorderTraversal();
    tree.postorderTraversal();

    cout << "\n\nEnter prefix expression: ";
    cin >> prefix;
    tree.constructPrefix(prefix.c_str());
    cout << "\nExpression Tree from Prefix:\n";
    tree.inorderTraversal();
    tree.preorderTraversal();
    tree.postorderTraversal();

    return 0;
}

/* OUTPUT:

Enter postfix expression: ab+cde+**

Expression Tree from Postfix:
In-order (Recursive): a + b * c * d + e 
In-order (Non-Recursive): a + b * c * d + e 
Pre-order (Recursive): * + a b * c + d e 
Pre-order (Non-Recursive): * + a b * c + d e 
Post-order (Recursive): a b + c d e + * * 
Post-order (Non-Recursive): a b + c d e + * * 


Enter prefix expression: *+abc+de

Expression Tree from Prefix:
In-order (Recursive): a + b * c 
In-order (Non-Recursive): a + b * c 
Pre-order (Recursive): * + a b c 
Pre-order (Non-Recursive): * + a b c 
Post-order (Recursive): a b + c * 
Post-order (Non-Recursive): a b + c * 
*/
