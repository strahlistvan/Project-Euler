#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000

int main()
{
    int a,b,c,p;
    int count=0, maxCount=0, maxCountPerim=0;
    for (p=12; p<LIMIT; ++p)
    {
        count = 0;
        for (a=3; a<p; ++a)
        {
            //eleg lenne megnezni, b hogy egesz szam-e
            b = (p*p - 2*p*a)/(2*p - 2*a);
            c = p-a-b;

            if (a*a + b*b == c*c)
                ++count;
        }
      if (count > maxCount )
      {
          maxCount = count;
          maxCountPerim = p;
      }
    }
    printf("%d", maxCountPerim);
    return 0;
}
