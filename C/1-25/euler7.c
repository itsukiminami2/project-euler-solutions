#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long ull;

bool is_prime(ull n) {
    if(n <= 1) {
        return true;
    }

    for (long i = 2; i*i <= n; ++i) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ull n = 2;
    int count = 1;

    while (true) {
        n++;
        if(is_prime(n)) {
            ++count;
        }

        if(count == 10001) {
            break;
        }
    }

    printf("%llu\n", n);
    
}