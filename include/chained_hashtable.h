#ifndef _CHAINED_HASHTABLE_H_
# define _CHAINED_HASHTABLE_H_
#include <iostream>
#include <iomanip>


template <typename T>
struct Node {
  T info;
  Node<T>* next = nullptr;
  Node(T info): info(info), next(nullptr){}
};

template <typename T>
class ChainedHashtable {
  unsigned sz, capacity;
  Node<T> ** htable;

public:
  ChainedHashtable(unsigned capacity = 997): capacity(capacity), sz(0), htable(new Node<T>*[capacity]()){}
  ChainedHashtable(const ChainedHashtable<T>& t) = delete;

  int hashCode(T e){
    return e % capacity;
  }

  void add(T e){
    int t = hashCode(e);

    if(htable[t]){
      auto node = new Node<T>(e);
      node->next = htable[t];
      htable[t] = node;
    }else{
      htable[t] = new Node<T>(e);
    }

    sz++;
  }

  void remove(T e){
    int t = hashCode(e);
    if(htable[t]){
      auto current = htable[t];
      Node<T>* beforeCurrent = nullptr;

      while(current){
        if(current.info == e){
          if(beforeCurrent){
            beforeCurrent->next = current->next;
          }else{
            htable[t] = current->next;
          }

          delete current;
          sz--;
          return;
        }
        beforeCurrent = current;
        current = current->next;
      }
    }
  }

  bool empty(){
    return sz == 0;
  }

  unsigned size() {
    return sz;
  }

  bool full(){
    return sz = capacity;
  }

  bool contains(T e){
    int t = hashCode(e);
    auto current = htable[t];
    while(current){
      if(current->info == e) return true;

      current = current->next;
    }

    return false;
  }

  ~ChainedHashtable(){
    delete[] htable;
  }

  friend std::ostream& operator<<(std::ostream& out, const ChainedHashtable<T>& h){
    for(int i = 0; i < h.capacity; i++){
      out << std::setw(3) << i << ": ";
      auto current = h.htable[i];
      while(current){
        out << current->info << ", ";
        current = current->next;
      }
      out << std::endl;
    }

    return out;
  }
};


#endif


