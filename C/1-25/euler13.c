#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp = fopen("euler13_data.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return EXIT_FAILURE;
    }

    int result[60];  // stores the sum
    memset(result, 0, sizeof(result));

    char numbers[100][51];

    for(int i = 0; i < 100; ++i) {
        fgets(numbers[i], 52, fp);  // read 51 chars, 50 digits + '\n'

        // replace all '\n' at the ends with '\0'
        char* pos;
        if((pos = strchr(numbers[i], '\n')) != NULL) {
            *pos = '\0';
        }

        // reverse all of the numbers
        int len = strlen(numbers[i]);
        for (int j = 0, k = len-1; j < k; ++j, --k) {
            char temp = numbers[i][j];
            numbers[i][j] = numbers[i][k];
            numbers[i][k] = temp;
        }
    }

    for(int digit = 0; digit < 50; ++digit) {
        // add all the digits
        for(int i = 0; i < 100; ++i) {
            result[digit] += (numbers[i][digit] - '0');
            if(result[digit] >= 10) {
                result[digit+1]++;
                result[digit] -= 10;
            }
        }
    }

    // reverse the result
    int len = sizeof(result)/sizeof(result[0]);
    for (int j = 0, k = len-1; j < k; ++j, --k) {
        int temp = result[j];
        result[j] = result[k];
        result[k] = temp;
    }

    // skip all leading zeroes.
    int i = 0;
    while(result[i] == 0) {
        i++;
    }

    int l = i + 9; // print the next 9 numbers, the first one contains 2 digits.
    for(; i < l; ++i) {
        printf("%d", result[i]);
    }
    printf("\n");

    fclose(fp);

    return EXIT_SUCCESS;
}