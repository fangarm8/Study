#include <iostream>
#include <fstream>

struct node {
    int key;
    node* left;
    node* right;
    node(int key){
        this->key = key; left = nullptr; right = nullptr;
    }
};

using namespace std;

node * insert(node * root, int key) {
    if (root == nullptr) return new node(key);
    if (key < root->key){
        root->left = insert(root->left, key);
    }
    else if (key == root->key){
        return root;
    }
    else {
        root->right = insert(root->right, key);
    }
    return root;
}

void preorder_traversal(node * root, ofstream& out) {
    if (root != nullptr) {
        out << root->key << '\n';
        preorder_traversal(root->left, out);
        preorder_traversal(root->right, out);
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    node * root = nullptr;
    while(!in.eof()) {
        int tmp;
        in >> tmp;
        root = insert(root, tmp);
    }

    preorder_traversal(root, out);
}