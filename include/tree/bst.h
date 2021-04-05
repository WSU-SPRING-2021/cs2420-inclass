#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

namespace cs2420 {

template <typename T>
struct Node {
  T info;
  Node* left = nullptr;
  Node* right = nullptr;
};

enum class Tranversal {PREORDER, INORDER, POSTORDER };

template <typename T>
class BST {
private:
  Node<T>* root = nullptr;

public:
  BST(): root(nullptr) {}
  bool empty() const { return !root; }
  int size() const { return size(root); }
  int size(Node<T>* n) const { 
    if(!n) return 0;

    return 1 + sizeD(n->left) + size(n->right);
  }

  bool search(T e) const {
    auto current = root;
    while(current){
      if(current->info == e){
        return true;
      }else if(e < current->info){
        current = current->left;
      } else {
        current = current->right;
      }
    }

    return false;
  }

  void insert(T e) {
    if(!root){
      root = new Node<T> { e };
    }else{
      auto current = root;
      Node<T>* parent = nullptr;

      while(current){
        parent = current;
        if(current->info == e){
          throw std::runtime_error("Element is already in the tree");
        }else if(e < current->info){
          current = current->left;
        } else {
          current = current->right;
        }

      }

      if( e < parent->info){
        parent->left = new Node<T> {e};
      } else {
        parent->right = new Node<T> {e};
      }
    }
  }

  void remove(T e){
    auto current = root;
    Node<T>* parent = nullptr;
    bool is_left_child = false;
    while(current){
      if(current->info == e){
        break;
      }else{
        parent = current;
        if(e < current-info){
          is_left_child = true;
          current = current->left;
        }else{
          is_left_child = false;
          current = current->right;
        }
      } 
    }

    Node<T>* node = current; // The node to be deleted
    if(node){
      if(!node->left && !node->right){ // Leaf node
        if(is_left_child) parent->left nullptr; else parent->right = nullptr;
      }else if(node->left && !node->right){ // No right child
        if(is_left_child) parent->left = node->left; else parent->right = node->left; 
      }else if(!node->left && node->right){ // No left child
        if(is_left_child) parent->left = node->right; else parent->right = node->right; 
      } else { // With left and right children
        // Find max node on the left side
        auto current = node->left;
        Node<T>* beforeCurrent = nullptr;
        while(current->right){
          beforeCurrent = current;
          current = current->right;
        }

        node->info = current->info
        if(beforeCurrent){
          beforeCurrent->right = current->left;
        } else {
          node->left = current->left;
        }

        node = current;
      }

      delete node;
      node = nullptr;
    }
  }

  void traverse(Tranversal type, void (*fptr)(const Node<T>* n, int d)) const {
    traverse(type, root, 0, fptr);
  }

  void traverse(Tranversal type, Node<T>* node, int depth, void (*fptr)(const Node<T>* n, int d)){
    if(node){
      switch(type){
      case Tranversal::PREORDER:
        fptr(n, depth);
        traverse(type, node->left, depth + 1, fptr);
        traverse(type, node->right, depth + 1, fptr);
        break;
      case Tranversal:: INORDER:
        traverse(type, node->left, depth + 1, fptr);
        fptr(n, depth);
        traverse(type, node->right, depth + 1, fptr);
        break;
      case Tranversal::POSTORDER:
        traverse(type, node->left, depth + 1, fptr);
        traverse(type, node->right, depth + 1, fptr);
        fptr(n, depth);
        break;
      }
    }
  }

  void destroy(Node<T>* node){
    if(node){
      destroy(node->left);
      destroy(node->right);

      delete node;
      node = nullptr;
    }
  }
  
  ~BST(){
    destroy(root);
  }



};

}

#endif