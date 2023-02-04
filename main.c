#include <stdio.h>
#include <unistd.h>
#include "Headers/gb_flip.h"
int rr(int n,int c);
int main() {
long r = 0,r2= 0, r3 = 0,r4 = 0;
int c = 100;
    printf("Random Number list\n");
    for(int i = 0; i <=10; ++i){
        r = generate_random(8679,c);
        r2 = generate_random(-21243,c);
        r3 = generate_random(43709,c);
        printf("%ld\t%ld\t%ld\n",r,r2,r3);
        sleep(1);
    }
    printf("Single Random Number\n");
    r4 = generate_random(-323434,10);
    printf("%ld", r4);
    return 0;
}



