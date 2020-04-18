#include <stdio.h>

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int n = 20;
    long ans = 1;
    
    for (long i = 1; i <= n; ++i) {
        ans = (ans * i)/gcd(ans, i);
    }

    printf("%ld\n", ans);

    return 0;
}