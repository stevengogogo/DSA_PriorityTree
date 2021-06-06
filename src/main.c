#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "treap.h"
#include <assert.h>


int main()
{
    init_nodes();

    //Build tree
    int len = 10;
    int p[] = {7,2,1,2,4,-12,2,2,2,2};
    tnode* t = build_treap(p, len);

    /*DELETION*/

    //Original
    int MAX = QueryLargest(t, 0, len-1);

    //Delete first item
    Delete(&t, 1-1);
    MAX = QueryLargest(t, 0, len-2);


    //Delete fourth item
    Delete(&t, 4-1); 
    MAX = QueryLargest(t, 0, len-3);


    //Delete All
    for(int i=2;i<len;i++){
        Delete(&t, 0);
    }

    clear_nodes();

    return 0;
}