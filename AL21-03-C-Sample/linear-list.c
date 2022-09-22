#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief データと続くリストを保持する構造体.
*/
typedef struct cell cell;

/**
 * @brief cellのポインタの型.
*/
typedef cell* list;

struct cell
{
  int element; /** int型で表されたデータ. */
  list next;  /** 続くリストの先頭のcellのポインタ/list. */
};


/**
 * @brief cellの初期化.
 * @return 初期化された,データやポインタが代入されていないcellのポインタ.
*/
cell* init_cell()
{
  cell* c = (cell*) malloc( sizeof(cell) );
  return c;
}

/**
 * @brief listの初期化. 
 * @return NULLのlist.
*/
list init_list()
{
  list l = NULL;
  return l;
}

/**
 * @brief 引数のcellを削除する.
 * @param[in] c 削除するcellのポインタ.
*/
void dispose(cell* c)
{
  free(c);
}

/**
 * @brief 引数のlistをメモリ解放する.
 * @param[in] list_head メモリ解放するlistのポインタ.
*/
void release_list(list* list_head)
{
  cell* disposing_cell = *list_head;
  cell* next_cell = *list_head;
  for(;next_cell != NULL;)
  {
    next_cell = disposing_cell->next;
    dispose(disposing_cell);
    disposing_cell = next_cell;
  }
  *list_head = NULL;
}

/**
 * @brief previousの後ろにvalを挿入する. Program 1.3.4
 * @param[in] previous 挿入する位置の前のcellをさすポインタ.
 * @param[in] val 挿入するint型のデータ.
*/
void insert_cell(cell* previous, int val)
{
  cell* q = init_cell();
  q->element = val;
  q->next = previous->next;
  previous->next = q;
}

/**
 * @brief リストの先頭にvalを挿入し,listを更新する. Program 1.3.6
 * @param[in] list 先頭に挿入するlistのポインタ.
 * @param[in] val 挿入するint型のデータ.
*/
void insert_head(list* list_head, int val)
{
  cell* q = init_cell();
  q->element = val;
  q->next = *list_head;
  *list_head = q;
}

/**
 * @brief previousの後ろのcellを削除する. Program 1.3.7
 * @param[in] previous 削除するcellの前のcellをさすポインタ.
*/
void delete_cell(cell* previous)
{
  cell* q = previous->next;
  previous->next = q->next;
  dispose(q);
}

/**
 * @brief リストの先頭を削除し,list_headを更新する. Program 1.3.9
 * @param[in] list_head 先頭を削除するlistのポインタ.
*/
void delete_head(list* list_head)
{
  cell* q = *list_head;
  *list_head = q->next;
  dispose(q);
}

/**
 * @brief list確認用プリント関数.
 * @param[in] list_head プリントするlist.
*/
void print_list(list list_head)
{
  cell* c = list_head;
  printf("LIST: [ ");
  for(;c != NULL;c = c->next)
  {
    printf("%d ", c->element);   
  }
  printf("]\n");
}

int main()
{
  //list_headを更新する関数でポインタを渡す必要有り
  list list_head = init_list();

  cell* example_cell;
  for(int i = 0; i < 20; i++)
  {
    insert_head(&list_head, i);
    if(i==6) example_cell = list_head;
  }  
  print_list(list_head);
  insert_cell(example_cell, 100);
  print_list(list_head);
  delete_cell(example_cell);
  print_list(list_head);
  delete_head(&list_head);
  print_list(list_head);

  release_list(&list_head);
  print_list(list_head);

  return 0;
}