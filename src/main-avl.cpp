#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include "tree/bst.h"
#include "tree/avl.h"

using namespace std;
int main(){

  cs2420::AVLTree<int> avl;
  cs2420::BST<int> bst;

  default_random_engine en;
  uniform_int_distribution rdist {-1000, 1000};

  for(int i = 0; i < 1000; i++){
    int r = rdist(en);

    bst.insert(r);
    avl.insert(r);
  }


  chrono::duration<double, nano> avl_time;
  chrono::duration<double, nano> bst_time;

  int nums[100];
  for(int i = 0; i < 100; i++){
    nums[i] = rdist(en);
  }

  auto start = chrono::high_resolution_clock::now();
  for(int n : nums){
    bst.search(n);
  }
  auto end = chrono::high_resolution_clock::now();
  bst_time = end - start;

  start = chrono::high_resolution_clock::now();
  for(int n : nums){
    avl.search(n);
  }
  end = chrono::high_resolution_clock::now();
  avl_time = end - start;


  cout << setw(20) << "Tree" 
       << setw(20) << "Time (ns)" <<endl;

  cout << fixed << setprecision(2)
       << setw(20) << "BST"
       << setw(20) << bst_time.count() << endl;
    cout << fixed << setprecision(2)
       << setw(20) << "AVL"
       << setw(20) << avl_time.count() << endl;

  return 0;
}