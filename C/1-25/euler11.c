#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp = fopen("euler11_data.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return EXIT_FAILURE;
    }

    int** ar;
    ar = malloc(sizeof(int*) * 20);
    for (int i = 0; i < 20; ++i) {
        ar[i] = malloc(sizeof(int) * 20);
    }

    int n;
    while (!feof(fp)) {
        for(int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; j++) {
                fscanf(fp, "%d", &n);
                ar[i][j] = n;
            }
            
        }
    }

    int max_p = 0;  // largest product of 4 numbers across the matrix

    for(int i = 0; i <= 16; ++i) {
        for(int j = 0; j <= 16; ++j) {
            int p;

            // scan horizontally
            p = ar[i][j] * ar[i][j+1] * ar[i][j+2] * ar[i][j+3];
            if(p > max_p) {
                max_p = p;
            }

            // scan vertically
            p = ar[i][j] * ar[i+1][j] * ar[i+2][j] * ar[i+3][j];
            if(p > max_p) {
                max_p = p;
            }
            
            // scan diagonally in the right-down direction
            p = ar[i][j] * ar[i+1][j+1] * ar[i+2][j+2] * ar[i+3][j+3];
            if(p > max_p) {
                max_p = p;
            }

            if(j-3 >= 0) {  // prevent array out-of-bounds situation
                // scan diagonally in the left-down direction
                p = ar[i][j] * ar[i+1][j-1] * ar[i+2][j-2] * ar[i+3][j-3];
                if(p > max_p) {
                    max_p = p;
                }
            }
        }
    }

    printf("%d\n", max_p);
    
    free(ar);
    fclose(fp);

    return EXIT_SUCCESS;
}