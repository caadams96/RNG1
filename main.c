#include <stdio.h>
#include <time.h>
#include "Headers/gb_flip.h"
#include "Headers/test_flip.h"
int main() {
    printf("***Random Number Generator Demo***\n");
    if(test()!=0){return 0;};
    long r = 0, r2= 0, r3 = 0, r4 = 0;
    int c = 1024;
    int size = 10;
    long arr[size];
    time_t iseed;
    gb_init_rand((long)time(&iseed));
    printf("RANDOM LOOP\n");
    for(int i = 0; i <=size-1; ++i){
        r = gb_unif_rand(c);
        r2 = gb_unif_rand(c);
        r3 = gb_unif_rand(c);
        printf("%ld\t%ld\t%ld\n",r,r2,r3);
        arr[i] = r;
    }
    printf("ARRAY\n");
    for(int i = 0; i<=size-1;++i){
        printf("%ld\n",arr[i]);
    }
}



