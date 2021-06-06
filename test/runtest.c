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
    {NULL, NULL} // Terminate the test
};