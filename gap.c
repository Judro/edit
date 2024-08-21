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

int gap_grow(Gap *gap) {
  char *data = malloc((2 * gap->len + 1) * sizeof(char));
  if (data == NULL) {
    return -1;
  }
  data[2 * gap->len] = 0;

  // for testing (remove me)
  for (size_t i = 0; i < 2 * gap->len; i++) {
    data[i] = '#';
  }
  // end

  for (size_t i = 0; i < gap->left; i++) {
    data[i] = gap->data[i];
  }
  for (size_t i = gap->left; i <= gap->right + gap->len; i++) {
    data[i] = 0;
  }
  for (size_t i = gap->right + 1; i < gap->len; i++) {
    data[i + gap->len] = gap->data[i];
  }

  free(gap->data);
  gap->right += gap->len;
  gap->len *= 2;
  gap->data = data;
  return 0;
}

// delete at left
int gap_delete(Gap *gap) {
  if (gap->left == 0) {
    return -1;
  }
  gap->left--;
  gap->data[gap->left] = 0;
  return 0;
}

// insert at left
int gap_insert(Gap *gap, char *s, size_t len) {
  if (len >= gap->right - gap->left) {
    do {
      gap_grow(gap);
    } while (len >= gap->len);
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
      // bug .. inspect it  why does the else not overwrite it. a else if should
      // help but I havent encountered an error? please test it
      if (i == gap->right)
        str[i] = '>';
    } else {
      str[i] = gap->data[i];
    }
  }
  printf("%s\n%ld %ld %ld\n", str, gap->left, gap->right, gap->len);
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

void destroy_gap(Gap *gap) { free(gap->data); }
