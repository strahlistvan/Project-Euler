#include <stdio.h>
#define N 4000000

int fib(int n)
{
    if (n<2)
        return 1;
    else
        return fib(n-2)+fib(n-1);
}

int main()
{
 //  int prev=1, prev_prev=1, curr=2, sum=0;
   int n=1, sum=0;
   for (n=1; fib(n)<N; ++n)
   {
      if (fib(n)%2 == 1)
        sum+=fib(n);
   }
 /*   while(curr<N)
    {
        if (!(curr&1))
            sum+=curr;
        prev_prev=prev;
        prev=curr;
        curr = prev+prev_prev;
    }
    */
    printf("A paros %d alatti Fibonacci-szamok osszege: %d",N,sum);
    return 0;
}
