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
#include "utils.h"

#define MAX_NODE 1600000
#define LEFT 0
#define RIGHT 1

extern int Nnode = 0;

/**
 * @brief 
 * @param key implicit key
 * @param priority
 * @param rev revert flat
 * @param size nodes below and including it
 * @param parent 
 * @param leaf 0: left; 1: right 
 */
typedef struct node {
    int key; 
    int priority;
    int rev; 
    int size;
    int parent;
    node *leaf[2];
} tnode;

// Memory Management
tnode* init_nodes();
void clear_nodes(tnode*);


/****Treap Operation****/

/** Update the revert flag*/
void push(tnode* t);

// Split and Merge
void split(tnode* t, tnode* lt, tnode* rt, int key, int add);



//node info
int size(tnode* t);

//update
/** Link parent of t's leaves to t.*/
void UpdateLeafParent(tnode* t);
/** Update number of nodes below t (including t)*/
void UnpdateSize(tnode* t);
void Operate(tnode* t);

#endif