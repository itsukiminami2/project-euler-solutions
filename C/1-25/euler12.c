#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int divisors(long n) {
    int cnt = 0; 
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            // If divisors are equal, 
            // count only one 
            if (n / i == i) {
                cnt++;
            }
            else { // Otherwise count both 
                cnt = cnt + 2;
            }    
        } 
    } 
    return cnt;
}

int main() {
    int n = 1;
    while (true) {
        long triangle_num = (n * (n + 1)) / 2;

        int f = divisors(triangle_num);
        if(f > 500) {
            printf("%ld\n", triangle_num);
            break;
        }

        ++n;
    }
    
    return 0;
}