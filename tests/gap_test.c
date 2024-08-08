#include "../gap.h"
#include <assert.h>
#include <string.h>

void init(void) {
  Gap gap;
  assert(gap_init(&gap, 255) == 0);
}
void simple_import(void) {
  Gap gap;
  gap_init(&gap, 255);
  assert(gap_insert(&gap, "Hello", 5) == 0);
  assert(strcmp("Hello", gap.data) == 0);
  gap_debug_print(&gap);
}

int main(void) {
  init();
  simple_import();
}
