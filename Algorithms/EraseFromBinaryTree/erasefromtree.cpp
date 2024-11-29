#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(Node*& node, int val) {
        if (node == nullptr) {
            node = new Node(val);
            return;
        }
        if (val < node->key) {
            insert(node->left, val);
        } else if (val > node->key) {
            insert(node->right, val);
        }
    }

    Node* erase(Node* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }

        if (val < node->key) {
            node->left = erase(node->left, val);
        } else if (val > node->key) {
            node->right = erase(node->right, val);
        } else {
            if (node->left == nullptr) {
                Node* rightChild = node->right;
                delete node;
                return rightChild;
            }
            if (node->right == nullptr) {
                Node* leftChild = node->left;
                delete node;
                return leftChild;
            }

            Node* minNode = find_min(node->right);
            node->key = minNode->key;
            node->right = erase(node->right, minNode->key);
        }
        return node;
    }

    Node* find_min(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void preorder_traversal(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(node->key);
        preorder_traversal(node->left, result);
        preorder_traversal(node->right, result);
    }
};

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    vector<int> keys;

    if (input.is_open()) {
        int val;
        while (input >> val) {
            keys.push_back(val);
        }
        input.close();
    }

    BinaryTree bst;

    for (size_t i = 1; i < keys.size(); ++i) {
        bst.insert(bst.root, keys[i]);
    }

    if (!keys.empty()) {
        bst.root = bst.erase(bst.root, keys[0]);
    }

    vector<int> result;
    bst.preorder_traversal(bst.root, result);

    if (output.is_open()) {
        for (int key : result) {
            output << key << endl;
        }
        output.close();
    }

    return 0;
}
