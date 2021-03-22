#ifndef _LP_HASHTABLE_H_
# define _LP_HASHTABLE_H_
#include <iostream>

template <typename T>
struct Cell {
  T info;
  bool empty = true;
};

template <typename T>
class LinearHashtable {
  unsigned sz, capacity;
  Cell<T> *htable;

public:
  LinearHashtable(unsigned capacity = 997): capacity(capacity), sz(0), htable(new Cell<T>[capacity]()){}
  LinearHashtable(const LinearHashtable<T>& t) = delete;

  int hashCode(T e){
    return e % capacity;
  }
  void add(T e){
    if(sz == capacity) throw std::runtime_error("Table is full");

    int t = hashCode(e);

    if(htable[t].empty){
      htable[t] = { e, false };
    }else{
      int i = 1;
      while(!htable[(t+i) % capacity].empty) i++;
      htable[(t+i) % capacity] = { e, false };
    }

    sz++;
  }

  ~LinearHashtable(){
    delete[] htable;
  }
}


#endif


