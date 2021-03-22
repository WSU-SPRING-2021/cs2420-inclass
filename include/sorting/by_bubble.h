#ifndef _SORTING_BY_BUBBLE_H_
#define _SORTING_BY_BUBBLE_H_
#include "adt.h"

namespace cs2420 {
template <typename T> 
class SortByBubble : public SortByADT {
public:
  SortByBubble(Bag<T>& bag): SortByADT(bag){}

  void sort(bool reversed = false){
    for(int i = 0; i < sz - 1; i++){
      for(int j = 1; j < sz - i; j++){
        if(lessOrGreaterThanOperator(j, j - 1, reversed)){
          swap(j, j-1);
        }
      }
    }
  }

};

};
#endif