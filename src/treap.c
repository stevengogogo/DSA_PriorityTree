#include "treap.h"

// Problem Setup
void interface(void){
    tnodeArr = init_nodes();
    int N=0;
    int Q=0;

    //Setup N/Q
    scanf("%d%d",&N, &Q);
    
    //Set initial priorities
    int* p = (int*)malloc(N*sizeof(int)+1);
    for(int i=1;i<=N;i++)
        scanf("%d", &p[i]);

    //Inital Treap
    build_treap(p, N);

    //Operation
    for(int i=0;i<Q;i++){
        //TODO
    }

    clear_nodes(tnodeArr);
}

tnode* build_treap(int* p, int len){
    tnode* t = NULL;

    Insert(t, p[1], 1);
    for(int k=2;k<=len;k++){
        Insert(t, p[k], k);
    }
    return t;
}


/****Main Operation****/
void Insert(tnode*t, int p, int k){
    //set new node
    tnode* newt = setNewNode(p,k);
    _Insert(t, newt);
}


/**Helper function**/
tnode* setNewNode(int p, int k){
    tnode* newt = &tnodeArr[Nnode++];
    //Assigned value
    newt->priority = p;
    newt->key = k;
    //Default
    newt->parent = NULL;
    newt->leaf[LEFT] = NULL;
    newt->leaf[RIGHT] = NULL;
    newt->rev = 0;
    newt->size = 1;
    return newt;
}

void _Insert(tnode*t, tnode* newt){
    if(t==NULL)
        t = newt;
    
    tnode* l = NULL;
    tnode* r = NULL;

    split(t, l, r, newt->key-1, 0);
    merge(l, l, newt);
    merge(t, l, r);
}

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

    updateRoot(t);
}

void merge(tnode* t, tnode* lt, tnode* rt){
    push(lt);
    push(rt);

    if(lt == NULL)
        t = rt; return;
    if(rt == NULL)
        t = lt; return;
    
    if(lt->priority > rt->priority){
        merge(lt->leaf[RIGHT], lt->leaf[RIGHT], rt);
        t = lt;
    }
    else{
        merge(rt->leaf[LEFT], lt, rt->leaf[LEFT]);
        t = rt;
    }

    updateRoot(t);
}

//node info
int size(tnode* t){
    if(t!=NULL)
        return t->size;
    else 
        return 0;
}

//update
void updateRoot(tnode* t){
    UpdateLeafParent(t);
    UpdateSize(t);
    Operate(t);
}

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