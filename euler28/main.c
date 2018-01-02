#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int ** make_zero_table(int rows, int cols);
void fill_spiral(int ** table, int N);
void print_table(int ** table, int rows, int cols);
int sum_diagonals(int ** table, int N);
void free_table(int ** table, int rows, int cols);

int main(int argc, char ** argv)
{
    int ** table = make_zero_table(SIZE, SIZE);
    fill_spiral(table, SIZE);
    print_table(table, SIZE, SIZE);
    printf("Az atlok osszege: %d\n", sum_diagonals(table, SIZE));
    free_table(table, SIZE, SIZE);
    return 0;
}

void fill_spiral(int ** table, int N)
{
   table[N/2][N/2] = 1; //kozepe 1-es
   int x=N/2, y=N/2, side_length, k, value=2;
   //sprial rajzolas: a negyzet oldalai egyre hosszabbak (side_length)
   for (side_length=1; side_length<N-1; side_length+=2)
   {
        for (k=0; k<side_length; ++k) //jobbra
        {
            table[y][++x] = value;
            ++value;
        }
        for (k=0; k<side_length; ++k) //lefele
        {
            table[++y][x] = value;
            ++value;
        }
        for (k=0; k<side_length+1; ++k) //balra
        {
            table[y][--x] = value;
            ++value;
        }
        for (k=0; k<side_length+1; ++k) //felfele
        {
            table[--y][x] = value;
            ++value;
        }
   }
   //spiral utolso egyenes szakasza (N-1 hosszu)
   for (k=0; k<N-1; ++k)
   {
       table[y][++x] = value;
       ++value;
   }
}

int sum_diagonals(int ** table, int N)
{
    int k, sum=-1; //mivel a metszespontbeli 1-et ketszer szamolja
    for (k=0; k<N; ++k)
    {
        sum+=table[k][k]; //foatlo
        sum+=table[k][N-1-k]; //mellekatlo
    }
    return sum;
}

void print_table(int ** table, int rows, int cols)
{
    int i,j;
    for (i=0; i<rows; ++i)
    {
        for (j=0; j<cols; ++j)
        {
            printf("%3d ", table[i][j]);
        }
        printf("\n");
    }
}

int ** make_zero_table(int rows, int cols)
{
    int ** table = (int **) calloc(rows, sizeof(int));
    int i;
    for (i=0; i<rows; ++i)
    {
        table[i] = (int *)calloc(cols, sizeof(int));
    }
    return table;
}

void free_table(int ** table, int rows, int cols)
{
    int i;
    for (i=0; i<rows; ++i)
    {
        free(table[i]);
    }
    free(table);
}
