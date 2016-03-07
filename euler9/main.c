#include <stdio.h>
#include <stdlib.h>
#define SUM 1000

int main()
{
    int a,b,c,m,n;
    char found=0;
    for (m=SUM; m>0 &&!found; --m)
    {
        for (n=m; n>0 && !found; --n)
        {
            a=m*m-n*n;
            b=2*m*n;
            c=m*m+n*n;
            if (a*a+b*b==c*c && a+b+c==SUM)
            {
                printf("Megtalaltam a megoldast!");
                found=1;
            }
        }
    }

    printf("A megoldás: a=%d b=%d c=%d\n",a,b,c);
    if (!found)
       printf("Nincs ilyen\n");
    if (a*a+b*b==c*c)
        printf("Helyes\n");
    printf("Szorzatuk: %d\n",a*b*c);
    return 0;
}
