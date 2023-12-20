#include "avl.hpp"

inline Node::Node(int val)
    : val(val), left(nullptr), right(nullptr)
{
}

inline void AVL::insert(int val)
{
    root = insert(root, val);
}

inline int AVL::get_height(Node *node)
{
    if (!node) {
        return 0;
    }

    int lh = get_height(node->left);
    int rh = get_height(node->right);

    return std::max(lh, rh) + 1;
}

inline int AVL::get_bf(Node *node)
{
    if (!node) {
        return 0;
    }

    return get_height(node->left) - get_height(node->right);
}

inline Node *AVL::min_node(Node *node)
{
    if (!node || !node->left) {
        return node;
    }

    return min_node(node->left);
}

inline Node *AVL::left_rotate(Node *node)
{
    Node* t = node->right;
    node->right = t->left;
    t->left = node;

    return t;
}

inline Node *AVL::right_rotate(Node *node)
{
    Node* t = node->left;
    node->left = t->right;
    t->right = node;

    return t;
}

Node *AVL::insert(Node *node, int val)
{
    if (!node) {
        return new Node(val);
    }

    if (node->val < val) {
        node->right = insert(node->right, val);
    }
    else {
        node->left = insert(node->left, val);
    }

    return update(node, val);
}

inline Node* AVL::update(Node *node, int val)
{
    if (node) {
        update(node->left, val);
        update(node->right, val);
        if (get_bf(node) > 1 && node->left->val > val) {
            return right_rotate(node);
        }
        else if (get_bf(node) > 1 && node->left->val <= val) {
            node = left_rotate(node);
            return right_rotate(node);
        }
        else if (get_bf(node) < -1 && node->right->val < val) {
            return left_rotate(node);
        }
        else if (get_bf(node) < -1 && node->right->val >= val) {
            node = right_rotate(node);
            return left_rotate(node);
        }
    } 
    return node;
}