#ifndef _SORTING_ADT_H_
#define _SORTING_ADT_H_
#include "bag.h"

namespace cs2420 {
template <typename T> 
class SortByADT {
public:
  SortByADT(Bag<T>& bag): items(bag){}

  virtual void sort(bool reversed = false) = 0;
  virtual ~SortByADT(){}

protected:
  Bag<T>& items;

  void swap(int i, int j){
    auto tmp = items[i];
    items[i] = items[j];
    items[j] = tmp;
  }

  bool lessOrGreaterThanOperator(int i, int j, bool reversed = false){
    return (!reversed && items[i] < items[j]) || (reversed && items[i] > items[j]);
  }

  int minOrMaxInRange(int begin, int end, bool reversed = false){
    int minOrMax = begin;
    for(int i = begin; i < end; i++){
      if(lessOrGreaterThanOperator(i, minOrMax, reversed)){
        minOrMax = i;
      }
    }

    return minOrMax;
  }
};

};
#endif