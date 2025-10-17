#ifndef SUDOKU_STORAGE_H
#define SUDOKU_STORAGE_H
#include <escher.h>
class Storage {
public:
  static void save(const char * key, const void * data, int len);
  static void load(const char * key, void * data, int len);
};
#endif