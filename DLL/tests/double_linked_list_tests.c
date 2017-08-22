#include "minunit.h"
#include <double_linked_list.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


static DLL* dll = NULL;
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
    dll = DLL_create();
    mu_assert(dll != NULL, "Failed to create list.");

    return NULL;
}

char* test_destroy()
{
    DLL_destroy(dll);

    return NULL;
}


char* test_clear_destroy()
{
    DLL* list = DLL_create();
    mu_assert(list != NULL, "Failed to create list");
    char *dynamic1, *dynamic2, *dynamic3;

    dynamic1 = (char*)malloc(sizeof(test1) + 1);
    dynamic2 = (char*)malloc(sizeof(test2) + 1);
    dynamic3 = (char*)malloc(sizeof(test3) + 1);

    mu_assert(dynamic1 != NULL, "Allocation error dynamic1");
    mu_assert(dynamic2 != NULL, "Allocation error dynamic2");
    mu_assert(dynamic3 != NULL, "Allocation error dynamic3");

    strcpy(dynamic1, test1);
    strcpy(dynamic2, test2);
    strcpy(dynamic3, test3);

    DLL_pushfront(list, dynamic1);
    mu_assert(DLL_first(list) == dynamic1, "Wrong first value after 1st push");
    DLL_pushfront(list, dynamic2);
    mu_assert(DLL_first(list) == dynamic2, "Wrong first value after 2st push");
    DLL_pushfront(list, dynamic3);
    mu_assert(DLL_first(list) == dynamic3, "Wrong first value after 2st push");

    mu_assert(DLL_count(list) == 3, "Wrong count after last push");
    DLL_clear_destroy(list);

    return NULL;
}


char* test_pushfront_popfront()
{
    DLL_pushfront(dll, test1);
    mu_assert(DLL_first(dll) == test1, "Wrong first value.");
    mu_assert(DLL_count(dll) == 1, "Wrong count after 1st push");

    DLL_pushfront(dll, test2);
    mu_assert(DLL_first(dll) == test2, "Wrong first value.");
    mu_assert(DLL_last(dll) == test1, "Wrong last value.");
    mu_assert(DLL_count(dll) == 2, "Wrong count after 2nd push");

    DLL_pushfront(dll, test3);
    mu_assert(DLL_first(dll) == test3, "Wrong first value.");
    mu_assert(DLL_last(dll) == test1, "Wrong last value.");
    mu_assert(DLL_count(dll) == 3, "Wrong count after 3rd push");

    char* val = DLL_popfront(dll);
    mu_assert(val == test3, "Wrong value on pop.");

    val = DLL_popfront(dll);
    mu_assert(val == test2, "Wrong value on pop.");

    val = DLL_popfront(dll);
    mu_assert(val == test1, "Wrong value on pop.");
    mu_assert(DLL_count(dll) == 0, "Wrong count after pop.");

    return NULL;
}


char* test_pushback_popback()
{
    DLL_pushback(dll, test1);
    mu_assert(DLL_first(dll) == test1, "Wrong first value.");
    mu_assert(DLL_count(dll) == 1, "Wrong count after 1st push");

    DLL_pushback(dll, test2);
    mu_assert(DLL_first(dll) == test1, "Wrong first value.");
    mu_assert(DLL_last(dll) == test2, "Wrong last value.");
    mu_assert(DLL_count(dll) == 2, "Wrong count after 2nd push");

    DLL_pushback(dll, test3);
    mu_assert(DLL_first(dll) == test1, "Wrong first value.");
    mu_assert(DLL_last(dll) == test3, "Wrong last value.");
    mu_assert(DLL_count(dll) == 3, "Wrong count after 3rd push");

    char* val = DLL_popback(dll);
    mu_assert(val == test3, "Wrong value on pop.");

    val = DLL_popback(dll);
    mu_assert(val == test2, "Wrong value on pop.");

    val = DLL_popback(dll);
    mu_assert(val == test1, "Wrong value on pop.");
    mu_assert(DLL_count(dll) == 0, "Wrong count after pop.");

    return NULL;
}


char* test_remove()
{
    DLL_pushback(dll, test1);
    mu_assert(DLL_last(dll) == test1, "Wrong last value.");

    DLL_pushback(dll, test2);
    mu_assert(DLL_last(dll) == test2, "Wrong last value.");

    DLL_pushback(dll, test3);
    mu_assert(DLL_last(dll) == test3, "Wrong last value.");

    char* val = DLL_remove(dll, dll->first->next);
    mu_assert(val == test2, "Wrong removed element.");
    mu_assert(DLL_count(dll) == 2, "Wrong count after remove");
    mu_assert(DLL_first(dll) == test1, "Wrong first elem after 1st remove.");
    mu_assert(DLL_last(dll) == test3, "Wrong last elem after 1st remove.");

    val = DLL_remove(dll, dll->first->next);
    mu_assert(val == test3, "Wrong removed element.");
    mu_assert(DLL_count(dll) == 1, "Wrong count after remove");
    mu_assert(DLL_first(dll) == test1, "Wrong first elem after 2nd remove.");
    mu_assert(DLL_last(dll) == test1, "Wrong last elem after 2nd remove.");

    val = DLL_remove(dll, dll->first);
    mu_assert(val == test1, "Wrong removed element.");
    mu_assert(DLL_count(dll) == 0, "Wrong count after remove");
    mu_assert(DLL_first(dll) == NULL, "Wrong first elem after 3rd remove.");
    mu_assert(DLL_last(dll) == NULL, "Wrong last elem after 3rd remove.");

    return NULL;
}


char* test_delete()
{
    DLL_pushback(dll, test1);
    mu_assert(DLL_last(dll) == test1, "Wrong last value.");

    DLL_pushback(dll, test2);
    mu_assert(DLL_last(dll) == test2, "Wrong last value.");

    DLL_pushback(dll, test3);
    mu_assert(DLL_last(dll) == test3, "Wrong last value.");

    char* val = DLL_delete(dll, eq, "test1 data");
    mu_assert(val == test1, "Wrong deleted element on 1st delete");

    val = DLL_delete(dll, eq, "test2 data");
    mu_assert(val == test2, "Wrong deleted element on 2nd delete");

    val = DLL_delete(dll, eq, "test3 data");
    mu_assert(val == test3, "Wrong deleted element on 3rd delete");

    return NULL;
}


char* test_insert()
{
    DLL_insert(dll, cmp, test2);
    mu_assert(DLL_first(dll) == test2, "Wrong first value after 1st insert");
    mu_assert(DLL_last(dll) == test2, "Wrong last value after 1st insert");
    mu_assert(DLL_count(dll) == 1, "Wrong count after insert");

    DLL_insert(dll, cmp, test2);
    mu_assert(DLL_first(dll) == test2, "Wrong first value after 2nd insert");
    mu_assert(DLL_last(dll) == test2, "Wrong last value after 2nd insert");
    mu_assert(DLL_count(dll) == 2, "Wrong count after 2nd insert");

    DLL_insert(dll, cmp, test1);
    mu_assert(DLL_first(dll) == test1, "Wrong first value after 3rd insert");
    mu_assert(DLL_last(dll) == test2, "Wrong last value after 3rd insert");
    mu_assert(DLL_count(dll) == 3, "Wrong count after 3rd insert");

    DLL_insert(dll, cmp, test3);
    mu_assert(DLL_first(dll) == test1, "Wrong first value after 3rd insert");
    mu_assert(DLL_last(dll) == test3, "Wrong last value after 3rd insert");
    mu_assert(DLL_count(dll) == 4, "Wrong count after 3rd insert");

    DLL_insert(dll, cmp, test3);
    mu_assert(DLL_first(dll) == test1, "Wrong first value after 3rd insert");
    mu_assert(DLL_last(dll) == test3, "Wrong last value after 3rd insert");
    mu_assert(DLL_count(dll) == 5, "Wrong count after 3rd insert");

    return NULL;
}



char* all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_pushfront_popfront);
    mu_run_test(test_pushback_popback);
    mu_run_test(test_remove);
    mu_run_test(test_delete);
    mu_run_test(test_insert);
    mu_run_test(test_destroy);
    mu_run_test(test_clear_destroy);
    return NULL;
}

RUN_TESTS(all_tests);
