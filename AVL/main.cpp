#include "avl.hpp"

int main() {
    // Insertion test cases

    // case 1
    AVL avl1;
    avl1.insert(20);
    avl1.insert(4);
    avl1.insert(15);
    // passed

    // case 2
    AVL avl2;
    avl2.insert(20);
    avl2.insert(4);
    avl2.insert(26);
    avl2.insert(9);
    avl2.insert(3);
    avl2.insert(15);
    // passed
    
    // case 3
    AVL avl3;
    avl3.insert(20);
    avl3.insert(4);
    avl3.insert(26);
    avl3.insert(3);
    avl3.insert(9);
    avl3.insert(21);
    avl3.insert(30);
    avl3.insert(2);
    avl3.insert(7);
    avl3.insert(11);
    avl3.insert(15);
    // passed

    // Deletion test cases

    // case 1
    AVL avl4;
    avl4.insert(2); 
    avl4.insert(1); 
    avl4.insert(4); 
    avl4.insert(3); 
    avl4.insert(5); 
    avl4.remove(1);
    // passed

    // case 2
    AVL avl5;
    avl5.insert(9);
    avl5.insert(5);
    avl5.insert(10);
    avl5.insert(0);
    avl5.insert(6);
    avl5.insert(11);
    avl5.insert(-1);
    avl5.insert(1);
    avl5.insert(2);
    avl5.remove(10);
    // passed

    return 0;
}
