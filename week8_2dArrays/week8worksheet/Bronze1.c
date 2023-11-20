// Bronze Level --------------------------------------------------------

// 1. Transpose of a Matrix:
// Write a program that initializes a [2][3] 2-d array. Call a function to transpose the matrix (2-d array). Finally, print
// the arrays both before and after the conversion.


// 1 2 3
// 4 5 6
// \---->
// 1 4
// 2 5
// 3 6
#include <stdio.h>

void printArray(int a[][3] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

void printArray2(int a[][3] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[j][i]);
     }
     printf("\n"); // start new line of output 
     }
}
//void transposeArray()



int main() {
  int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  printf("Values in array1 by row are:\n");
  printArray(array1);  
  printf("\n weird Values in array1 by row are:\n");
  printArray2(array1);

  return 0;
}
