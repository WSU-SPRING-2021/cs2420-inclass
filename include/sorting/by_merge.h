#ifndef _SORTING_BY_MERGE_H
#define _SORTING_BY_MERGE_H
#include "adt.h"

namespace cs2420 {

template<typename T>
class SortByMerge : public SortByADT<T> {
public:
  SortByMerge(Bag<T>& bag): SortByADT<T>(bag){}
  std::string label() { return "Merge"; }
  void sort(bool reversed = false){
    T* aux = new T[this->items.get_size()];
    sort(aux, 0, this->items.get_size() - 1, reversed);
    delete [] aux;
  }
private:

  void sort(T* aux, int lo, int hi, bool reversed){
    if(hi <= lo) return;

    int mid = (lo + hi)/ 2;
    sort(aux, lo, mid, reversed);
    sort(aux, mid+1, hi, reversed);

    merge(aux, lo, mid, hi, reversed);
  }

  void merge(T* aux, int lo, int mid, int hi, bool reversed){
    int i = lo; 
    int j = mid + 1;

    for(int k = lo; k <= hi; k++){
      if(i > mid) aux[k] = this->items[j++];
      else if( j > hi) aux[k] = this->items[i++];
      else if (this->lessOrGreaterThanOperator(i, j, reversed)){
        aux[k] = this->items[i++];
      }else{
        aux[k] = this->items[j++];
      }
    }

    for(int i = lo; i <= hi; i++){
      this->items[i] = aux[i];
    }
  }
};

}

#endif