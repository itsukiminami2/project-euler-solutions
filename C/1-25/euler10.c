#include <stdio.h>
#include <stdbool.h>

int main() {
    int limit = 2000000;
    int n = 2;
    unsigned long long sum = 0;

    while (n < limit) {
        bool prime = true;
        for (int i = 2; i*i <= n; ++i) {
            if(n % i == 0) {
                prime = false;
                break;
            }
        }
        if(prime) {
            sum += n;
        }

        ++n;
    }
    
    printf("%llu\n", sum);

    return 0;
}