/**
 * @file treap.h
 * @author Shao-Ting Chiu
 * @brief Implicit Treap Implementation
 * @version 0.1
 * @date 2021-05-30
 * @note This code inspired by https://github.com/radoslav11/Implicit-treap/blob/master/implicit_treap.cpp
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TREAP_H
#define TREAP_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define MAX_NODE 1600000
#define LEFT 0
#define RIGHT 1


/**
 * @brief 
 * @param key implicit key
 * @param priority
 * @param rev revert flat
 * @param size nodes below and including it
 * @param parent 
 * @param leaf 0: left; 1: right; 2 Parent
 */
typedef struct node {
    int priority;
    int key; 
    int rev; 
    int size;
    struct node *parent;
    struct node *leaf[2];
} tnode;



/***Problem Setup***/
void interface(void);
tnode* build_treap(int* p, int len);

/****Main Operation****/
void Insert(tnode* t, int p, int k);
void Delete(tnode*t, int k);
void Increase(tnode*t, int l, int r, int p);
void QueryLargest(tnode*t, int l , int r);
void Reverse(tnode*t, int l, int r);
void Remove(tnode*t);

/**Helper function**/
tnode* setNewNode(int p, int k);
void _Insert(tnode*t, tnode* newt);


// Memory Management
void init_nodes();
void clear_nodes();


/****Treap Operation****/

/** Update the revert flag*/
void push(tnode* t);

// Split and Merge
void split(tnode* t, tnode* lt, tnode* rt, int key, int add);

/**
 * @brief Merge two treaps. Assume all kets in rt > lt
 * @param t new root
 * @param lt treap with smaller keys
 * @param rt treap with larger keys
 */
void merge(tnode* t, tnode* lt, tnode* rt);


//node info
int size(tnode* t);

//update
void updateRoot(tnode* t);
/** Link parent of t's leaves to t.*/
void UpdateLeafParent(tnode* t);
/** Update number of nodes below t (including t)*/
void UpdateSize(tnode* t);
void Operate(tnode* t);

//utils
void swapTnode(tnode* a, tnode* b);

#endif