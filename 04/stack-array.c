#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief スタックの配列がとれる最大要素数. */
#define SIZE 1000

/**
 * @brief スタックの配列とメタ情報を保持する構造体.
 */
typedef struct {
  size_t length;      /** 配列の長さ. */
  int elements[SIZE]; /** 要素の配列. */
} stack;

/**
 * @brief stackの初期化.
 */
stack* init_stack() {
  stack* s = (stack*)malloc(sizeof(stack));
  s->length = 0;
  return s;
}

/**
 * @brief stackの要素をクリアする.
 */
void clear_stack(stack* stack) {
  stack->length = 0;
}

/**
 * @brief stackのメモリを解放.
 */
void release_stack(stack* stack) {
  free(stack);
}

/**
 * @brief valをスタックにプッシュする.
 */
void push(stack* stack, int val) {
  if (stack->length >= SIZE) {
    printf("No more element can be pushed into the stack.\n");
    return;
  }

  stack->elements[stack->length] = val;
  stack->length++;
}

/**
 * @brief スタックの先頭をポップする.
 */
void pop(stack* stack, int* val) {
  if (stack->length == 0) {
    printf("No more element can be popped from the elements.\n");
    return;
  }

  stack->length--;
  *val = stack->elements[stack->length];
}

/**
 * @brief stack確認用プリント関数.
 */
void print_stack(stack* stack) {
  printf("ELEMENTS: [ ");
  for (int i = stack->length - 1; i >= 0; i--) {
    printf("%d ", stack->elements[i]);
  }
  printf("]\nSTACK POINTER: %ld\n", stack->length);
}

int main() {
  stack* stack = init_stack();
  print_stack(stack);

  for (int i = 0; i < 10; i++) {
    push(stack, i);
  }
  print_stack(stack);

  int val;
  pop(stack, &val);
  print_stack(stack);
  printf("POP: %d\n", val);

  clear_stack(stack);
  print_stack(stack);

  release_stack(stack);
  return 0;
}

// 実行結果
// ELEMENTS: [ ]
// STACK POINTER: 0
// ELEMENTS: [ 9 8 7 6 5 4 3 2 1 0 ]
// STACK POINTER: 10
// ELEMENTS: [ 8 7 6 5 4 3 2 1 0 ]
// STACK POINTER: 9
// POP: 9
// ELEMENTS: [ ]
// STACK POINTER: 0