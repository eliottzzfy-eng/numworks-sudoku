#ifndef SUDOKU_MODEL_H
#define SUDOKU_MODEL_H
class Model {
public:
  Model();
  int cell(int x,int y) const;
  void setCell(int x,int y,int v);
  void newPuzzle(int diff);
  bool isFixed(int x,int y) const;
  void toggleHint(int x,int y);
private:
  int m_grid[81];
  bool m_fixed[81];
  void loadFromString(const char* s);
  void generateFromSeed(int diff);
};
#endif