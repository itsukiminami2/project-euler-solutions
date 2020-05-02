#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 2000000

int main() {
    char* sieve = malloc(LIMIT * (sizeof *sieve));
    memset(sieve, 1, LIMIT * (sizeof *sieve));

    unsigned long long sum = 0;

    sieve[0] = sieve[1] = 0;
    for (int i = 2; i*i < LIMIT; ++i) {
        if(sieve[i] == 1) {
            for (int j = i*i; j < LIMIT; j += i) {
                sieve[j] = 0;
            }
        }
    }

    for(int i = 2; i < LIMIT; ++i) {
        if(sieve[i]) {
            sum += i;
        }
    }

    free(sieve);

    printf("%llu\n", sum);

    return 0;
}