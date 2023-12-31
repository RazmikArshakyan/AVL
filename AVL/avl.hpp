#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <cmath>
#include <queue>

struct Node {
    Node(int val);

    int val;
    Node* left;
    Node* right;
};

class AVL {
public: 
    void insert(int val);
    void remove(int val);
    int get_height(Node* node);
    int get_bf(Node* node);
    Node* min_node(Node* node);
    Node* left_rotate(Node* node);
    Node* right_rotate(Node* node);
    Node* get_root();
    void level_order_traversal();

private:
    Node* insert(Node* node, int val);
    Node* remove(Node* node, int val);
    Node* balance(Node*& node, int val);
    Node* root = nullptr;
    void level_order_traversal(Node* node);
};

#include "avl_impl.hpp"
#endif
