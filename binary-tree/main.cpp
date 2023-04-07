#include <iostream>
#include <string>

#include "BST.h"

using namespace std;

template <typename T>
void printMenu(BST<T>&);
template <typename T>
void performAction(BST<T>&, int);

int main()
{
    BST<int>* tree = new BST<int>();
    printMenu(*tree);

    delete tree;
    return 0;
}

template <typename T>
void printMenu(BST<T>& tree)
{
    vector<string> options = {
        "Insert Element",
        "Remove Element",
        "Print Tree (BFS)",
        "Print Tree (DFS)",
        "Print Tree (Inorder Traversal)",
        "Print Tree (Preorder Traversal)",
        "Print Tree (Postorder Traversal)",
        "Find Parent",
        "Find Sibling",
        "Find Successor",
        "Exit"
    };

    int option = 0;
    while (option != options.size())
    {
        cout << "== Binary Search Tree ==" << endl;
        for (int i = 0; i < options.size(); i++)
            cout << i + 1 << ". " << options[i] << endl;

        cout << "Enter option: ";
        cin >> option;
        performAction(tree, option);
    }
}

template <typename T>
void performAction(BST<T>& tree, int option)
{
    switch (option)
    {
        case 1:
            T data;
            cout << "Enter data: ";
            cin >> data;
            cout << (tree.insert(data) ? "Inserted." : "Key already present.") << endl;

            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            tree.remove(data);
            cout << "Removed " << data << " from tree." << endl;

            break;

        case 3:
            cout << "BFS Traversal:" << endl;
            tree.bfs_iterative();
            break;

        case 4:
            cout << "DFS Traversal:" << endl;
            tree.dfs_iterative();
            break;

        case 5:
            cout << "Inorder Traversal:" << endl;
            tree.inOrder(tree.getRoot());
            break;

        case 6:
            cout << "Preorder Traversal:" << endl;
            tree.preOrder(tree.getRoot());
            break;

        case 7:
            cout << "Postorder Traversal:" << endl;
            tree.postOrder(tree.getRoot());
            break;

        case 8:
            cout << "Enter data: ";
            cin >> data;
            cout << "Parent of " << data << " is " << tree.findParent(data)->data << endl;
            break;

        case 9:
            cout << "Enter data: ";
            cin >> data;
            cout << "Sibling of " << data << " is " << tree.findSibling(data)->data << endl;
            break;

        case 10:
            cout << "Enter data: ";
            cin >> data;
            cout << "Successor of " << data << " is " << tree.findSuccessor(tree.find(data))->data << endl;
            break;
        
        default:
            break;
    }
}