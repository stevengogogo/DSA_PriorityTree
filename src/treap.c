#include "treap.h"

static int Nnode;
static tnode* tnodeArr;

// Problem Setup
void interface(void){
    init_nodes();
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

    clear_nodes();
}

tnode* build_treap(int* p, int len){
    tnode* t = NULL;

    for(int k=0;k<len;k++){
        Insert(&t, p[k], k+1);
    }
    return t;
}


/****Main Operation****/
void Insert(tnode**t, int prior, int pos){
    if(pos==-1){
        _Insert_at_start(t, prior);
    }
    else{
        _Insert(t, prior, pos);
    }
}

void Delete(tnode**t, int k){
    if(*t == NULL)
        return;
    tnode* l;
    tnode* r;
    tnode* m;

    split(*t, &l, &r, k-1, 0);
    split(r, &m, &r, 0, 0);
    merge(t, l, r);
    Operate(t);
}

int QueryLargest(tnode*t, int kL , int kR){
    tnode* l;
    tnode* r;
    tnode* m;

	split(t, &l, &r, kL - 1,0);
	split(r, &m, &r, kR - kL,0);

	int answer = m->max;

    merge(&r, m, r);
    merge(&t, l, r);

    return answer;
}


/**Helper function**/

/** Insert node with priority `prior` at position `pos`
 * @note pos>=0. This function can not insert at beginning.Use @ref _Insert_at_start instead.
*/
void _Insert(tnode**t, int prior, int pos){
    //set new node
    tnode* newt = setNewNode(prior);
    newt->key = pos;
    newt->val = prior;
    newt->max = prior;

    if(*t==NULL){
        *t = newt;
        return;
    }
    
    tnode* l = NULL;
    tnode* r = NULL;

    split(*t, &l, &r, pos, 0);
    merge(&l, l, newt);
    merge(t, l, r);
    Operate(t);
}

void _Insert_at_start(tnode**t, int prior){
    int first_prior = get_val_at_pos(*t, 0);
    _Insert(t, prior, 0);
    Delete(t, 0);
    _Insert(t, first_prior, 0);
}


tnode* setNewNode(int val){
    tnode* newt = &tnodeArr[Nnode];
    ++Nnode;
    //Assigned value
    newt->pt = rand();
    newt->key = 0;
    newt->val = val;
    newt->sum = val;
    newt->max = val;
    //Default
    newt->parent = NULL;
    newt->leaf[LEFT] = NULL;
    newt->leaf[RIGHT] = NULL;
    newt->rev = 0;
    newt->size = 1;
    return newt;
}

int get_val_at_pos(tnode* t, int pos){
    tnode* l;
    tnode* r;
    tnode* m;

    split(t, &l, &r, pos - 1, 0);
    split(r, &m, &r, 0, 0);

    int ret = (m!=NULL) ? m->val : -1; 

    merge(&r, m, r);
    merge(&t, l, r);
    return ret;
}

int find_largest_pos(tnode* t, int kL, int kR){
    tnode* l;
    tnode* r;
    tnode* m;

	split(t, &l, &r, kL - 1,0);
	split(r, &m, &r, kR - kL,0);

	int answer = m->max;

    merge(&r, m, r);
    merge(&t, l, r);

    return answer;
}

// Memory Management
void init_nodes(){

    Nnode = 0;
    tnodeArr = (tnode*)malloc(MAX_NODE * sizeof(tnode));
}

void clear_nodes(){
    Nnode = 0;
    free(tnodeArr);
}

/****Treap Operation****/

void push(tnode*t){
    if (t==NULL)
        return ;
    t->sum += t->lazy *size(t);
    t->val += t->lazy;

    //Max
    if(t->leaf[LEFT] != NULL)
        t->max = max(t->val, t->leaf[LEFT]->max);
    if(t->leaf[RIGHT] != NULL)
        t->max = max(t->val, t->leaf[RIGHT]->max);
    if(t->leaf[LEFT] == NULL && t->leaf[RIGHT] == NULL)
        t->max = t->val;
    
    //Reverse
    if(t->rev)
        swapTnode(t->leaf[LEFT], t->leaf[RIGHT]);
    
    if(t->leaf[LEFT])
        t->leaf[LEFT]->rev ^= t->rev;
    if(t->leaf[RIGHT])
        t->leaf[RIGHT]->rev ^= t->rev;

    t->lazy = 0;
    t->rev = 0;
}

void reset(tnode*t){
    if(t!=NULL){
        t->sum = t->val;
        t->max = t->val;
    }
}

void combine(tnode** t, tnode* l, tnode* r){
    if(l==NULL){
        *t  = r;
    }
    else if(r==NULL){
        *t = l;
    }
    else{
        (*t)->sum = l->sum + r->sum;
        (*t)->max = max(l->max, r->max);
    }
}



// Split and Merge
void split(tnode* t, tnode** lt, tnode** rt, int key, int add){
    if (t == NULL){
        *lt=NULL;
        *rt=NULL;
        return;
    }
    push(t);

    int ik = add + size(t->leaf[LEFT]); //implicit key

    if(key >= ik){ //key is on the right
        split(t->leaf[RIGHT], &t->leaf[RIGHT], rt, key, ik+1);
        *lt = t;
    }
    else{
        split(t->leaf[LEFT], lt, &t->leaf[LEFT] ,key, add);
        *rt = t;
    }

    updateRoot(t);
}

void merge(tnode** t, tnode* lt, tnode* rt){
    push(lt);
    push(rt);

    if(lt == NULL){
        *t = rt; return;
    }
    if(rt == NULL){
        *t = lt; return;
    }
    
    if(lt->pt > rt->pt){
        merge(&lt->leaf[RIGHT], lt->leaf[RIGHT], rt);
        *t = lt;
    }
    else{
        merge(&rt->leaf[LEFT], lt, rt->leaf[LEFT]);
        *t = rt;
    }

    updateRoot(*t);
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
    Operate(&t);
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

void Operate(tnode** t){
    if(!*t)
        return;
    push((*t)->leaf[LEFT]);
    push((*t)->leaf[RIGHT]);

    combine(t, (*t)->leaf[LEFT], *t);
	combine(t, *t, (*t)->leaf[RIGHT]);
}

//utils
void swapTnode(tnode* a, tnode* b){
    tnode* temp = a;
    a = b;
    b = a;
}