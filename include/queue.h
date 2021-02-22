#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "doubly-linked-list.h"

namespace cs2420 {

template <typename T>
class QueueADT { // ADT - Abstract Data Type
public:
  virtual void enqueue(T info) = 0;
  virtual T dequeue() = 0;
  virtual T peek() const = 0;
  virtual bool empty() const = 0;
  virtual void clear() = 0;
  virtual ~QueueADT(){}
};

template<typename T>
class Queue : public QueueADT<T> {
private:
  List<T> list;

public:
  Queue() {}

  void enqueue(T info){
    list.add_back(info);
  }

  T dequeue(){
    if(empty()){
      throw std::runtime_error("Empty queue");
    } 

    auto front = list.begin();
    T info = *front;

    list.remove_front();
    return info;
  }
  T peek() const {
    if(empty()){
      throw std::runtime_error("Empty queue");
    } 

    auto front = list.begin();
    T info = *front;

    return info;
  };
  
  bool empty() const {
    return list.size() == 0;
  };

  void clear() {
    list.remove_all();
  }
};

}

#endif