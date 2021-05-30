#ifndef TEST_INSERT_H
#define TEST_INSERT_H

#include "treap.h"
#include "acutest.h"

void tree_validate(tnode* t){
    if (t==NULL)
        return;

    //Priority
    for(int i=0;i<2;i++)
        TEST_CHECK(t->priority >= t->leaf[i]->priority);
    
    //Key
    TEST_CHECK(t->size > t->leaf[LEFT]->size);
    TEST_CHECK(t->size < t->leaf[RIGHT]->size);

    tree_validate(t->leaf[LEFT]);
    tree_validate(t->leaf[RIGHT]);
}


void test_build(void){
    init_nodes();

    int len = 4;
    int p[] = {1,2,4,-1};

    tnode* t = build_treap(p, len);
    TEST_CHECK(t!=NULL);
    tree_validate(t);

    clear_nodes();
}



#endif
