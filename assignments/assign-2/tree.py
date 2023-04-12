class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def printTree(node, level=0):
    if node != None:
        printTree(node.left, level + 1)
        print(' ' * 4 * level + '-> ' + str(node.value))
        printTree(node.right, level + 1)


t = Node(1, Node(2, Node(4, Node(7)), Node(9)),
         Node(3, Node(5), Node(6, Node(10), Node(11))))
printTree(t)
