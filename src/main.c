#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "treap.h"
#include <assert.h>

void tree_validate(tnode* t, int* c){
    if (t==NULL)
        return;
    *c = *c + 1;
    for(int i=0;i<2;i++){
        if(t->leaf[i] != NULL){
            //Priority
            assert(t->pt >= t->leaf[i]->pt);

        }
    }

     //Key
    if (t->leaf[LEFT] != NULL)
    assert(t->key > t->leaf[0]->key);

    if(t->leaf[RIGHT] != NULL)
    assert(t->key < t->leaf[1]->key);

    tree_validate(t->leaf[0], c);
    tree_validate(t->leaf[1], c);
}

int main()
{
    
    init_nodes();

    int len = 4;
    int p[] = {1,2,4,-12,2,2,2,2};
    int c=0;
    tnode* t = build_treap(p, len);
    tree_validate(t, &c);
    clear_nodes();

    return 0;
}