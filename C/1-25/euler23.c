#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int proper_sum(int n) {
    int sum = 0;
    for(int i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            if(n/i == i) {
                sum += i;
            }
            else {
                sum += (i + n/i);
            }
        }
    }

    return sum - n;
}

int main() {
    int upper_limit = 28123;
    int abundant_numbers[7000];
    int count = 0; // total count of all abundant numbers < upper_limit.
    int sum = 0; // sum of all the positive integers which cannot be written as the sum of two abundant numbers.
    int* sum_pairs = calloc(upper_limit, sizeof *sum_pairs);

    for(int i = 12; i < upper_limit; ++i) {
        if(proper_sum(i) > i) {
            abundant_numbers[count++] = i;
        }
    }

    for(int i = 0; i < count; ++i) {
        for(int j = i; j < count; ++j) {
            int sum = abundant_numbers[i] + abundant_numbers[j];
            if(sum >= upper_limit) {
                break;
            }

            sum_pairs[sum-1] = 1;
        }
    }

    for(int i = 12; i < upper_limit; ++i) {
        if(!sum_pairs[i]) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}