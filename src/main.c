#include <stdio.h>
#include <stdlib.h>
#include "treap.h"
#include <time.h>
#include <assert.h>


static int* gen_vec_rand(int len){
    srand(time(NULL));   
    int r = rand() % 100;    
    int* ps = (int*)malloc(len*sizeof(int));

    for(int i=0;i<len;i++){
        r = rand() % 100;
        ps[i] = r;
    }

    return ps;
}

static int max_vec(int* ps, int a, int b){
    int MAX= ps[0];
    for(int i=a;i<=b;i++){
        if(MAX<ps[i]){
            MAX = ps[i];
        }
    }
    return MAX;
}

static int print_vec(int* ps, int len){
    for(int i=0; i<len;i++){
        printf("%d", ps[i]);
        if(i!=len-1){
            printf(",");
        }
    }
}


int main()
{   
    init_nodes();
    //Build tree
    int ps[] = {18300, 29753, 2980, 22690, -7762, -4779, -25393, 29411, -1922, -29893, -25148, -15353, -5610, -3094, -10506};
    //int len = 10;
    //int* ps = gen_vec_rand(len);
    int len = sizeof(ps)/sizeof(ps[0]);
    int MAX;
    int real;
    //Build tree by adding one by one
    tnode* t = NULL;

    for(int k=0;k<len;k++){
        Insert(&t, ps[k], k);
        MAX = QueryLargest(t, 0, k);
        real = max_vec(ps, 0, k);
        if(MAX != real)
            printf("r");
        //TEST_MSG("Got: %d ; Real: %d at i=%d", MAX, real,k);
    }

    print_vec(ps, len);

    clear_nodes();
    return 0;
    //return interface();
}