#include <stdio.h>

int main() {
    int n = 1;
    int max_c = 0, max_n = 0;
    while(n < 1000000) {
        unsigned long long curr = n;

        int c = 1;
        while(curr != 1) {
            if(curr % 2 != 0) {
                curr = (3*curr + 1);
                c++;
            }
            else {
                curr = curr / 2;
                c++;
            }
        }

        if(c > max_c) {
            max_c = c;
            max_n = n;
        }
        
        ++n;
    }

    printf("%d\n", max_n);
    
    return 0;
}