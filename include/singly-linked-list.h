#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_
#include <initializer_list>
namespace cs2420 {
  template<typename T>
  struct Node {
    T info;
    Node<T> *next;

    Node(T info):info(info), next(nullptr) {}
    Node(T info, Node<T> * ptr): info(info), next(ptr) {}
  };

  template<typename T>
  class List {
  private:
    unsigned sz = 0;
    Node<T>* front = nullptr;
    Node<T>* back = nullptr;

  public:
    List(){}

    // List<int> lst = {2,4,6,8,10}
    List<const std::initializer_list<T>& lst) { // O(n) - linear time
      for(T n : lst){
        add_back(n);
      }
    }
    
    List<T>& add_front(T info) { // O(1) - constant time
      front = new Node<T>(info, front);

      if(!back) {// If list is empty
        back = front;
      }

      sz++;
      return *this;
    }

    List<T>& add_back(T info){ // O(1) - constant
      auto node = new Node<T>(info);
      if(back) { // list is not empty
        back->next = node;
        back = node;
      }else { // list is empty
        front = back = node;
      }

      sz++;

      return *this;
    }

    bool remove_front(){ // O(1)
      if(sz == 0){
        return false;
      }

      if(front == back){
        delete front;
        front = back = nullptr;
      }else{
        auto tmp = front;
        front = tmp->next;
        delete tmp;
      }

      sz--;
      return true;
    }

    bool remove_back(){ // O(n)
      if(sz == 0) {
        return false;
      }

      if(front == back){
        delete front;
        front = back = nullptr;
      } else {
        auto pred = front;
        while(pred->next != back){
          pred = pred->next;
        }

        delete back;
        back = pred;
        back->next = nullptr;
      }

      sz--;
      return true;
    }

    bool remove(T info){ // O(n)
      if(sz == 0) return false;

      if(front->info == info) return remove_front();

      auto pred = front;
      auto current = front->next;
      while(current){
        if(current->info == info){
          pred->next = current->next;
          if(!pred->next){
            back = pred;
          }

          delete current;
          sz--;

          return true;
        }


        pred = current;
        current = current->next;
      }

      return false;
    }
  };
}

#endif