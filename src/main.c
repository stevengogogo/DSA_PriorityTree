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

    //Build tree
    int len = 10;
    int p[] = {7,2,1,2,4,-12,2,2,2,2};
    tnode* t = build_treap(p, len);

    Delete(&t, 0);

    //Test largest
    int MAX = QueryLargest(t, 0, len-1);
   
    //Delete All
    for(int i=1;i<len;i++){
        Delete(&t, 0);
    }



    clear_nodes();

    return 0;
}