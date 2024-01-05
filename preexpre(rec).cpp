#include <iostream>
#include <cctype>

using namespace std;

// Expression Tree Node
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node
TreeNode* createNode(string value) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


// Recursive helper function to construct Expression Tree from prefix expression
TreeNode* constructExpressionTreeHelper(string prefix, int& index) {
    if (index >= prefix.length()) {
        return NULL;
    }

    TreeNode* newNode = createNode(string(1, prefix[index++]));

    if (isOperator(newNode->value[0])) {
        newNode->left = constructExpressionTreeHelper(prefix, index);
        newNode->right = constructExpressionTreeHelper(prefix, index);
    }

    return newNode;
}

// Function to construct Expression Tree from prefix expression
TreeNode* constructExpressionTree(string prefix) {
    if (prefix.empty()) {
        return NULL;
    }

    int index = 0;
    return constructExpressionTreeHelper(prefix, index);
}


// Recursive Inorder traversal of Expression Tree
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

// Recursive Preorder traversal of Expression Tree
void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Recursive Postorder traversal of Expression Tree
void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value << " ";
    }
}

int main() {
    string prefixExpression = "*+abc*de";
    TreeNode* root = constructExpressionTree(prefixExpression);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
