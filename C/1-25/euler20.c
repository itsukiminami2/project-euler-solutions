#include <stdio.h>
#include <math.h>

int main() {
    double total = 0;
    int n = 100;
    for(int i = 1; i <= n; ++i) {
        total += log10(i);
    }
    int count = floor(total) + 1;  // total number of digits in n!

    int* factorial; // store all the individual digits of the factorial

    return 0;
}