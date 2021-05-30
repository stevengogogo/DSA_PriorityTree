#include "treap.h"

// Memory Management
tnode* init_nodes(){
    Nnode = 0;
    return (tnode*)malloc(MAX_NODE * sizeof(tnode));
}

void clear_nodes(tnode* nArr){
    Nnode = 0;
    free(nArr);
}

/****Treap Operation****/

void push(tnode*t){
    if (t==NULL)
        return ;
    
    if(t->rev)
        swapTnode(t->leaf[LEFT], t->leaf[RIGHT]);
    
    if(t->leaf[LEFT])
        t->leaf[LEFT]->rev ^= t->rev;
    if(t->leaf[RIGHT])
        t->leaf[RIGHT]->rev ^= t->rev;

    t->rev = 0;
}

// Split and Merge
void split(tnode* t, tnode* lt, tnode* rt, int key, int add){
    if (t == NULL){
        lt=rt=NULL;
        return;
    }

    int ik = add + size(t->leaf[LEFT]); //implicit key

    if(ik <= key){ //key is on the right
        split(t->leaf[RIGHT], t->leaf[RIGHT], rt, key, ik+1);
        lt = t;
    }
    else{
        split(t->leaf[LEFT], lt, t->leaf[LEFT] ,key, add);
        rt = t;
    }

    //Update
    UpdateLeafParent(t); 
    UpdateSize(t);
    Operate(t);
}

//node info
int size(tnode* t){
    if(t!=NULL)
        return t->size;
    else 
        return 0;
}

//update
void UpdateLeafParent(tnode* t){
    if (t==NULL)
        return ;

    for(int i=0;i<2;i++){
        if (t->leaf[i])
            t->leaf[i]->parent = t;
    }
}

void UpdateSize(tnode* t){
    if (t!=NULL)
        t->size = size(t->leaf[LEFT]) + size(t->leaf[RIGHT]) + 1;
}

void Operate(tnode* t){
    if(!t)
        return;
    push(t->leaf[LEFT]);
    push(t->leaf[RIGHT]);
}

//utils
void swapTnode(tnode* a, tnode* b){
    tnode* temp = a;
    a = b;
    b = a;
}