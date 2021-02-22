#ifndef _STACK_H_
#define _STACK_H_
#include "doubly-linked-list.h"

namespace cs2420 {

template <typename T>
class StackADT { // ADT - Abstract Data Type
public:
  virtual void push(T info) = 0;
  virtual T pop() = 0;
  virtual T top() const = 0;
  virtual bool empty() const = 0;
  virtual void clear() = 0;
  virtual ~StackADT(){}
};

template<typename T>
class Stack : public StackADT<T> {
private:
  List<T> list;

public:
  Stack() {} // O(1)

  void push(T info){ // O(1)
    list.add_front(info);
  }
  
  T pop(){ // O(1)
    if(empty()){
      throw std::runtime_error("Empty stack");
    } 

    auto front = list.begin();
    T info = *front;

    list.remove_front();
    return info;
  }
  T top() const { // O(1)
    if(empty()){
      throw std::runtime_error("Empty stack");
    } 

    auto front = list.begin();
    T info = *front;

    return info;
  };
  
  bool empty() const { // O(1)
    return list.size() == 0;
  };

  void clear() { // O(n)
    list.remove_all();
  }
};

}

#endif