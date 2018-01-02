#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    long long unsigned sum, sum_of_squares;
    sum_of_squares = (N*(N+1)*(2*N+1))/6;
    sum = (N*(N+1))/2;
    printf("Elso %d szam osszege: %d\n",N,sum);
    printf("Elso %d negyzetszam osszege: %d\n",N,sum_of_squares);
    long long int diff = sum*sum - sum_of_squares;

    printf("\nAz elso %d szam osszegenek negyzete - Az elso %d negyzetszam osszege = %d\n",N,N,diff);

    return 0;
}
