class Node:
    def __init__(self, val):
        self.key = val
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, node, val):
        if self.root is None:
            self.root = Node(val)
            return
        if val < node.key:
            if node.left is None:
                node.left = Node(val)
            else:
                self.insert(node.left, val)
        elif val > node.key:
            if node.right is None:
                node.right = Node(val)
            else:
                self.insert(node.right, val)
    
    def erase(self, node, val):
        if node is None:
            return None        
        if val < node.key:
            node.left = self.erase(node.left, val)
        elif val > node.key:
            node.right = self.erase(node.right, val)
        else:
            if node.left is None:
                return node.right
            if node.right is None:
                return node.left
            node.key = self.find_min(node.right).key
            node.right = self.erase(node.right, node.key)
        return node

    def find_min(self, node):
        if node.left is not None:
            return self.find_min(node.left)
        return node

    def preorder_traversal(self):
        result = []
        self._preorder_recursive(self.root, result)
        return result

    def _preorder_recursive(self, node, result):
        if node is not None:
            result.append(node.key)
            self._preorder_recursive(node.left, result)
            self._preorder_recursive(node.right, result)

keys = []
with open('input.txt', 'r') as file:
    for line in file:
        if line != '\n':
            keys.append(int(line.strip()))

bst = BinaryTree()
for i in range(1, len(keys)):
    bst.insert(bst.root, keys[i])

bst.root = bst.erase(bst.root, keys[0])

result = bst.preorder_traversal()
with open('output.txt', 'w') as file:
    for key in result:
        file.write(str(key) + '\n')