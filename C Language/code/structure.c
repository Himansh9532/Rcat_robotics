// #calloc
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    // allocate memory for 5 integers and initialize them to 0
    ptr = (int *)calloc(5, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error code
    }
    // use the allocated memory
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    // don't forget to free the allocated memory
    free(ptr);
    return 0;
}