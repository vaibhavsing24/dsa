#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool rightThread;
};

Node* createThreadedTree(int *arr, int n) {
    if (n == 0) {
        return nullptr;
    }

    Node* root = new Node;
    root->data = arr[0];
    root->left = nullptr;
    root->right = nullptr;
    root->rightThread = true;

    Node* prev = root;
    for (int i = 1; i < n; i++) {
        Node* curr = new Node;
        curr->data = arr[i];
        curr->left = nullptr;
        curr->right = nullptr;
        curr->rightThread = true;

        // Insert curr as right child of prev if it's greater than prev
        if (curr->data > prev->data) {
            prev->right = curr;
            prev->rightThread = false;
        } else {
            // Find the appropriate position to insert curr in the left subtree
            Node* temp = root;
            while (temp->right != nullptr && temp->data < curr->data) {
                temp = temp->right;
            }
            curr->left = temp->right;
            temp->right = curr;
            temp->rightThread = false;
        }

        prev = curr;
    }

    return root;
}

void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    int arr[] = {10, 5, 15, 3, 8, 12, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = createThreadedTree(arr, n);

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    // Deallocate memory
    Node* current = root;
    while (current != nullptr) {
        Node* next = current->right;
        if (!current->rightThread) {
            next = current->right; // Move to the actual right child
        }
        delete current;
        current = next;
    }

    return 0;
}
