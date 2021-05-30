#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "treap.h"
#include <assert.h>

void tree_validate(tnode* t){
    if (t==NULL)
        return;

    //Priority
    for(int i=0;i<2;i++)
        assert(t->priority >= t->leaf[i]->priority);
    
    //Key
    assert(t->size > t->leaf[LEFT]->size);
    assert(t->size < t->leaf[RIGHT]->size);

    tree_validate(t->leaf[LEFT]);
    tree_validate(t->leaf[RIGHT]);
}

int main()
{
    
    init_nodes();

    int len = 4;
    int p[] = {1,2,4,-1};

    tnode* t = build_treap(p, len);
    tree_validate(t);
    clear_nodes();

    return 0;
}