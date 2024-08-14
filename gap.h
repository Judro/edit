#ifndef GAP_H
#define GAP_H
#include <stddef.h>
typedef struct {
  char *data;
  size_t len;
  size_t left;
  size_t right;
} Gap;

int gap_init(Gap *gap, size_t len);
int gap_insert(Gap *gap, char *s, size_t len);
void gap_debug_print(Gap *gap);
int gap_move_cursor(Gap *gap, size_t pos);
int gap_delete(Gap *gap);

#endif
