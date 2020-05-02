#include <stdio.h>
#include <math.h>

#define LIMIT 1000000

int sieve[LIMIT+1];

void generate_sieve(int *);
int truncatable(int);

int main()
{
    generate_sieve(sieve);

    unsigned sum = 0;
    int count = 0; // keeps track of the number of two-sided primes found

    // find 11 "two-sided primes" from 11 onwards, since we are to ignore 2, 3, 5 and 7
    // count in increments of two, since even numbers (except 2) can't be prime
    for (int i = 11; count < 11; i += 2) {
        if (sieve[i] && truncatable(i)) {
            sum += i;
            ++count;
        }
    }

    printf("%u\n", sum);

    return 0;
}

void generate_sieve(int* a)
{
    for (int i = 0; i < LIMIT; ++i) {
        a[i] = 1;
    }

    a[0] = a[1] = 0;
    for (int i = 2; i*i <= LIMIT; ++i) {
        if(a[i] == 1) {
            for (int j = i*i; j <= LIMIT; j += i) {
                a[j] = 0;
            }
        }
    }
}

int truncatable(int p)
{
    /* check if 'p' is right-truncatable */
    int tmp = p;
    while (tmp != 0) {
        if(!sieve[tmp]) {
            return 0;
        }
        tmp = tmp / 10;
    }

    /* check if 'p' is left-truncatable */
    tmp = p;
    int n = floor(log10(tmp)) + 1;
    while(tmp != 0) {
        if(!sieve[tmp]) {
            return 0;
        }
        tmp = tmp % (int)pow(10, n-1);
        n--;
    }

    return 1;
}