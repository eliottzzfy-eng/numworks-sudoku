#ifndef SUDOKU_APP_H
#define SUDOKU_APP_H
#include <escher.h>
#include "controller.h"
class App : public Escher::App {
public:
  App();
  const char * name() const override { return "Sudoku"; }
  Escher::StackViewController * stack() { return &m_stack; }
private:
  Escher::StackViewController m_stack;
  Controller m_controller{this};
};
#endif