#ifndef _SORTING_BY_BUBBLE_H_
#define _SORTING_BY_BUBBLE_H_
#include "adt.h"

namespace cs2420 {
template <typename T> 
class SortByBubble : public SortByADT<T> {
public:
  SortByBubble(Bag<T>& bag): SortByADT<T>(bag){}
  std::string label() { return "Bubble"; }
  void sort(bool reversed = false){
    for(int i = 0; i < this->items.get_size() - 1; i++){
      for(int j = 1; j < this->items.get_size() - i; j++){
        if(this->lessOrGreaterThanOperator(j, j - 1, reversed)){
          this->swap(j, j-1);
        }
      }
    }
  }

};

};
#endif