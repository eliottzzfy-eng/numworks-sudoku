#ifndef SUDOKU_CONTROLLER_H
#define SUDOKU_CONTROLLER_H
#include <escher.h>
#include "model.h"
class Controller : public Escher::ViewController, public Escher::SelectableTableViewDataSource {
public:
  Controller(Escher::App * a);
  const char * title() override { return "Sudoku"; }
  Escher::View * view() override { return &m_view; }
  void didBecomeFirstResponder() override;
  bool handleEvent(Ion::Events::Event e) override;
private:
  class GridView : public Escher::View {
  public:
    GridView(Model * m):m_model(m) {}
    void drawRect(KDContext * ctx, KDRect r) const override;
    void setDark(bool d){m_dark=d;}
  private:
    Model * m_model;
    bool m_dark=false;
  } m_view{nullptr};
  Model m_model;
  void showMenu();
  void newGame(int diff);
  void toggleDark();
  int m_selectedX=0,m_selectedY=0;
};
#endif