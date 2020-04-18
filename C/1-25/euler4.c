#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_palindrome(int number) {
    int reverse = 0;
    while (number != 0) { 
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }

    return (reverse == number);
}

int main() {
    int max_p = 0;
    for (int i = 999; i >= 100; --i) {
        for (int j = i; i >= 100; --j) {
            int product = i * j;
            if(product < max_p) {
                break;
            }

            if(is_palindrome(product) && (product > max_p)) {
                max_p = product;
            }
        }
    }

    printf("%d\n", max_p);

    return 0;
}