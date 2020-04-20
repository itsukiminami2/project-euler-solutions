#include <stdio.h>

int next_permutation(int array[], int length) {
    int x = length - 2;
    while((x >= 0) && (array[x] > array[x+1])) {
        x--;
    }
    
    // no such 'x' found
    if(x < 0) {
        return 0;
    }
    //else
    int y = length - 1;
    while((y > x) && (array[y] < array[x])) {
        y--;
    }

    //swap array[x] and array[y]
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;

    //reverse(array, x+1, length-1);
    int start = x + 1;
    int end = length - 1;
    while(start < end) {
        int t = array[start];
        array[start] = array[end];
        array[end] = t;

        start++;
        end--;
    }

    return 1;
}


int main() {
    int set[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // also the first permutation
    for(int i = 1; i < 1000000; ++i) {
        next_permutation(set, 10);
    }

    for(int i = 0; i < 10; ++i) {
        printf("%d", set[i]);
    }

    return 0;
}