#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_treap.h"

// Run TESTs 
TEST_LIST = {
    {"Utility", test_utils},
    {"Treap: Insertion and build", test_build},
    {"Treap: Insertion at start", test_insert_at_start},
    {"Treap: Deletion", test_delete},
    {"Treap: Increase", test_increase},
    {"Treap: Reverse", test_reverse},
    {"Treap: Find largest position (with minimum key)", test_find_largest},
    {"Treap: Remove Largest", test_remove_largest},
    {"Treap: Maximum Consistency", test_maximum},
    {NULL, NULL} // Terminate the test
};