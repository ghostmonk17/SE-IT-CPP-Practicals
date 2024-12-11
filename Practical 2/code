/*Implement stack as an abstract data type using singly linked list and use this ADT for conversion of
infix expression to postfix, prefix and evaluation of postfix and prefix expression
*/


#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(char value) {
        Node* newNode = new Node{value, top};
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is Empty");
        }
        Node* temp = top;
        char value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is Empty");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infix_to_postfix(const string& infix, string& postfix) {
    Stack operators;
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                postfix += operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(ch)) {
                postfix += operators.pop();
            }
            operators.push(ch);
        }
    }
    while (!operators.isEmpty()) {
        postfix += operators.pop();
    }
}

void infix_to_prefix(const string& infix, string& prefix) {
    string reversedInfix = string(infix.rbegin(), infix.rend());
    for (char& ch : reversedInfix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    string postfix;
    infix_to_postfix(reversedInfix, postfix);
    prefix = string(postfix.rbegin(), postfix.rend());
}

int main() {
    string infix, postfix, prefix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    infix_to_postfix(infix, postfix);
    cout << "Postfix: " << postfix << endl;

    infix_to_prefix(infix, prefix);
    cout << "Prefix: " << prefix << endl;

    return 0;
}
   
