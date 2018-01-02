#include <stdio.h>
#include <stdlib.h>
#define PERIM 1000

int main()
{
    int a=0, b=0, c=0 ,m=PERIM ,n=PERIM ,k;
    char found=0;
    for (k=1; !found && m>0; ++k)
    {
        for (m=PERIM; m>0 &&!found; m-=2)
        {
            for (n=m-1; n>0 && !found; n-=2)
            {
                a=m*m-n*n;
                b=2*m*n;
                c=m*m+n*n;
                if (a*a+b*b==c*c && a+b+c==PERIM)
                {
                    printf("Megtalaltam a megoldast!");
                    found=1;
                }
            }
        }
    }

    if (!found)
       printf("Nincs ilyen\n");
    else
        printf("A megoldas: a=%d b=%d c=%d\n",a,b,c);
    printf("Szorzatuk: %d\n",a*b*c);
    return 0;
}
