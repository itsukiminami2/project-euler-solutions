#include <stdio.h>

int main() {
    unsigned s1[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4}; // 0-9
    unsigned s2[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8}; // 11-19
    unsigned s3[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6}; // 20-90
    unsigned hundred = 7;
    unsigned and = 3;
    unsigned thousand = 8;

    unsigned sum = 0;
    
    // sum from 1 to 9
    for(int i = 1; i < 10; ++i) {
            sum += s1[i];
    }

    // from 10 to 19
    for(int i = 0; i < 10; ++i) {
            sum += s2[i];
    }

    // sum from 20 to 99
    for(int i = 20; i < 100; ++i) {
        sum += s3[i/10] + s1[i%10];
    }

    for (int i = 1; i < 10; ++i) {
        int j;

        sum += s1[i] + hundred;
        // from i hundred and one to i hundred and nine
        for (j = 1; j < 10; j++) {
            sum += s1[i] + hundred + and + s1[j];
        }
        
        // from i hundred and ten to i hundred and nineteen
        for (j = 0; j < 10; j++) {
            sum += s1[i] + hundred + and + s2[j];
        }
        
        // from i hundred and twenty to i hundred and ninety-nine
        for (j = 20; j < 100; j++) {
            sum += s1[i] + hundred + and + s3[j/10] + s1[j%10];
        }
    }

    // just 1000
    sum += s1[1] + thousand;

    printf("%d\n", sum);

    return 0;
}