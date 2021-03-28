#ifndef _SORTING_BY_QUICK_H_
#define _SORTING_BY_QUICK_H_
#include "adt.h"

namespace cs2420 {
template <typename T> 
class SortByQuick : public SortByADT<T> {
  void sort(int lo, int hi, bool reversed){
    if(lo < hi){
      int m = partition(lo, hi, reversed);
      sort(lo, m - 1, reversed);
      sort(m + 1, hi, reversed);
    }
  }

  int partition(int lo, int hi, bool reversed){
    int p = rand() % (hi - lo + 1) + lo;
    this->swap(p, hi);

    int i = lo - 1;
    for(int j = lo; j < hi; j++){
      if(this->lessOrGreaterThanOperator(j, hi, reversed)){
        this->swap(++i, j);
      }
    }

    this->swap(i+1, hi);
    return i + 1;
  }

public:
  SortByQuick(Bag<T>& bag): SortByADT<T>(bag){}
  std::string label() { return "Quick"; }
  void sort(bool reversed = false){
    sort(0, this->items.get_size() - 1, reversed);
  }
};

};
#endif