#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    FILE* fp = fopen("p022_names.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "%s", "Error : Could not open file.\n");
        return EXIT_FAILURE;
    }

    char** names;
    names = malloc(sizeof(*names) * 6000);  // make space for 6000 names
    
    unsigned size = 0;
    names[size] = malloc(sizeof(char) * 16);
    while(fscanf(fp, "\"%[A-Za-z]\",", names[size]) != EOF) {
        names[++size] = malloc(sizeof(char) * 16);
    }
    free(names[size]); // free the space allocated for EOF

    qsort(names, size, sizeof(*names), compare);

    int sum = 0;
    for(int i = 0; i < size; ++i) {
        int name_worth = 0;
        for(int j = 0; names[i][j] != 0; ++j) {
            name_worth += (names[i][j] - 'A') + 1;
        }
        sum += name_worth * (i+1);

        free(names[i]);
    }
    free(names);

    printf("%d\n", sum);

    fclose(fp);

    return 0;
}
