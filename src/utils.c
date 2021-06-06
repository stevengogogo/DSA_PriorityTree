#include "utils.h"

//Choose the bigger one
int argmax(int a, int b){
    if (a>b)
        return 0;
    else 
        return 1;
}

int max(int a, int b){
    return a>b ? a : b;
}