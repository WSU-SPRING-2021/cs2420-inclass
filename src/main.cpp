#include <iostream>
#include <iomanip>
using namespace std;
// Structures

enum class FormattingChar {
  Equal, Underscore, Astrisk
};

struct MTable {
  int size;
  FormattingChar ch;
};

// function prototypes
void print_formatted_line(int, const MTable & t); 
void print_formatted_num(int, int);

void print_table(const MTable &t) {
  for(int i = 1; i <= t.size; i++){
    for(int j = 1; j <= t.size; j++) {
      print_formatted_num(i, j);
    }
    cout << endl;
    print_formatted_line(i, t);
  }
}

void print_formatted_line(int i, const MTable & t){
  if(i == 1) {
    for(int k = 0; k < 6 * t.size; k++){
      switch (t.ch){
        case FormattingChar::Equal: 
          cout << '='; 
          break;
        case FormattingChar::Underscore: 
          cout << '_'; 
          break;
        case FormattingChar::Astrisk: 
          cout << '*'; 
          break;
      }
    }

    cout << endl;
  }
}

void print_formatted_num(int i, int j) {
  if(j == 1){
    cout << setw(3) << i * j << setw(3) << '|';
  } else {
    cout << setw(6) << i *j;
  }
}

int main() {
  MTable big = {12, FormattingChar::Equal};
  MTable small = {6, FormattingChar::Astrisk};

  print_table(big);
  print_table(small);

  return 0;
}