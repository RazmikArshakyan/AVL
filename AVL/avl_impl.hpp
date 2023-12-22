#include "avl.hpp"

inline Node::Node(int val)
    : val(val), left(nullptr), right(nullptr)
{
}

inline void AVL::insert(int val)
{
    root = insert(root, val);
}

inline void AVL::remove(int val)
{
    root = remove(root, val);
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

inline void AVL::level_order_traversal(Node *node)
{
    if (!node) {
        return;
    }

    std::queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        int level_size = q.size();

        for (int i = 0; i < level_size; ++i) {
            Node* curr = q.front();
            q.pop();

            std::cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        std::cout << std::endl;
    }
}

inline Node *AVL::get_root()
{
    return root;
}

inline void AVL::level_order_traversal()
{
    level_order_traversal(root);
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

    return balance(node, val);
}

inline Node *AVL::remove(Node *node, int val)
{
    Node* tmp;
    if (!node) {
        return nullptr;
    }

    if (node->val < val) {
        node->right = remove(node->right, val);
    }
    else if (node->val > val) {
        node->left = remove(node->left, val);
    }
    else if (node->left && node->right) {
        tmp = min_node(node->right);
        node->val = tmp->val;
        node->right = remove(node->right, node->val);
    }
    else {
        tmp = node;
        if (!node->left) {
            node = node->right;
        }
        else if (!node->right) {
            node = node->left;
        }
        delete tmp;
    }

    return balance(node, val);
}

inline Node* AVL::balance(Node *&node, int val)
{
    if (node) {
        balance(node->left, val);
        balance(node->right, val);
        if (get_bf(node) > 1) {
            if (node->left && node->left->val > val) {
                node = right_rotate(node);
            }
            else {
                node->left = left_rotate(node->left);
                node = right_rotate(node);
            }
        }
        else if (get_bf(node) < -1) {
            if (node->right && node->right->val < val) {
                node = left_rotate(node);
            }
            else {
                node->right = right_rotate(node->right);
                node = left_rotate(node);
            }
        }
    } 
    return node;
}

