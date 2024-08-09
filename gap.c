#include "gap.h"
#include <stdio.h>
#include <stdlib.h>

int gap_init(Gap *gap, size_t len) {
  gap->data = calloc(len + 1, sizeof(char));
  gap->len = len;
  gap->left = 0;
  gap->right = len - 1;
  if (gap->data == NULL)
    return -1;
  return 0;
}

// insert at left
int gap_insert(Gap *gap, char *s, size_t len) {
  if (len >= gap->right - gap->left) {
    // todo increse size;
  }
  for (int i = 0; i < len; i++) {
    gap->data[gap->left + i] = s[i];
  }
  gap->left += len;
  return 0;
}

void gap_debug_print(Gap *gap) {
  char *str = calloc(gap->len + 1, sizeof(char));
  for (size_t i = 0; i < gap->len; i++) {
    if (gap->data[i] == 0) {
      str[i] = '-';
      if (i == gap->left)
        str[i] = '<';
      if (i == gap->right)
        str[i] = '>';
    } else {
      str[i] = gap->data[i];
    }
  }
  printf("%s\n%ld %ld %ld", str, gap->left, gap->right, gap->len);
  free(str);
}

int gap_move_cursor(Gap *gap, size_t pos) {
  if (pos >= gap->len - (gap->right - gap->left))
    return -1;
  if (pos == gap->left)
    return 0;
  if (pos < gap->left) {
    size_t diff = gap->left - pos;
    for (size_t i = 0; i < diff; i++) {
      gap->data[gap->right - i] = gap->data[gap->left - i - 1];
      gap->data[gap->left - i] = 0;
    }
    gap->data[pos] = 0;
    gap->left = pos;
    gap->right -= diff;
  } else {
    // pos > right
    size_t diff = pos - gap->left;
    for (size_t i = 0; i < diff; i++) {
      gap->data[gap->left + i] = gap->data[gap->right + i + 1];
      gap->data[gap->right + i + 1] = 0;
    }
    gap->left = pos;
    gap->right += diff;
    // gap->data[gap->left]=0;
  }
  return 0;
}
