#include <stdio.h>

#define TERMS ((((1001 - 3) / 2) * 4) + 4)  // formula -> ((n-3)/2*4)+4, for a (n x n) spiral.

int main() {
    unsigned sum = 1; // initial sum
    int term = 1;     // first term
    int a = 2;
    
    for(int i = 1; i <= TERMS; ++i) {
        term += a; // the next term
        sum += term; // add the next term to the current sum

        if(i % 4 == 0) {
            a += 2;
        }
    }

    printf("%u\n", sum);

    return 0;
}