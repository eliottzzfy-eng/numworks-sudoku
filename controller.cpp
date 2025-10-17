#include "controller.h"
#include <ion.h>
#include <assert.h>
using namespace Escher;
Controller::Controller(Escher::App * a):ViewController(),m_view(&m_model),m_model(){}
void Controller::didBecomeFirstResponder(){newGame(0);}
bool Controller::handleEvent(Ion::Events::Event e){
  if(e==Ion::Events::OK){m_model.toggleHint(m_selectedX,m_selectedY);return true;}
  if(e==Ion::Events::Right){m_selectedX=(m_selectedX+1)%9;return true;}
  if(e==Ion::Events::Left){m_selectedX=(m_selectedX+8)%9;return true;}
  if(e==Ion::Events::Down){m_selectedY=(m_selectedY+1)%9;return true;}
  if(e==Ion::Events::Up){m_selectedY=(m_selectedY+8)%9;return true;}
  if(e==Ion::Events::Back){showMenu();return true;}
  return false;
}
void Controller::newGame(int diff){m_model.newPuzzle(diff);m_view.reload();}
void Controller::toggleDark(){m_view.setDark(!m_view.m_dark);m_view.reload();}
void Controller::showMenu(){/* placeholder for menu UI */}
void Controller::GridView::drawRect(KDContext * ctx, KDRect r) const {
  KDCoordinate w = bounds().width(), h = bounds().height();
  KDCoordinate cw = w/9, ch = h/9;
  // background
  ctx->fillRect(KDRect(0,0,w,h), m_dark?KDColorBlack:KDColorWhite);
  // grid lines
  for(int i=0;i<=9;i++){
    KDColor c = (i%3==0)?KDColorBlack:KDColorGray;
    ctx->drawLine(KDPoint(i*cw,0),KDPoint(i*cw,h));
    ctx->drawLine(KDPoint(0,i*ch),KDPoint(w,i*ch));
  }
  // numbers
  for(int y=0;y<9;y++) for(int x=0;x<9;x++){
    int v = m_model->cell(x,y);
    if(v){
      char buf[2] = {(char)('0'+v),0};
      KDPoint p(x*cw + cw/2 - 4, y*ch + ch/2 - 8);
      ctx->drawString(buf,p);
    }
  }
}