#include <assert.h>
#include <ngl_builtins.h>
#include <ngl_error.h>
#include <ngl_stack_ngl_val.h>

int main() {
  ngl_builtins_init();
  ngl_stack s;
  assert(ngl_ok == ngl_stack_init(&s));
  ngl_stack_push(&s, ngl_val_int(0));
  ngl_stack_push(&s, ngl_val_int(1));
  assert(ngl_stack_get(&s, 0).integer == 1);
  assert(ngl_stack_get(&s, 1).integer == 0);
  }
