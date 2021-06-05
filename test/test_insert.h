#ifndef TEST_INSERT_H
#define TEST_INSERT_H

#include "treap.h"
#include "acutest.h"

void tree_validate(tnode* t){
    if (t==NULL)
        return;

    for(int i=0;i<2;i++){
        if(t->leaf[i] != NULL){
            //Priority
            TEST_CHECK(t->pt >= t->leaf[i]->pt);

        }
    }

     //Key
    if (t->leaf[LEFT] != NULL)
    TEST_CHECK(t->size > t->leaf[LEFT]->size);

    if(t->leaf[RIGHT] != NULL)
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
