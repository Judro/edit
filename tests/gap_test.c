#include "../gap.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void init(void) {
  Gap gap;
  assert(gap_init(&gap, 255) == 0);
  free(gap.data);
}
void simple_insert(void) {
  Gap gap;
  gap_init(&gap, 255);
  assert(gap_insert(&gap, "Hello", 5) == 0);
  assert(strcmp("Hello", gap.data) == 0);
  free(gap.data);
}

void move_curser_left(void) {
  Gap gap;
  gap_init(&gap, 255);
  gap_insert(&gap, "Hello", 5);
  assert(gap_move_cursor(&gap, 2) == 0);
  assert(strcmp("He", gap.data) == 0);
  free(gap.data);
}

void move_curser_right(void) {
  Gap gap;
  gap_init(&gap, 255);
  gap_insert(&gap, "Hello", 5);
  assert(gap_move_cursor(&gap, 0) == 0);
  assert(gap_move_cursor(&gap, 1) == 0);
  assert(strcmp("H", gap.data) == 0);
  assert(gap_move_cursor(&gap, 0) == 0);
  assert(gap_move_cursor(&gap, 3) == 0);
  assert(strcmp("Hel", gap.data) == 0);
  assert(gap_move_cursor(&gap, 5) == 0);
  assert(strcmp("Hello", gap.data) == 0);
  free(gap.data);
}

void insert_2(void) {
  Gap gap;
  gap_init(&gap, 255);
  gap_insert(&gap, "Hello", 5);
  assert(gap_move_cursor(&gap, 2) == 0);
  assert(strcmp("He", gap.data) == 0);
  assert(gap_insert(&gap, "aaa", 3) == 0);
  assert(strcmp("Heaaa", gap.data) == 0);
  assert(gap_move_cursor(&gap, 8) == 0);
  assert(gap_insert(&gap, "end", 3) == 0);
  assert(strcmp("Heaaalloend", gap.data) == 0);
  free(gap.data);
}

int main(void) {
  init();
  simple_insert();
  move_curser_left();
  move_curser_right();
  insert_2();
}
