class node:
    def __init__(self, val):
        self.key = val
        self.right = None
        self.left = None

def insert(val, root):
    if root is None:
        root = node(val)
    else:
        if val < root.key:
            root.left = insert(val, root.left)
        elif val == root.key:
            return
        else:
            root.right = insert(val, root.right)
    return root

def preorder_traversal(root, result):
    if root is not None:
        result.append(root.key)
        preorder_traversal(root.left, result)
        preorder_traversal(root.right, result)
        
with open('input.txt', 'r') as file:
    keys = [int(line) for line in file]

root = None

for key in keys:
    root = insert(key, root)

result = []

preorder_traversal(root, result)

with open('output.txt', 'w') as file:
    for key in result:
        file.write(str(key) + '\n')

