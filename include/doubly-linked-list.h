#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_
#include <iostream>
#include <initializer_list>
namespace cs2420 {
  template<typename T>
  struct Node {
    T info;
    Node<T> *next;
    Node<T> *prev;

    Node(T info):info(info), next(nullptr), prev(nullptr) {}
    Node(T info, Node<T> * nxt, Node<T>* prv): info(info), next(nxt), prev(prv) {}
  };

  template<typename T>
  class ListIterator {
  private:
    Node<T>* current = nullptr;

  public:
    ListIterator(Node<T>* node): current(node){}
    T operator*(){
      return current->info;
    }

    ListIterator<T>& operator++(){
      current = current->next;
      return *this;
    }

    ListIterator<T>& operator--(){
      current = current->prev;
      return *this;
    }

    bool operator==(const ListIterator<T>& rhs) {
      return current == rhs.current;
    }

    bool operator!=(const ListIterator<T>& rhs) {
      return current != rhs.current;
    }

    operator bool() const {
      return current;
    }
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
    List(const std::initializer_list<T>& lst) { // O(n) - linear time
      for(T n : lst){
        add_back(n);
      }
    }
    
    List<T>& add_front(T info) { // O(1) - constant time
      auto node = new Node<T>(info, front, nullptr);

      if(!back) {// If list is empty
        back = front = node;
      }else{
        front->prev = node;
        front = node;
      }

      sz++;
      return *this;
    }

    // List<int> lst = another_list

    List<T>(const List<T>& rhs) { // Copy constuctor
      auto current = rhs.front;
      while(current){
        add_back(current->info);
        current = current->next;
      }
    }

    // List<int> lst {2, 4, 5, 6, 7};
    // List<int> second = {5};
    // second = lst;
    List<T>& operator=(const List<T>& rhs){
      remove_all();
      auto current = rhs.front;
      while(current){
        add_back(current->info);
        current = current->next;
      }

      return *this;      
    }

    List<T>& add_back(T info){ // O(1) - constant
      auto node = new Node<T>(info, nullptr, back);
      if(back) { // list is not empty
        back->next = node;
        back = node;
      }else { // list is empty
        front = back = node;
      }

      sz++;

      return *this;
    }

    unsigned size() const { return sz; }

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
        front->prev = nullptr;
        delete tmp;
      }

      sz--;
      return true;
    }

    bool remove_back(){ // O(1)
      if(sz == 0) {
        return false;
      }

      if(front == back){
        delete front;
        front = back = nullptr;
      } else {
        auto pred = back->pred;
        pred->next = nullptr;

        delete back;
        back = pred;
      }

      sz--;
      return true;
    }

    bool remove(T info){ // O(n)
      if(sz == 0) return false;

      if(front->info == info) return remove_front();

      auto current = front->next;
      while(current){
        if(current->info == info){
          current->prev->next = current->next;
          current->next->prev = current->prev;
          if(current == back){
            back = current->prev;
          }

          delete current;
          sz--;
          return true;
        }
        current = current->next;
      }

      return false;
    }

    void remove_all(){
      auto current = front;
      while(current){
        auto tmp = current;
        current = current->next;
        delete tmp;
      }
      front = back = nullptr;
      sz = 0u;
    }

    ListIterator<T> begin() const {
      return ListIterator<T>(front);
    }

    ListIterator<T> end() {
      return ListIterator<T>(back->next);
    }

    bool find(T info){
      auto current = front;
      while(current){
        if(current->info == info){
          return true;
        }

        current = current->next;
      }

      return false;
    }

    friend std::ostream& operator<<(std::ostream& out, const List<T>& lst){
      auto current = lst.front;
      while(current){
        out << current->info << " ";
        current = current->next;
      }

      return out;
    }


    ~List() {
      remove_all();
    }

  };
}


/*
List<int> lst {2, 3, 4};

for(int i : lst){
  cout << i;
}
*/
#endif



