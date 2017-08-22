#include "minunit.h"
#include <single_linked_list.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


static SLL* sll = NULL;
char* test1 = "test1 data";
char* test2 = "test2 data";
char* test3 = "test3 data";


int cmp(void* fst, void* snd)
{
    return strcmp((char*)fst, (char*)snd);
}

bool eq(void* a, void* b)
{
    return strcmp((char*)a, (char*)b) == 0;
}

char* test_create()
{
    sll = SLL_create();
    mu_assert(sll != NULL, "Failed to create list.");

    return NULL;
}

char* test_destroy()
{
    SLL_destroy(sll);

    return NULL;
}


char* test_push_pop()
{
    SLL_pushback(sll, test1);
    mu_assert(SLL_last(sll) == test1, "Wrong last value.");

    SLL_pushback(sll, test2);
    mu_assert(SLL_last(sll) == test2, "Wrong last value.");

    SLL_pushfront(sll, test3);
    mu_assert(SLL_first(sll) == test3, "Wrong first value.");

    char* val = SLL_popfront(sll);
    mu_assert(val == test3, "Wrong value on pop.");

    val = SLL_popfront(sll);
    mu_assert(val == test1, "Wrong value on pop.");

    val = SLL_popfront(sll);
    mu_assert(val == test2, "Wrong value on pop.");
    mu_assert(SLL_count(sll) == 0, "Wrong count after pop.");

    return NULL;
}


char* test_remove()
{
    SLL_pushback(sll, test1);
    mu_assert(SLL_last(sll) == test1, "Wrong last value.");

    SLL_pushback(sll, test2);
    mu_assert(SLL_last(sll) == test2, "Wrong last value.");

    SLL_pushback(sll, test3);
    mu_assert(SLL_last(sll) == test3, "Wrong last value.");

    char* val = SLL_remove(sll, sll->first->next);
    mu_assert(val == test2, "Wrong removed element.");
    mu_assert(SLL_count(sll) == 2, "Wrong count after remove");
    mu_assert(SLL_first(sll) == test1, "Wrong first elem after 1st remove.");
    mu_assert(SLL_last(sll) == test3, "Wrong last elem after 1st remove.");

    val = SLL_remove(sll, sll->first->next);
    mu_assert(val == test3, "Wrong removed element.");
    mu_assert(SLL_count(sll) == 1, "Wrong count after remove");
    mu_assert(SLL_first(sll) == test1, "Wrong first elem after 2nd remove.");
    mu_assert(SLL_last(sll) == test1, "Wrong last elem after 2nd remove.");

    val = SLL_remove(sll, sll->first);
    mu_assert(val == test1, "Wrong removed element.");
    mu_assert(SLL_count(sll) == 0, "Wrong count after remove");
    mu_assert(SLL_first(sll) == NULL, "Wrong first elem after 3rd remove.");
    mu_assert(SLL_last(sll) == NULL, "Wrong last elem after 3rd remove.");

    return NULL;
}


char* test_insert()
{
    SLL_insert(sll, cmp, test1);
    mu_assert(SLL_first(sll) == test1, "Wrong first value after 1st insert");
    mu_assert(SLL_last(sll) == test1, "Wrong last value after 1st insert");
    mu_assert(SLL_count(sll) == 1, "Wrong count after insert");

    SLL_insert(sll, cmp, test1);
    mu_assert(SLL_first(sll) == test1, "Wrong first value after 2nd insert");
    mu_assert(SLL_last(sll) == test1, "Wrong last value after 2nd insert");
    mu_assert(SLL_count(sll) == 2, "Wrong count after 2nd insert");

    SLL_insert(sll, cmp, test2);
    mu_assert(SLL_first(sll) == test1, "Wrong first value after 3rd insert");
    mu_assert(SLL_last(sll) == test2, "Wrong last value after 3rd insert");
    mu_assert(SLL_count(sll) == 3, "Wrong count after 3rd insert");

    SLL_insert(sll, cmp, test3);
    mu_assert(SLL_first(sll) == test1, "Wrong first value after 3rd insert");
    mu_assert(SLL_last(sll) == test3, "Wrong last value after 3rd insert");
    mu_assert(SLL_count(sll) == 4, "Wrong count after 3rd insert");

    SLL_insert(sll, cmp, test3);
    mu_assert(SLL_first(sll) == test1, "Wrong first value after 3rd insert");
    mu_assert(SLL_last(sll) == test3, "Wrong last value after 3rd insert");
    mu_assert(SLL_count(sll) == 5, "Wrong count after 3rd insert");

    return NULL;
}

char* test_get_count()
{
    int count = SLL_get_count(sll);
    mu_assert(count == SLL_count(sll), "Wrong count");

    return NULL;
}

char* test_get_node()
{
    SllNode* node = SLL_get_node(sll, eq, "test1 data");
    mu_assert(node != NULL, "NULL node on test 1");
    mu_assert(node->value == test1, "Wrong node on get node test1");

    node = SLL_get_node(sll, eq, "test2 data");
    mu_assert(node != NULL, "NULL node on test 2");
    mu_assert(node->value == test2, "Wrong node on get node test2");

    node = SLL_get_node(sll, eq, "test3 data");
    mu_assert(node != NULL, "NULL node on test 3");
    mu_assert(node->value == test3, "Wrong node on get node test3");

    return NULL;
}

char* test_reverse()
{
    SllNode* first = sll->first;
    SllNode* last = sll->last;
    SllNode* printer = sll->first;
    
    while( printer != NULL ){
        printf("\t%s\n", printer->value);
        printer = printer->next;
    }

    SLL_reverse(sll);
    mu_assert(sll->first == last, "Invalid first value");
    mu_assert(sll->last == first, "Invalid last value");

    printer = sll->first;
    printf("\n---\n");
    while( printer != NULL ){
        printf("\t%s\n", printer->value);
        printer = printer->next;
    }

    return NULL;
}

char* all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_remove);
    mu_run_test(test_insert);
    mu_run_test(test_get_count);
    mu_run_test(test_get_node);
    mu_run_test(test_reverse);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
