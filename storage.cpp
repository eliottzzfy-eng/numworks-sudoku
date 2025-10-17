#include "storage.h"
#include <ion.h>
#include <stddef.h>
void Storage::save(const char * key, const void * data, int len){
  // placeholder: use Ion::Storage API or Flash to persist
  (void)key;(void)data;(void)len;
}
void Storage::load(const char * key, void * data, int len){
  (void)key;(void)data;(void)len;
}