#include "config.h"
#include "display.h"
#include "gap.h"
#include <curses.h>
#include <stdlib.h>

int main(void) {
  DisplayBundle display;
  init_display(&display);

  getch();
  destroy_display(&display);
  return 0;
}
