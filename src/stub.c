#include "mruby.h"
#include "mruby/irep.h"
#include "lib.c"

int main(void) {
  mrb_state *mrb = mrb_open();
  if (!mrb) { /* handle error */ }
  mrb_load_irep(mrb, lib);
  mrb_close(mrb);
}
