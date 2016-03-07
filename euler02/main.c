#include <stdio.h>
#define N 4000000

int main()
{
    int prev=1, prev_prev=1, curr=2, sum=0;
    while(curr<N)
    {
        if (!(curr&1))
            sum+=curr;
        prev_prev=prev;
        prev=curr;
        curr = prev+prev_prev;
    }
    printf("A paros %d alatti Fibonacci-szamok osszege: %d",N,sum);
    return 0;
}
