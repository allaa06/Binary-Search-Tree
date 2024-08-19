#ifndef BST_TPP
#define BST_TPP

#include <iostream>
#include <memory>
#include "bst.h"

template <typename T>
Node<T>::Node()
   :val{},
   left{nullptr},
   right{nullptr}
{}

template <typename T>
Node<T>::Node(T val) 
   :val{val}
   ,left{nullptr}
   ,right{nullptr}
{}

template <typename T>
BST<T>::BST()
   :root{nullptr}
{}

template <typename T>
Node<T>* BST<T>::insert(Node<T>* node, T val) {
   if(!node){
     return new Node<T>(val);
   }
   if(node->val > val) {
      node->left = insert(node->left, val);
   }
   else {
      node->right = insert(node->right, val);
   }

   return node;
}

template <typename T>
Node<T>* BST<T>::remove(Node<T>* node, T val) {
   if(!node) { return nullptr; }
   if(node->val > val) {
      node->left = remove(node->left, val);
   }
   else if(node->val < val) {
      node->right = remove(node->right, val);
   }
   else {
      if(!node->left) { return node->right; }
      else if(!node->right) { return node->left; }
      else {
         Node<T>* tmp = get_min(node->right);
         node->val = tmp->val;
         node->right = remove(node->right, tmp->val);
      }
   }

   return node;
}

template <typename T>
int BST<T>::get_height(Node<T>* node) {
   if(!node) {
      return 0;
   }
   int left = get_height(node->left);
   int right = get_height(node->right);
   return std::max(left, right) + 1;
}

template <typename T>
Node<T>* BST<T>::get_min(Node<T>* node) {
   while(node->left) {
      node = node->left;
   }
   return node;
}

template <typename T>
Node<T>* BST<T>::get_max(Node<T>* node) {
   while(node->right) {
      node = node->right;
   }
   return node;
}

template <typename T>
Node<T>* BST<T>::get_predecessor(Node<T>* node, T val) {
   Node<T>* pred = nullptr;
   Node<T>* curr = node;
   while (curr->val != val)
   {
      if (curr->val > val)
      {
          curr = curr->left;
      }
      else 
      { 
         pred = curr;
         curr = curr->right;
      }
    }
    if(curr->left)
    {
     return get_max(curr->left);
    }
    return pred;
}

template <typename T>
Node<T>* BST<T>::get_successor(Node<T>* node, T val) {
   Node<T>* successor = nullptr;
   Node<T>* curr = node;
   while (curr->val != val)
   {
      if (curr->val <= val)
      {
          curr = curr->right;
      }
      else 
      { 
         successor = curr;
         curr = curr->left;
      }
    }
   if(curr->right)
   {
      return get_min(curr->right);
   }
   return successor;
}

template <typename T>
void BST<T>::print_in_order(Node<T>* node) {
   if (node == nullptr) return;
   print_in_order(node->left);
   std::cout << node->val << " ";
   print_in_order(node->right);
}

template <typename T>
void BST<T>::insert(T val) {
   root = insert(root, val);
   
}

template <typename T>
void BST<T>::remove(T val) {
   root = remove(root, val);

}

template <typename T>
int BST<T>::get_height() {
   return get_height(root);

}

template <typename T>
T BST<T>::get_min() {
   Node<T>* min_node = get_min(root);
   return (min_node != nullptr) ? min_node->val : root->val;
}

template <typename T>
T BST<T>::get_max() {
   Node<T>* max_node = get_max(root);
   return (max_node != nullptr) ? max_node->val : T();

}

template <typename T>
T BST<T>::get_predecessor(T val) {
  Node<T>* predecessor = get_predecessor(root, val);
   return (predecessor != nullptr) ? predecessor->val : T();
}

template <typename T>
T BST<T>::get_successor(T val) {
  Node<T>* successor = get_successor(root, val);
   return (successor != nullptr) ? successor->val : T();
}

template <typename T>
void BST<T>::print_in_order() {
   print_in_order(root);
   std::cout << std::endl;
}

#endif
