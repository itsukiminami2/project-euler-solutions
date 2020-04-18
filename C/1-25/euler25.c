#include <stdio.h>
#include <math.h>

int digits(unsigned n) {
    int l_n = (n * log10((1 + sqrt(5)) / 2)) - (log10(5) / 2);

    return floor(l_n) + 1;
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
