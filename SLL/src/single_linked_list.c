#include "single_linked_list.h"
#include "debug.h"
#include <stdbool.h>


SLL* SLL_create()
{
    return  (SLL*)calloc(1, sizeof(SLL));
}


void SLL_destroy(SLL* list)
{
    SllNode *cur, *prev;

    cur = prev = list->first;
    if(cur == NULL)
        return;

    for(cur = cur->next; cur != NULL; prev = cur, cur = cur->next){
            free(prev);
    }
    free(prev);
    free(list);
}


void SLL_clear(SLL* list)
{
    SllNode *cur;

    for(cur = list->first; cur != NULL; cur = cur->next){
        free(cur->value);
    }
}


void SLL_clear_destroy(SLL* list)
{
    SllNode *cur, *prev;

    cur = prev = list->first;
    if(cur == NULL)
        return;

    for(cur = cur->next; cur != NULL; prev = cur, cur = cur->next){
        free(prev->value);
        free(prev);
    }
    free(prev);
    free(list);
}

void SLL_pushfront(SLL* list, void* value)
{
    SllNode* node = (SllNode*)calloc(1, sizeof(SllNode));
    if(node == NULL){
        log_err("Allocation error");
        return;
    }

    node->value = value;

    node->next = list->first;
    list->first = node;
    if(list->last == NULL)
        list->last = node;
    ++list->count;
}


void* SLL_popfront(SLL* list)
{
    void* result;
    SllNode* node = list->first;

    if(node == NULL)
        return NULL;

    if(node == list->last){
        list->first = NULL;
        list->last = NULL;
    }else
        list->first = node->next;
    
    --list->count;
    result = node->value;
    free(node);
    
    return result;
}


void SLL_pushback(SLL* list, void* value)
{
    SllNode* node = (SllNode*)calloc(1, sizeof(SllNode));
    if(node == NULL){
        log_err("Allocation error");
        return;
    }

    node->value = value;
    if(list->last != NULL){
        list->last->next = node;
    }else{
        list->first = node;
    }
    list->last = node;

    ++list->count;
}


void* SLL_remove(SLL* list, SllNode* node)
{
    void* result = NULL;
    SllNode *prev;

    if(list->first == NULL || list->last == NULL){
        log_err("Empty list passed to SLL_remove");
        goto error;
    }
    if(node == NULL){
        log_err("Null node");
        goto error;
    }

    if(node == list->first && node == list->last){
        list->first = NULL;
        list->last = NULL;
    }else if(node == list->first){
        list->first = node->next;
    }else{
        prev = list->first;
        for(;
            prev != NULL && prev->next != node;
            prev = prev->next)
            ;
        if(prev != NULL){
            prev->next = node->next;
        }else{
            log_err("Unlinked node");
            goto error;
        }
        if(node == list->last){
            list->last = prev;
        }
    }
    result = node->value;
    free(node);
    --list->count;

error:
    return result;
}


bool SLL_insert(SLL* list, int(*cmp)(void* fst, void* snd), void* value)
{
    register SllNode *cur;
    register SllNode *new;
    register SllNode **linkp;

    if( list == NULL ){
        log_err("NULL list");
        return false;
    }

    linkp = &list->first;

    while( (cur = *linkp) != NULL && (cmp(cur->value, value) < 0) )
            linkp = &cur->next;

    new = (SllNode*)malloc(sizeof(SllNode));
    if( new == NULL )
        return false;

    new->value = value;
    new->next = cur;
    *linkp = new;

    if(cur == NULL)
        list->last = new;

    ++list->count;
    return true;
}


int SLL_get_count(const SLL* list)
{
    register const SllNode* node = list->first;
    register int count = 0;
    
    while( node != NULL ){
        node = node->next;
        ++count;
    }

    return count;
}

SllNode*
SLL_get_node(const SLL* list, _Bool(*eq)(void* a, void* b), void* value)
{
    register SllNode* node = list->first;

    while( node != NULL && eq(node->value, value) == false ){
        node = node->next;
    }

    return node;
}


void SLL_reverse(SLL* list)
{
    SLL new_list = (SLL){0};
    SllNode *last, *head, *next;
    last = NULL;
    
    new_list.last = list->first;
    new_list.first = list->last;

    head = list->first;
    while( head != NULL ){
        next = head->next;
        head->next = last;
        last = head;
        head = next;
    }

    list->first = new_list.first;
    list->last = new_list.last;
}


void SLL_traverse(SLL* list, void(*cb)(SllNode*))
{
    SllNode *node = list->first;

    while( node != NULL ){
        cb(node);
        node = node->next;
    }
}


void* SLL_foldl(SLL* list, void(*cb)(void*, void*), void* acc)
{
    SllNode *node = list->first;

    while( node != NULL ){
        cb(acc, node->value);
        node = node->next;
    }

    return acc;
}
