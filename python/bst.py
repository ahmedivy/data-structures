class Node:

    def __init__(self, data):
        self.data = data
        self.left: Node = None
        self.right: Node = None


class BST:

    def __init__(self) -> None:
        self.root: Node = None

    def insert(self, data):
        node = Node(data)
        if not self.root:
            self.root = node
            return
        curr = self.root
        while curr:
            if data < curr.data:
                if not curr.left:
                    curr.left = node
                    break
                curr = curr.left
            elif data > curr.data:
                if not curr.right:
                    curr.right = node
                    break
                curr = curr.right

    def in_order(self):
        def print_node(node: Node):
            if node:
                print_node(node.left)
                print(node.data, end=" ")
                print_node(node.right)
        print_node(self.root)

    def print(self):
        def print_node(node, level=0, is_left=False):
            if not node:
                return
            print_node(node.right, level + 1, False)
            prefix = "    " * (level - 1)
            prefix += ("└── " if is_left else "┌── ") if level > 0 else ""
            print(prefix + str(node.data))
            print_node(node.left, level + 1, True)

        print_node(self.root)

    @property
    def total_nodes(self):
        def count(node):
            return 0 if not node else 1 + count(node.left) + count(node.right)
        return count(self.root)

    @property
    def height(self):
        def height(node):
            return 0 if not node else 1 + max(height(node.left), height(node.right))
        return height(self.root)


def main():
    tree = BST()
    tree.insert(4)
    tree.insert(3)
    tree.insert(7)

    tree.print()

    print(f'Height: {tree.height}')
    print(f'Nodes: {tree.total_nodes}')


if __name__ == "__main__":
    main()
