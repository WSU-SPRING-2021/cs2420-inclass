#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

enum class Marker {
  Exit = 'X', Entry = 'N', Wall = '+', Passage = ' ', Visited = '.'
};

class Cell {
  int r, c;
public:
  Cell(int i, int j): r(i), c(j){}

  bool operator==(const Cell& cell){
    return r == cell.r && c == cell.c;
  }

  bool operator!=(const Cell& cell){
    return !(*this == cell);
  }

  friend class Maze;
};

class Maze {
  string* grid;
  unsigned rows, cols;
  cs2420::Stack<Cell> s;

  Cell find_cell_by_marker(Marker m){
    for(int r = 0; r < rows; r++){
      for(int c = 0; c < cols; c++){
        if(grid[r][c] == static_cast<char>(m)){
          return Cell(r, c);
        }
      }
    }

    return Cell(0,0);
  }

  void push_to_stack(int r, int c){
    if(grid[r][c] == static_cast<char>(Marker::Exit) ||
       grid[r][c] == static_cast<char>(Marker::Passage)){
         s.push(Cell(r, c));
       }
  }

  friend ostream& operator<<(ostream& out, const Maze& maze){
    for(int r = 0; r < maze.rows; r++){
      out << maze.grid[r] << endl;
    }

    return out;
  }
public:
  Maze(string* g, unsigned r): grid(g), rows(r), cols(g[0].size()){}

  void navigateMaze(){
    int r, c;
    Cell current = find_cell_by_marker(Marker::Entry);
    Cell exit = find_cell_by_marker(Marker::Exit);

    while(current != exit){
      r = current.r;
      c = current.c;

      grid[r][c] = static_cast<char>(Marker::Visited);

      push_to_stack(r-1, c); // top
      push_to_stack(r+1, c); // bottom
      push_to_stack(r, c-1); // left
      push_to_stack(r, c+1); // right

      if(s.empty()) {
        cout << "Impossible to exit!" << endl;
        cout << *this;
        return;
      }else{
        current = s.pop();
      }
    }

    cout << *this;
    cout << "You successfully exited the maze!" << endl;
  }

};

int main(){
  string mazeGrid [] {
    "++++++++++++",
    "++         +",
    "+ +  + +  ++",
    "X   ++++   +",
    "+ ++++++++ +",
    "+ + + + +  +",
    "+  +  +    +",
    "+++++++ ++++",
    "+   +N+ +  +",
    "+       ++++",
    "++++++++++++"
  };

  Maze maze(mazeGrid, 11u);
  maze.navigateMaze();

  return 0;
}