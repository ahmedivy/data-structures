#pragma once

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *find_parent(Node *root, int key);
int find_level(Node *root, int key, int level = 0);
int find_height(Node *root);
int min_value(Node *root);
int max_value(Node *root);
bool is_bst(Node *root);
void level_order_insert(Node *root, int key);
void print_tree(Node *root, int level = 0, bool is_left = false);
void run_test();
bool is_same_level(Node *root, int key1, int key2);
int count_nodes(Node *root);
