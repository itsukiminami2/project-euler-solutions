#include <stdio.h>

unsigned proper_sum(unsigned n) {
    unsigned sum = 0;
    for(unsigned i = 1; i*i <= n; ++i) {
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
    unsigned sum = 0;
    for(unsigned i = 2; i < 10000; ++i) {
        unsigned s = proper_sum(i);
        if(proper_sum(s) == i && i < s) {
            sum += (i + s);
        }
    }

    printf("%u", sum);

    return 0;
}