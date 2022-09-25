#include <stdio.h>
#include <stdlib.h>

int main(){
    printf(" ------- Variable ------- \n");
    int *p =  (int *)malloc(sizeof(int));
    if (p == NULL)    // memory allocation failure
        exit(-2);
    *p = 1;
    printf("%d\n", *p);     // Output: 1
    free(p);

    printf("\n ------- 1D Array ------- \n");
    int arrLen = 10;
    int *dynArr = (int*)malloc(arrLen * sizeof(int));
    if(dynArr == NULL) {    // memory allocation failure
        exit(-2);
    }

    for (int i = 0; i < arrLen; ++i) {    // access
        dynArr[i] = i;
        printf("%d ", dynArr[i]);       // Output: 0 ~ 9
    }
    printf("\n");

    free(dynArr);

    printf("\n ------- 2D Array ------- \n");
    int row = 5, col = 10;
    int **dynArr2 = (int**)malloc(row * sizeof(int*));      // Allocate row first
    if(dynArr2 == NULL)    // memory allocation failure
        exit(-2);

    for(int i = 0; i < row; ++i){                           // Allocate col
        dynArr2[i] = (int*)malloc(col * sizeof(int));
        if(dynArr2[i] == NULL)        // memory allocation failure
            exit(-2);
    }


    for(int i = 0; i < row; ++i) {   // access
        for(int j = 0; j < col; ++j) {
        int index = i * col + j;
        dynArr2[i][j] = index;
        printf("%d ", dynArr2[i][j]);       // Output: 0 ~ 49
      }
      printf("\n");
    }

    for(int i = 0; i < row; ++i){                           // Deallocate col first
        free(dynArr2[i]);
    }

    free(dynArr2);                                         // Deallocate row
    return 0;
}
