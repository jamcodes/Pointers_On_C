#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_

#include <stdlib.h>
#include <stdbool.h>

struct sll_node{
    struct sll_node *next;
    void* value;
};
typedef struct sll_node SllNode;

struct SLL{
    int count;
    SllNode *first;
    SllNode *last;
};
typedef struct SLL SLL;

SLL* SLL_create();
void SLL_destroy(SLL* list);
void SLL_clear(SLL* list);
void SLL_clear_destroy(SLL* list);

#define SLL_count(A)    ( (A)->count )
#define SLL_first(A)    ( (A)->first != NULL ? (A)->first->value : NULL )
#define SLL_last(A)     ( (A)->last != NULL ? (A)->last->value : NULL )

void  SLL_pushfront(SLL* list, void* value);
void* SLL_popfront(SLL* list);

void  SLL_pushback(SLL* list, void* value);

void* SLL_remove(SLL* list, SllNode* node);

bool SLL_insert(SLL* list, int(*cmp)(void* fst, void* snd), void* value);

int SLL_get_count(const SLL* list);

SllNode* SLL_get_node(const SLL* list, _Bool(*eq)(void* a, void* b), void* value);

void SLL_reverse(SLL* list);

void SLL_traverse(SLL* list, void(*cb)(SllNode*));

void SLL_foldl(SLL* list, void(*cb)(void*, void*));

#endif /*SINGLE_LINKED_LIST_H_*/
