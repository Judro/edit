#include "display.h"
#include "config.h"
#include "gap.h"
void init_display(DisplayBundle *display) {
  display->window = initscr();
  curs_set(0);
  noecho();
  gap_init(&display->buffer, DEFAULT_GAP_SIZE);
  // TODO remove me
  gap_insert(&display->buffer, "Hello World", 11);
}

void destroy_display(DisplayBundle *display) {
  destroy_gap(&display->buffer);
  endwin();
}
