#ifndef _SMART_BAG_H_
#define _SMART_BAG_H_
#include <iostream>
#include <initializer_list>
#include <memory>
template <typename Item> 
class SmartBag {
private:
  unsigned sz; // How many actual items 
  unsigned capacity; // Max size
  std::unique_ptr<Item[]> items; // The dynamic array of items

public:
  SmartBag(): SmartBag(4){}
  SmartBag(unsigned c): sz(0), capacity(c), items(std::make_unique<Item[]>(c)){}
  SmartBag(std::initializer_list<Item> lst): SmartBag(lst.size){
    for(Item i : lst){
      items[sz++] = i;
    }
  }

  SmartBag<Item>& insert_last(Item i) {
    if(sz == capacity) { // Bag is full
      std::unique_ptr<Item[]> newItems = std::make_unique<Item[]>(capacity * 2);
      for(int j = 0; j < sz; j++){
        newItems[j] = items[j]; // copy from old array to new array
      }

      items = std::move(newItems);

      capacity *= 2;
    }

    items[sz++] = i;

    return *this;
  }

  SmartBag<Item>& remove_last() {
    sz--;
    // Shrink when sz = capacity / 2;
    return *this;
  }

  Item operator[](int ndx) const { // Read-only
    if(ndx < 0 || ndx >= sz){
      throw std::runtime_error("invalid index");
    }

    return items[ndx];
  }

  Item& operator[](int ndx) { // Read-write
    if(ndx < 0 || ndx >= sz){
      throw std::runtime_error("invalid index");
    }
    
    return items[ndx];
  }

  Item* begin(){return items;} // points to the first item

  Item* end(){return items + sz;} // Points to the position after last item

  unsigned get_size() const { return sz; }
  unsigned get_capacity() const { return capacity; }

  ~SmartBag() {}

  friend std::ostream& operator<<(std::ostream& out, const SmartBag<Item>& b) {
    for(int i = 0; i < b.sz; i++){
      out << b.items[i] << ", ";
    }

    return out;
  }
};

#endif