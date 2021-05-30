#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "treap.h"

int main()
{
    
    init_nodes();

    int len = 4;
    int p[] = {1,2,4,-1};

    tnode* t = build_treap(p, len);

    clear_nodes();

    return 0;
}