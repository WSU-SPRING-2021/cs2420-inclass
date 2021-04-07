#include <iostream>
#include "tree/bst.h"

using namespace std;

template<typename T>
void showNode(const cs2420::Node<T>* node, int depth){
  if(node){
    for(int i = 0; i < depth; i++){
      cout << "   ";
    }
    cout << node->info << endl;
  }
}

int main(){

  cs2420::BST<char> bst;

  cout << bst.size() << endl;

  bst.traverse(cs2420::Traversal::INORDER, showNode);

  bst.insert('E');
  bst.insert('C');
  bst.insert('A');
  bst.insert('D');
  bst.insert('M');
  bst.insert('P');
  bst.insert('K');

  bst.traverse(cs2420::Traversal::INORDER, showNode);
  cout << bst.size() << endl;

  bst.traverse(cs2420::Traversal::PREORDER, showNode);

  bst.traverse(cs2420::Traversal::POSTORDER, showNode);

  cout << bst.search('M') << endl;
  bst.remove('M');
  cout << bst.search('M') << endl;

  cout << endl << endl;
  bst.traverse(cs2420::Traversal::INORDER, showNode);


  cs2420::BST<int> nums;
  for(int i = 0; i < 10; i++){
    nums.insert(i);
  }

  nums.traverse(cs2420::Traversal::INORDER, showNode);
  
  return 0;
}