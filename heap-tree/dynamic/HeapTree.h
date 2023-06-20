#include <iostream>
#include "queue"
#include "cmath"
class HeapTree
{
private:
    class Node
    {
    public:
        int key = 0;
        Node *left = nullptr, *right = nullptr;
        Node(int data) { this->key = data; }
        ~Node() {}
    };


public:
    Node *root = nullptr, *lastNode = nullptr;
    HeapTree() {}
    ~HeapTree() {}
    void insert(int value);
    Node *getParent(Node *root, Node *node);
    bool isLeft(Node *parent, Node *node);
    bool isRight(Node *parent, Node *node);
    void heapifyUp(Node *node);
    void heapifyDown(Node *node);
    int deletion();
    void print(Node *node = nullptr);

};

void HeapTree::insert(int value)
{
    Node *newNode = new Node(value);
    if (this->root == nullptr)
    {
        this->root = newNode;
        this->lastNode = newNode;
        return;
    }
    if(root==lastNode)
    {
        root->left = newNode;
        lastNode = newNode;
        heapifyUp(newNode);
        return;
    }
    Node *parent = getParent(this->root, lastNode);
    if (isLeft(parent, lastNode))
    {
        parent->right = newNode;
    }
    else
    {
        Node *node = parent;
        parent = getParent(this->root, node);
        while (node != this->root && !isLeft(parent, node))
        {
            node = parent;
            parent = getParent(this->root, node);
        }

        if (node == root)
        {
            while (node->left != nullptr)
            {
                node = node->left;
            }

            node->left = newNode;
        }
        else
        {
            node = parent->right;
            while (node->left != nullptr)
            {
                node = node->left;
            }

            node->left = newNode;
        }
    }

    heapifyUp(newNode);
    lastNode = newNode;
}

int HeapTree::deletion()
{
    if (this->root == nullptr)
    {
        return -1;
    }

    int temp = this->root->key;
    this->root->key = this->lastNode->key;
    this->lastNode->key = temp;

    Node *parent = getParent(this->root, this->lastNode);
    if (isRight(parent, this->lastNode))
    {
        parent->right = nullptr;
        lastNode = parent->left;
    }
    else
    {
        parent->left = nullptr;
        Node *node = parent;
        parent = getParent(this->root, node);
        while (node != this->root && !isRight(parent, node))
        {
            node = parent;
            parent = getParent(this->root, node);
        }
        if (node == this->root)
        {
            while (node->right != nullptr)
            {
                node = node->right;
            }
            lastNode = node;
        }
        else
        {
            node = parent->left;
            while (node->right != nullptr)
            {
                node = node->right;
            }
            lastNode = node;
        }
    }
    heapifyDown(this->root);
    return temp;
}

void HeapTree::heapifyUp(HeapTree::Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    Node *parent = getParent(this->root, node);
    if (parent == nullptr)
    {
        return;
    }

    if (parent->key < node->key)
    {
        int temp = parent->key;
        parent->key = node->key;
        node->key = temp;
        heapifyUp(parent);
    }
}

void HeapTree::heapifyDown(HeapTree::Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    Node *left = node->left;
    Node *right = node->right;
    Node *largest = node;

    if (left != nullptr && left->key > largest->key)
    {
        largest = left;
    }

    if (right != nullptr && right->key > largest->key)
    {
        largest = right;
    }

    if (largest != node)
    {
        int temp = largest->key;
        largest->key = node->key;
        node->key = temp;
        heapifyDown(largest);
    }
}
HeapTree::Node *HeapTree::getParent(HeapTree::Node *root, HeapTree::Node *node)
{
    if (root == nullptr || root == node)
    {
        return nullptr;
    }

    if (root->left == node || root->right == node)
    {
        return root;
    }

    Node *left = getParent(root->left, node);
    Node *right = getParent(root->right, node);

    if (left != nullptr)
    {
        return left;
    }

    if (right != nullptr)
    {
        return right;
    }

    return nullptr;
}

bool HeapTree::isLeft(HeapTree::Node *parent, HeapTree::Node *node)
{
    if(parent == nullptr)
    {
        return false;
    }
    return parent->left == node;
}

bool HeapTree::isRight(HeapTree::Node *parent, HeapTree::Node *node)
{
    return parent->right == node;
}

void HeapTree::print(Node *node)
{
    std::cout<<std::endl;
    std::queue<Node *> q, queue;
    q.push(root);
    int count = 0, counter = 0;
    while (!q.empty())
    {
        count++;
        Node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            std::cout << "   ";
        }
        else
        {
            std::cout << temp->key << " ";
            q.push(temp->left);
            q.push(temp->right);
        }
        if (count == pow(2, counter))
        {
            count = 0;
            std::cout << std::endl;
            counter++;
        }
    }
}