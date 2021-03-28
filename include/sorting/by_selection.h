#ifndef _SORTING_BY_SELECTION_H_
#define _SORTING_BY_SELECTION_H_
#include "adt.h"

namespace cs2420 {
template <typename T> 
class SortBySelection : public SortByADT<T> {
public:
  SortBySelection(Bag<T>& bag): SortByADT<T>(bag){}
  std::string label() { return "Selection"; }
  void sort(bool reversed = false){
    for(int i = 0; i < this->items.get_size() - 1; i++){
      int minOrMax = this->minOrMaxInRange(i, this->items.get_size(), reversed);
      if(this->lessOrGreaterThanOperator(minOrMax, i, reversed)){
        this->swap(i, minOrMax);
      }
    }
  }
};

};
#endif