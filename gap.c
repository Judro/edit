#include "gap.h"
#include <stdio.h>
#include <stdlib.h>

int gap_init(Gap *gap, size_t len) {
  gap->data = calloc(len, sizeof(char));
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
  char *str = calloc(gap->len, sizeof(char));
  for (size_t i = 0; i < gap->len; i++) {
    if (gap->data[i] == 0) {
      str[i] = '-';
    } else {
      str[i] = gap->data[i];
    }
  }
  printf("%s\n%ld %ld %ld", str, gap->left, gap->right, gap->len);
}
