#ifndef TEST_INSERT_H
#define TEST_INSERT_H

#include "treap.h"
#include "acutest.h"

void test_build(void){
    init_nodes();

    int len = 4;
    int p[] = {1,2,4,-1};

    tnode* t = build_treap(p, len);

    clear_nodes();
}



#endif
