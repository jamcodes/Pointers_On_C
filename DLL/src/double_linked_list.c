#include "double_linked_list.h"
#include "debug.h"


DLL* DLL_create()
{
    return (DLL*)calloc(1, sizeof(DLL));
}


void DLL_destroy(DLL* list)
{
    DllNode* cur = list->first;
    for(cur = cur->next; cur != NULL; cur = cur->next){
        free(cur->prev);
    }
    free(list->last);
    free(list);
}


void DLL_clear(DLL* list)
{
    for(DllNode* cur = list->first; cur != NULL; cur = cur->next){
        free(cur->value);
    }
}


void DLL_clear_destroy(DLL* list)
{
    DllNode* cur = list->first;
    for(cur = cur->next; cur != NULL; cur = cur->next){
        free(cur->prev->value);
        free(cur->prev);
    }
    free(list->last->value);
    free(list->last);
    free(list);
}


void DLL_pushfront(DLL* list, void* value)
{
    DllNode* node = (DllNode*)calloc(1, sizeof(DllNode));
    if( node == NULL ){
        log_err("Allocation error");
        return;
    }

    node->value = value;
    node->next = list->first;
    if( list->first == NULL ){
        list->last = node;
    }else{
        list->first->prev = node;
    }
    list->first = node;
    ++list->count;
}


void* DLL_popfront(DLL* list)
{
    DllNode* node = list->first;
    return node != NULL ? DLL_remove(list, node) : NULL;
}


void DLL_pushback(DLL* list, void* value)
{
    DllNode* node = (DllNode*)calloc(1, sizeof(DllNode));
    if( node == NULL ){
        log_err("Allocation error");
        return;
    }

    node->value = value;
    node->prev = list->last;
    if( list->last == NULL ){
        list->first = node;
    }else{
        list->last->next = node;
    }
    list->last = node;

    ++list->count;
}


void* DLL_popback(DLL* list)
{
    DllNode* node = list->last;
    return node != NULL ? DLL_remove(list, node) : NULL;
}


void* DLL_remove(DLL* list, DllNode* node)
{
    void* result = NULL;
    if( list->first == NULL || list->last == NULL ){
        log_err("Empty list");
        goto error;
    }
    if( node == NULL ){
        log_err("NULL node");
        goto error;
    }

    if( node == list->first && node == list->last ){
        list->first = NULL;
        list->last = NULL;
    }else if( node == list->first ){
        list->first = node->next;
        list->first->prev = NULL;
    }else if( node == list->last ){
        list->last = node->prev;
        list->last->next = NULL;
    }else{
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    --list->count;
    result = node->value;
    free(node);

error:
    return result;
}


void* DLL_delete(DLL* list, bool(*eq)(void* a, void* b), void* value)
{
    DllNode* cur = list->first;

    while( cur != NULL && eq(cur->value, value) == false ){
        cur = cur->next;
    }

    return cur != NULL ? DLL_remove(list, cur) : NULL;       
}


int DLL_insert(DLL* list, int(*cmp)(void* a, void* b), void* value)
{
    register DllNode *cur;
    register DllNode *new_node;

    for( cur = list->first; cur != NULL; cur = cur->next ){
        if( cmp(cur->value, value) > 0 ) /* allow duplicates */
            break;
    }

    new_node = (DllNode*)malloc(sizeof(DllNode));
    if( new_node == NULL )
        return -1;

    new_node->value = value;

    /* insert the new node before cur (which is bigger than new_node's value) */
    if( cur == NULL && list->first == NULL && list->last == NULL ){
        list->first = new_node;
        list->last = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }else if( cur == NULL ){
        new_node->prev = list->last;
        new_node->next = NULL;
        list->last->next = new_node;
        list->last = new_node;
    }else if( cur == list->first ){
        new_node->prev = NULL;
        new_node->next = cur;
        cur->prev = new_node;
        list->first = new_node;
    }else{
        new_node->prev = cur->prev;
        cur->prev->next = new_node;
        new_node->next = cur;
        cur->prev = new_node;
    }

    ++list->count;
    return 1;
}
