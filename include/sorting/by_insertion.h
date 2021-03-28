#ifndef _SORTING_BY_INSERTION_H_
#define _SORTING_BY_INSERTION_H_
#include "adt.h"

namespace cs2420 {
template <typename T> 
class SortByInsertion : public SortByADT<T> {
public:
  SortByInsertion(Bag<T>& bag): SortByADT<T>(bag){}
  std::string label() { return "Insertion"; }
  void sort(bool reversed = false){
    for(int i = 1; i < this->items.get_size(); i++){
      for(int j = i; j > 0 && this->lessOrGreaterThanOperator(j, j-1, reversed); j--){
        this->swap(j, j-1);
      }
    }
  }
};

};
#endif