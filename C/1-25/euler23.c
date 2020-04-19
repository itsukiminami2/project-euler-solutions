#include <stdio.h>
#include <stdlib.h>

// computes the sum of proper factors of n
int proper_sum(int n) {
    int sum = 0;
    for(int i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            if(n/i == i) {
                sum += i;
            }
            else {
                sum += (i + n/i);
            }
        }
    }

    return sum - n;
}

int main() {
    const int limit = 28123;
    int* abundants = calloc(limit, sizeof(int));
    int sum = 0;

    for(int i = 1; i <= limit; ++i) {
        if(proper_sum(i) > i) {
            abundants[i] = 1;
        }
    }

    for(int i = 1; i <= limit; i++) {
        int is_sum = 0;
        for(int j = 0; j <= i; ++j) {
            if(abundants[j] && abundants[i-j]) {
                is_sum = 1;
            }
        }
        if(is_sum == 0) {
            sum += i;
        }
    }
    
    printf("%d\n", sum);

    return 0;
}
