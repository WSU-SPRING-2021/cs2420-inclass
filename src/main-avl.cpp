#include <iostream>
#include "tree/avl.h"

using namespace std;
int main(){

  cs2420::AVLTree<char> avl;

  cout << avl.size() << endl;

  avl.insert('A');
  avl.insert('B');
  avl.insert('C');
  avl.insert('D');
  avl.insert('E');
  avl.insert('F');
  avl.insert('G');

  avl.inorderTraversal(cout);
  cout << avl.size() << endl;

  return 0;
}