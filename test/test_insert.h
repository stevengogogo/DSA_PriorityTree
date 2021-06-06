#ifndef TEST_INSERT_H
#define TEST_INSERT_H

#include "treap.h"
#include "acutest.h"

void tree_validate(tnode* t, int* c){
    if (t==NULL)
        return;
    *c = *c + 1;
    for(int i=0;i<2;i++){
        if(t->leaf[i] != NULL){
            //Priority
            TEST_CHECK(t->pt >= t->leaf[i]->pt);
        }
    }

     //Key
    if (t->leaf[LEFT] != NULL){
        TEST_CHECK(t->pt >= t->leaf[LEFT]->pt);
        TEST_CHECK(t->key >= t->leaf[LEFT]->key);
        TEST_MSG("Root: %d;Left: %d", t->key, t->leaf[LEFT]->key);
    }

    if(t->leaf[RIGHT] != NULL){
        TEST_CHECK(t->pt >= t->leaf[RIGHT]->pt);
        TEST_CHECK(t->key <= t->leaf[RIGHT]->key);
        TEST_MSG("Root: %d;RIGHT: %d", t->key, t->leaf[RIGHT]->key);
    }

    tree_validate(t->leaf[0], c);
    tree_validate(t->leaf[1], c);
}

void print_tree(tnode* t){
    if (t==NULL){
        return;
    }
    print_tree(t->leaf[0]);
    printf("%d ",t->key);
    print_tree(t->leaf[1]);
}


void test_build(void){
    init_nodes();

    int len = 10;
    int p[] = {7,2,1,2,4,-12,2,2,2,2};
    int p2[] = {7,2,1,2,4,-12,2,2,2,2};
    int c =0;
    int EST;

    tnode* t = build_treap(p, len);
    TEST_CHECK(t!=NULL);
    //TEST_CHECK(t->leaf[RIGHT]!=NULL);
    //tree_validate(t, &c);
    //TEST_CHECK(c==4);
    //TEST_MSG("length: %d / REAL: %d", c, len);

    for(int i=0;i<len;i++){
        EST = get_val_at_pos(t, i);
        TEST_CHECK(EST == p2[i]);
        TEST_MSG("Real: %d / EST: %d", p2[i], EST);
    }
    print_tree(t);
    clear_nodes();
}



#endif
