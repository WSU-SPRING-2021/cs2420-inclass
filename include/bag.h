#ifndef _BAG_H_
#define _BAG_H_
#include <iostream>
#include <initializer_list>
template <typename Item> 
class Bag {
private:
  unsigned sz; // How many actual items 
  unsigned capacity; // Max size
  Item* items; // The dynamic array of items

public:
  Bag(): Bag(4){}
  Bag(unsigned c): sz(0), capacity(c), items(new Item[c]){}
  Bag(std::initializer_list<Item> lst): sz(0), 
                                        capacity(lst.size()), 
                                        items(new Item[lst.size()]){
    for(Item i : lst){
      items[sz++] = i;
    }
  }

  Bag<Item>& insert_last(Item i) {
    if(sz == capacity) { // Bag is full
      Item* newItems = new Item[capacity * 2];
      for(int j = 0; j < sz; j++){
        newItems[j] = items[j]; // copy from old array to new array
      }
      delete [] items; // Delete the old array
      items = newItems;
      capacity *= 2;
    }

    items[sz++] = i;

    return *this;
  }

  Bag<Item>& remove_last() {
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

  ~Bag() {
    delete [] items;
    items = nullptr;
  }

  friend std::ostream& operator<<(std::ostream& out, const Bag<Item>& b) {
    for(int i = 0; i < b.sz; i++){
      out << b.items[i] << ", ";
    }

    return out;
  }
};

#endif