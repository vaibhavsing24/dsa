#include <iostream>
#include <string>

using namespace std;

// NOTE:
// Use Stack as an ADT

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return '\0';
        } else {
            Node* temp = top;
            char popped = temp->data;
            top = top->next;
            delete temp;
            return popped;
        }
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return '\0';
        } else {
            return top->data;
        }
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix) {
    Stack stack;
    string postfix;

    for (char& character : infix) {
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9')) {
            postfix += character;
        } else if (character == '(') {
            stack.push(character);
        } else if (character == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            if (!stack.isEmpty() && stack.peek() != '(') {
                return "Invalid expression.";
            } else {
                stack.pop();
            }
        } else {
            while (!stack.isEmpty() && precedence(character) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(character);
        }
    }

    while (!stack.isEmpty()) {
        if (stack.peek() == '(' || stack.peek() == ')') {
            return "Invalid expression.";
        }
        postfix += stack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    if (postfixExpression != "Invalid expression.") {
        cout << "The postfix expression is: " << postfixExpression << endl;
    } else {
        cout << "Invalid expression.\n";
    }

    return 0;
}
