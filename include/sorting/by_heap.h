#ifndef _SORTING_BY_HEAP_H_
#define _SORTING_BY_HEAP_H_
#include "adt.h"

namespace cs2420 {
  
template <typename T>
class SortByHeap : public SortByADT<T> {
public:
  SortByHeap(Bag<T>& bag): SortByADT<T>(bag){}
  std::string label() { return "Heap"; }
  void sort(bool reversed = false){
    build_heap(reversed);
    for(int i = this->items.get_size()  - 1; i > 0; i--){
      this->swap(0, i);
      heapify(0, i, reversed);
    }
  }
private:
  void build_heap(bool reversed){
    for(int i = this->items.get_size() / 2 - 1; i >= 0; i--){
      heapify(i, this->items.get_size(), reversed);
    }
  }

  void heapify(int p, int hsz, bool reversed){
    int left = 2 * p + 1;
    int right = left + 1;
    int largest = p;
    if(left < hsz && this->lessOrGreaterThanOperator(p , left, reversed)) {
      largest = left;
    }

    if(right < hsz && this->lessOrGreaterThanOperator(largest , right, reversed)) {
      largest = right;
    }

    if(largest != p){
      this->swap(p, largest);
      heapify(largest, hsz, reversed);
    }
  }
};

}

#endif