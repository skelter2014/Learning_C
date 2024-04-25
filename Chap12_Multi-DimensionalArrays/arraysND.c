#include <stdio.h>


//#define size1D 5
//#define size2D 4
//#define size3D 3;

const int size1D = 5;
const int size2D = 4;
const int size3D = 3;

void initialize2DArray(int row, int col, int array[size2D][size1D]);
void print2DArray(int row, int col, int array[size2D][size1D]);
int sum2DArray(int row, int col, int array[size2D][size1D]);

//Each row of the table starts the numbering at 10 * the row number (ex 10, 20, 30)
//each column is incremented by 1
void initialize2DArray(int row, int col, int array[size2D][size1D])
{
  for (int j = 0; j < row; j++) {
    for (int i = 0; i < col; i++) {
      array[j][i] = (10 * (j + 1)) + (i + 1);
    }
  }
}

//Each row of the table starts the numbering at 10 * the row number (ex 10, 20, 30)
//each column is incremented by 1
int sum2DArray(int row, int col, int array[size2D][size1D])
{
  int sum = 0;
  for (int j = 0; j < row; j++) {
    for (int i = 0; i < col; i++) {
      sum += array[j][i];
    }
  }
  return sum;
}


//outside loop walks over each row (1-4)
//inside loop iterates over columns 1-5
void print2DArray(int row, int col, int array[size2D][size1D])
{
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%4d", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


/*
Create an array, print it, and sum all the values and print that sum
*/
int main(void)
{
  int array2D[size2D][size1D];

  initialize2DArray(size2D, size1D, array2D);
  print2DArray(size2D, size1D, array2D);
  printf("Sum of array values: %4d\n\n", sum2DArray(size2D, size1D, array2D));
}


