#include <stdio.h>
#define PERIM 1000

int main()
{
    int a, b, c;
    for (a=1; a<PERIM; ++a)
    {
        for (b=a; b<PERIM; ++b)
        {
            for (c=b; c<PERIM; ++c)
            {
                if (a*a+b*b==c*c && a+b+c==PERIM)
                {
                    printf("a=%d, b=%d, c=%d\n", a, b, c);
                    printf("A szorzatuk: %d\n", a*b*c);
                }
            }
        }

    }
    return 0;
}
