#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long unsigned number = 0;
    char done=0;
    int i, N=20;

    while (!done)
    {
        ++number;
      //  printf("%d ",number);
        for (i=1; i<N; ++i)
        {
            if (number%i!=0)
                break;
        }
        if (i==N)
            done=1;
    }
    printf("\n%d A legkisebb szam, amely 1-tol %d -ig minden egesszel oszthato\n",number,N);
    return 0;
}
