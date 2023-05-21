from typing import Generator


class Node:
    def __init__(self, data):
        self.data = data
        self.next: Node = None
        self.prev: Node = None

    def __str__(self) -> str:
        return str(self.data)

    def __eq__(self, other) -> bool:
        return self.data == (other.data if type(other) == Node else other)

    def __ne__(self, other) -> bool:
        return not (self == other)


class LinkedList:

    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.size = 0

    def __len__(self) -> int:
        return self.size

    def __str__(self) -> str:
        return "[" + ", ".join([str(node) for node in self]) + "]"

    def __iter__(self) -> Generator:
        curr = self.head
        while curr:
            yield curr
            curr = curr.next

    def __reversed__(self):
        curr = self.tail
        while curr:
            yield curr
            curr = curr.prev

    def __setitem__(self, ix, value):
        self.find_(ix).data = value

    def __getitem__(self, ix):
        return self.find_(ix).data

    def find_(self, ix):
        itr = enumerate(self if ix > -1 else reversed(self))
        ix = ix if ix > -1 else abs(ix + 1)
        for i, node in itr:
            if i == ix:
                return node

    def __contains__(self, key):
        return any([node == key for node in self])

    def __delitem__(self, index):
        return self.pop(index)

    def insert(self, index, data):
        if not self or index >= self.size:
            self.append(data)
            return

        node = Node(data)
        if index == 0:
            node.next = self.head
            self.head.prev = node
            self.head = node
        else:
            curr = self.find_(index - 1)
            node.next = curr.next
            node.prev = curr
            curr.next = node
        self.size += 1

    def append(self, data):
        node = Node(data)
        if not self:
            self.head = self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
        self.size += 1

    def pop(self, index=-1):
        if index not in range(-self.size, self.size):
            raise IndexError(f"Index {index} is out of range")

        node = None
        # If only one element in list
        if self.size == 1:
            node = self.head
            self.head = self.tail = None
        # If removing first element
        elif index == 0:
            node = self.head
            self.head = self.head.next
            self.head.prev = None
        # If removing last element
        elif index == self.size - 1 or index == -1:
            node = self.tail
            self.tail = self.tail.prev
            self.tail.next = None
        # If somewhere in middle
        else:
            curr = self.head if index > -1 else self.tail
            itr = range((index if index > -1 else abs(index)) - 1)
            for _ in itr:
                curr = curr.next if index > -1 else curr.prev
            curr.prev.next = curr.next
            curr.next.prev = curr.prev
            node = curr

        self.size -= 1
        return node.data
