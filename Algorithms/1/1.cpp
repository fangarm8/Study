#include <iostream>
#include <fstream>
#include <vector>

struct Node {
    Node * parent;
    bool LorR;
    
    int key;
    
    Node* left;
    int Lson;
    
    Node* right;
    int Rson;

    Node(int val, Node* par, bool son) {
        parent= par;
        LorR = son;
        key = val;
        left = nullptr;
        Lson = 0;
        right = nullptr;
        Rson = 0;
    }

    void addL(int val) {
        Node * tmp = new Node(val, this, 0);
        left = tmp;
        Lson += 1;
        Node * node_par = parent;
        Node * node_child = this;
        while (node_par != nullptr) {
            if (node_child->LorR == 0)
                node_par->Lson += 1;
            else
                node_par->Rson += 1;
            node_child = node_par;
            node_par = node_par->parent;
        }
    }

    void addR(int val) {
        Node * tmp = new Node(val, this, 1);
        right = tmp;
        Rson += 1;
        Node * node_par = parent;
        Node * node_child = this;
        while (node_par != nullptr) {
            if (node_child->LorR == 0)
                node_par->Lson += 1;
            else
                node_par->Rson += 1;
            node_child = node_par;
            node_par = node_par->parent;
        }
    }
};

using namespace std;

struct bst {
    Node * root;
    
    bst() {
        root = nullptr;
    }
    
    void insert(int val, Node * tmp) {
        if (root == nullptr) {
            root = new Node(val, nullptr, 0);
        } else {
            if (tmp->key > val) {
                if (tmp->left)
                    this->insert(val, tmp->left);
                else
                    tmp->addL(val);
            } else if (tmp->key < val) {
                if (tmp->right)
                    this->insert(val, tmp->right);
                else
                    tmp->addR(val);
            }
        }
    }

    void pt(vector<int>& res, Node* tmp) {
        res.push_back(tmp->key);
        if (tmp->left)
            this->pt(res, tmp->left);
        
        if (tmp->right)
            this->pt(res, tmp->right);
    }

    void it(vector<Node*>& res, Node* tmp) {
        if (tmp) {
            this->it(res, tmp->left);
            if (tmp->Lson != tmp->Rson)
                res.push_back(tmp);
            this->it(res, tmp->right);
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
};

int main() {
    ifstream in("in.txt");
    bst tree;
    int tmp;
    while (in >> tmp)
        tree.insert(tmp, tree.root);
    in.close();
    vector<Node*> sons;
    tree.it(sons, tree.root);
    Node * avg;
    if (sons.size() % 2 == 0)
        avg = nullptr;
    else {
        avg = sons[sons.size() / 2];
        tree.root = tree.erase(tree.root, avg->key);
    }
    vector<int> res;
    tree.pt(res, tree.root);
    ofstream out("out.txt");
    for (auto v : res)
        out << v << "\n";
}