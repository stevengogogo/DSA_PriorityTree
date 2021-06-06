/**
 * @file test_treap.h
 * @brief Test Treap operation
 * @version 0.1
 * @date 2021-06-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TEST_INSERT_H
#define TEST_INSERT_H

#include "treap.h"
#include "utility.h"
#include "acutest.h"

void test_build(void){
    init_nodes();

    int len = 10;
    int p[] = {7,2,1,2,4,-12,2,2,2,2};
    int EST;

    tnode* t = build_treap(p, len);
    TEST_CHECK(t!=NULL);
    //TEST_CHECK(t->leaf[RIGHT]!=NULL);
    //tree_validate(t, &c);
    //TEST_CHECK(c==4);
    //TEST_MSG("length: %d / REAL: %d", c, len);

    for(int i=0;i<len;i++){
        EST = get_val_at_pos(t, i);
        TEST_CHECK(EST == p[i]);
        TEST_MSG("Real: %d / EST: %d", p[i], EST);
    }

    //Heap Property
    check_heap(t);
    //Print Priorities
    print_tree(t);


    //Test largest
    int MAX = QueryLargest(t, 4, len);
    TEST_CHECK(MAX == 4);


    clear_nodes();
}

void test_insert_at_start(void){
    init_nodes();

    int len = 10;
    int n=100;
    int p[] = {7,2,1,2,4,-12,2,2,2,2};
    int EST;

    tnode* t = build_treap(p, len);
    Insert(&t, n, 0);
    int MAX = QueryLargest(t, 0, len);
    TEST_CHECK(MAX == n);

    clear_nodes();
}


void test_delete(void){
    init_nodes();

    //Build tree
    int len = 10;
    int p[] = {7,2,1,2,4,-12,2,2,2,2};
    tnode* t = build_treap(p, len);

    /*DELETION*/

    //Original
    int MAX = QueryLargest(t, 0, len-1);
    TEST_CHECK(MAX == 7);
    TEST_MSG("Got: %d", MAX);

    //Delete first item
    Delete(&t, 1-1);
    MAX = QueryLargest(t, 0, len-2);
    TEST_CHECK(MAX == 4);
    TEST_MSG("Got: %d", MAX);

    //Delete fourth item
    Delete(&t, 4-1); 
    MAX = QueryLargest(t, 0, len-3);
    TEST_CHECK(MAX == 2);
    TEST_MSG("Got: %d", MAX);
    print_tree(t);

    //Delete All
    for(int i=2;i<len;i++){
        Delete(&t, 0);
    }
    TEST_CHECK(t==NULL);
    if (t!=NULL)
        TEST_MSG("Got t.val: %d", t->val);

    clear_nodes();
}


#endif
