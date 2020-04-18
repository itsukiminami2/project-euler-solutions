#include <stdio.h>
#include <math.h>

int digits(unsigned long long n) {
    int l_n = (n * log10((1 + sqrt(5)) / 2)) - (log10(5) / 2);

    return floor(l_n) + 1;
}

int main() {
    unsigned long long n = 8;
    
    while(1) {
        if(digits(n) == 1000) {
            break;
        }
        ++n;
    }

    printf("%llu\n", n);
    
    return 0;
}