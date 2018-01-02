#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ** make_zero_table(int rows, int cols);
void fill_spiral(int ** table, int N);
void print_table(int ** table, int rows, int cols);
void free_table(int ** table, int rows, int cols);
char is_prime(int number);

int main(int argc, char ** argv)
{
    int SIZE = 7;
    double rate = 1;

    while (rate > 0.1)
    {
        int ** table = make_zero_table(SIZE, SIZE);
        fill_spiral(table, SIZE);
        //print_table(table, SIZE, SIZE);
        int diagPrimeCount = 0, k;
        for (k=0; k<SIZE; ++k)
        {
            if (is_prime(table[k][k]))
                ++diagPrimeCount;
            if (is_prime(table[k][SIZE-1-k]))
                ++diagPrimeCount;
        }
        free_table(table, SIZE, SIZE);
        rate = (double) diagPrimeCount / (2*SIZE-1);
       // printf("jelenlegi arany: %f - Meret: %d\n\n", rate, SIZE);
        SIZE+=2;
    }

    printf("%d", SIZE);
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
        for (k=0; k<side_length; ++k) //felfele
        {
            table[--y][x] = value;
            ++value;
        }
        for (k=0; k<side_length+1; ++k) //balra
        {
            table[y][--x] = value;
            ++value;
        }
        for (k=0; k<side_length+1; ++k) //lefele
        {
            table[++y][x] = value;
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

char is_prime(int number)
{
    if (number==2)
        return 1;
    if (number<2 || number%2==0)
        return 0;

    int i;
    for (i=3; i<=sqrt(number); i+=2)
    {
        if (number%i==0)
            return 0;
    }
    return 1;
}
