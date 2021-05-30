#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_insert.h"

// Run TESTs 
TEST_LIST = {
    {"Utility", test_utils},
    {"Build treap", test_build},
    {NULL, NULL} // Terminate the test
};