#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

void inorder_travel(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder_travel(root->left);
    cout << root->data << " ";
    inorder_travel(root->right);
}

int main() {
    Node* root = nullptr;
    int n;
    
    cout << "number of elements: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        root = insert(root, t);
    }

    cout << "Inorder traversal (sorted elements): ";
    inorder_travel(root);
    cout << endl;

    return 0;
}
