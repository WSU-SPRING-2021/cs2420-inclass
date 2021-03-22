#ifndef _SORTING_BY_SELECTION_H_
#define _SORTING_BY_SELECTION_H_
#include "adt.h"

namespace cs2420 {
template <typename T> 
class SortBySelection : public SortByADT {
public:
  SortBySelection(Bag<T>& bag): SortByADT(bag){}

  void sort(bool reversed = false){
    for(int i = 0; i < sz - 1; i++){
      int minOrMax = minOrMaxInRange(i, sz, reversed);
      if(lessOrGreaterThanOperator(minOrMax, i, reversed)){
        swap(i, minOrMax);
      }
    }
  }
};

};
#endif