#include <stdio.h>
#include <math.h>

int digits(unsigned n) {
    int l_n = (n * log10((1 + sqrt(5)) / 2)) - (log10(5) / 2); // l_n -> log10(n)

    return floor(l_n) + 1;  // number of digits in n = floor(log10(n)) + 1
}

int main() {
    unsigned n = 1;
    
    while(1) {
        if(digits(n) == 1000) {
            break;
        }
        ++n;
    }

    printf("%u\n", n);
    
    return 0;
}
