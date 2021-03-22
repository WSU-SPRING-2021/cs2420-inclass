#ifndef _SORTING_BY_INSERTION_H_
#define _SORTING_BY_INSERTION_H_
#include "adt.h"

namespace cs2420 {
template <typename T> 
class SortByInsertion : public SortByADT {
public:
  SortByInsertion(Bag<T>& bag): SortByADT(bag){}

  void sort(bool reversed = false){
    for(int i = 1; i < sz; i++){
      for(int j = i; j > 0 && lessOrGreaterThanOperator(j, j-1, reversed); j--){
        swap(j, j-1);
      }
    }
  }
};

};
#endif