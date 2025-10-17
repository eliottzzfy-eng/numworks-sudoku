#include "model.h"
#include <string.h>
static const char* PRESET_EASY[] = {
 "530070000600195000098000060800060003400803001700020006060000280000419005000080079",
 "000260701680070090190004500820100040004602900050003028009300074040050036703018000"
};
static const char* PRESET_HARD[] = {
 "300200000000107000706030500070009080900020004010800050009040301000702000000008006"
};
Model::Model(){ newPuzzle(0); }
int Model::cell(int x,int y) const { return m_grid[y*9+x]; }
void Model::setCell(int x,int y,int v){ if(!m_fixed[y*9+x]) m_grid[y*9+x]=v; }
bool Model::isFixed(int x,int y) const { return m_fixed[y*9+x]; }
void Model::toggleHint(int x,int y){ /* placeholder: would compute pencil marks or suggestions */ }
void Model::loadFromString(const char* s){
  for(int i=0;i<81;i++){ char c=s[i]; m_grid[i]=(c>='1'&&c<='9')?c-'0':0; m_fixed[i]=m_grid[i]!=0; }
}
void Model::generateFromSeed(int diff){
  // simple: pick preset
  if(diff==0) loadFromString(PRESET_EASY[0]); else loadFromString(PRESET_HARD[0]);
}
void Model::newPuzzle(int diff){ generateFromSeed(diff); }