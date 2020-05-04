/*
    euler46.c - solution to project euler problem 46.
    Find the smallest odd composite no. not of the form n = p + 2k,
    where p is prime and k is a perfect square.
    * Runs in 0.0090secs.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIMIT 10000

void generate_sieve(char*);
int check(int);

char sieve[LIMIT];

int main()
{
    memset(sieve, 1, LIMIT * sizeof(char));
    generate_sieve(sieve);

    for(int i = 3; ; i += 2) {
        if(!sieve[i]) {
            if(check(i)) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}

void generate_sieve(char* a)
{
    a[0] = a[1] = 0;
    for (int i = 2; i*i <= LIMIT; ++i) {
        if(a[i] == 1) {
            for (int j = i*i; j <= LIMIT; j += i) {
                a[j] = 0;
            }
        }
    }
}

// return 0 if the n is the sum of a prime and twice a square, 1 otherwise
int check(int n)
{
    for(int p = n-1; p > 1; --p) { // find the largest prime < i
        if(sieve[p]) {
            int k = (n - p) / 2;
            // check if 'k' is a perfect square
            double sqrt_k = sqrt(k);
            if(sqrt_k - round(sqrt_k) == 0) {
                return 0;
            }
        }
    }

    return 1;
}