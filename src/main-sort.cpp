#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <iomanip>
#include "bag.h"
#include "sorting/adt.h"
#include "sorting/by_bubble.h"
#include "sorting/by_selection.h"
#include "sorting/by_insertion.h"
#include "sorting/by_quick.h"
#include "sorting/by_heap.h"
#include "sorting/by_merge.h"
using namespace std;

enum class SortType { Random, Reversed, Sorted };

template <typename T>
struct SortingTimer {
  cs2420::SortByADT<T>& algorithm;
  chrono::duration<double, nano> random_time;
  chrono::duration<double, nano> sorted_time;
  chrono::duration<double, nano> reversed_time;

  SortingTimer(cs2420::SortByADT<T>& a): algorithm(a) {}
  string label(){ return algorithm.label(); }
  void run(SortType type, bool reversed = false){
    auto start = chrono::high_resolution_clock::now();
    algorithm.sort(reversed);
    auto end = chrono::high_resolution_clock::now();

    switch(type){
      case SortType::Random:
        random_time = end - start; break;
      case SortType::Sorted:
        sorted_time = end - start; break;
      case SortType::Reversed:
        reversed_time = end - start; break;
    }

  }

};

int main(){
  const int MAX_CAPACITY = 10000;
  default_random_engine en;
  uniform_int_distribution rdist {-1000, 1000};

  Bag<int> b = {3, 4, 6, 7, 9, 2, 3, 10};
  for(int i = 0; i < MAX_CAPACITY; i++){
    b.insert_last(rdist(en));
  }

  Bag<int> data[] { // Copies of the original bag b
    Bag<int>(b),
    Bag<int>(b),
    Bag<int>(b),
    Bag<int>(b),
    Bag<int>(b),
    Bag<int>(b)
  };

  cs2420::SortByADT<int>* algorithms []  {
    new cs2420::SortByBubble<int>(data[0]),
    new cs2420::SortBySelection<int>(data[1]),
    new cs2420::SortByInsertion<int>(data[2]),
    new cs2420::SortByQuick<int>(data[3]),
    new cs2420::SortByMerge<int>(data[4]),
    new cs2420::SortByHeap<int>(data[5])
  };

  cout << setw(20) << "Algorithm" 
       << setw(20) << "Sorted" 
       << setw(20) << "Random" 
       << setw(20) << "Reversed" << endl;

  for(cs2420::SortByADT<int>* a : algorithms){
    SortingTimer<int> rt(*a);
    rt.run(SortType::Random);
    rt.run(SortType::Sorted);
    a->sort(true); // reverse the array first
    rt.run(SortType::Reversed);

    cout << fixed << setprecision(2)
       << setw(20) << rt.label() 
       << setw(20) << rt.sorted_time.count() 
       << setw(20) << rt.random_time.count() 
       << setw(20) << rt.reversed_time.count()  << endl;
  }

  return 0;
}



//https://github.com/WSU-SPRING-2021/cs2420-inclass