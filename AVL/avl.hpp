#ifndef AVL_H
#define AVL_H

#include <iostream>

struct Node {
    Node(int val);

    int val;
    Node* left;
    Node* right;
};

class AVL {
public: 
    void insert(int val);
    int get_height(Node* node);
    int get_bf(Node* node);
    Node* min_node(Node* node);
    Node* left_rotate(Node* node);
    Node* right_rotate(Node* node);

private:
    Node* insert(Node* node, int val);
    Node* update(Node* node, int val);
    Node* root = nullptr;
};

#include "avl_impl.hpp"
#endif