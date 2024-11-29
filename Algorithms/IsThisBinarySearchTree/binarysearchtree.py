def is_bst(tree, node_index, min_key, max_key):
    if node_index == -1:
        return True

    key, left, right = tree[node_index]

    if not (min_key <= key < max_key):
        return False

    return (is_bst(tree, left, min_key, key) and
            is_bst(tree, right, key, max_key))

def main():
    tree = []

    with open('input.txt', 'r') as file:
        n = int(file.readline())
        if n == 0:
            print('YES')
            return
        root_key = int(file.readline())
        tree.append((root_key, -1, -1))
        
        for _ in range(2, n+1):
            key, parent, child_type = file.readline().split()
            key = int(key)
            parent = int(parent)

if __name__ == "__main__":
    main()