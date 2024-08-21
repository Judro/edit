#ifndef DISPLAY_H
#define DISPLAY_H
#include "gap.h"
#include <curses.h>
typedef struct {
  Gap buffer;
  WINDOW *window;
} DisplayBundle;

void init_display(DisplayBundle *display);
void destroy_display(DisplayBundle *);

#endif
