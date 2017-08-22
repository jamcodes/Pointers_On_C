#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

#include <stdlib.h>
#include <stdbool.h>

struct dll_node{
    struct dll_node *next;
    struct dll_node *prev;
    void* value;
};
typedef struct dll_node DllNode;

struct DLL{
    DllNode *first;
    DllNode *last;
    size_t count;
};
typedef struct DLL DLL;


DLL* DLL_create();
void DLL_destroy(DLL* list);
void DLL_clear(DLL* list);
void DLL_clear_destroy(DLL* list);

#define DLL_count(A)    ( (A)->count )
#define DLL_first(A)    ( (A)->first != NULL ? (A)->first->value : NULL )
#define DLL_last(A)     ( (A)->last != NULL ? (A)->last->value : NULL )

void  DLL_pushfront(DLL* list, void* value);
void* DLL_popfront(DLL* list);

void  DLL_pushback(DLL* list, void* value);
void* DLL_popback(DLL* list);

void* DLL_remove(DLL* list, DllNode* node);
void* DLL_delete(DLL* list, bool(*eq)(void* a, void* b), void* value);

int DLL_insert(DLL* list, int(*cmp)(void* a, void* b), void* value);


#endif /*DOUBLE_LINKED_LIST_H_*/
