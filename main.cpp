#include <iostream>
#include "bst.h"

int main() {
    BST<char> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(17);
    tree.insert(40);
    tree.insert(14);
    tree.insert(19);
    tree.insert(31);
    tree.insert(32);
    tree.insert(33);
    tree.insert(39);
    tree.insert(34);
    tree.insert(35);
    tree.insert(38);
    tree.insert(37);
    tree.insert(36);


    std::cout << "In-order traversal: ";
    tree.print_in_order();

    std::cout << "Height of tree: " << tree.get_height() << std::endl;
    std::cout << "Minimum value: " << tree.get_min() << std::endl;
    std::cout << "Maximum value: " << tree.get_max() << std::endl;
    std::cout << "Predecessor of 35: " << tree.get_predecessor(35) << std::endl;
    std::cout << "Successor of 35: " << tree.get_successor(35) << std::endl;

    tree.remove(34);
    std::cout << "In-order traversal after removing 34: ";
    tree.print_in_order();

    return 0;
}
