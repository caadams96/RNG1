//
// Created by corey on 2/3/2023.
//
#include "Headers/gb_flip.h"
#include <time.h>
/*macros*/
#define mod_diff(x,y) (((x) -(y)) & 0x7fffffff)/*difference modulo 2^31*/
#define two_to_the_31 ((unsigned long) 0x80000000)//
/*prototypes*/
long gb_next_rand();
long gb_flip_cycle(); /*compute 55 more pseudo-random numbers*/
void gb_init_rand(long seed);
long gb_unif_rand(long m);
/*variables*/
static long A[56]= {-1}; /*pseudo-random values*/
long *gb_fptr = A; /*the next A value to be exported*/
time_t seconds;
/*functions*/
long gb_next_rand() { return *gb_fptr>=0 ? /*if*/
                             *gb_fptr--  :  /*do*/
                             gb_flip_cycle(); /*else*/
}
long gb_flip_cycle(){
    register long *ii, *jj;
    for(ii= &A[1], jj= &A[32]; jj<=&A[55]; ii++, jj++){
        *ii= mod_diff(*ii, *jj);
    }
    for(jj= &A[1]; ii<=&A[55]; ii++, jj++){
        *ii= mod_diff(*ii,*jj);
    }
    gb_fptr = &A[54];
    return A[55];
}
void gb_init_rand(long seed){
    register long i;
    register long prev = seed, next= 1;
    seed= prev= mod_diff(prev,0); /* strip off the sign*/
    A[55]= prev;
    for(i = 21; i; i= (i+21) % 55){
        A[i]= next;
        next= mod_diff(prev,next);
        if(seed & 1){
            seed = 0x40000000 + (seed>>1);
        }else { seed>>= 1;} /*cyclic shift right 1*/
        next= mod_diff(next,seed);
        prev= A[i];
    }
    /*warm up generator*/
    gb_flip_cycle();
    gb_flip_cycle();
    gb_flip_cycle();
    gb_flip_cycle();
    gb_flip_cycle();
}

long gb_unif_rand(long m){
    register unsigned long t= two_to_the_31-(two_to_the_31%m);
    register long r;
    do{
        r = gb_next_rand();
    }while(t <= (unsigned long)r);
    return r%m;
}
/*Added Function*/
long generate_random(int seed,int ceiling){
    int i,r = 0,t = 0;
    gb_init_rand((long)time(&seconds)-seed);
    r = gb_unif_rand(ceiling);
    return r;
}