//
// Created by corey on 2/4/2023.
//
#include <stdio.h>
#include "Headers/gb_flip.h"
int test(){
    long j;
    gb_init_rand(-314159L);
    if(gb_next_rand()!=119318998){
        printf("Failure on the first try!\n");return-1;
    }
    for(j= 1;j<=133;++j){
        gb_next_rand();
    }
    if(gb_unif_rand(0x55555555L)!=748103812){
        printf("Failure on the second try!\n");return-2;
    }
    printf("OK, the gb_flip routines seem to work!\n");
    return 0;
}