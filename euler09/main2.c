#include <stdio.h>
#define PERIM 1000

int main()
{
    int a, b, c;
    char found = 0;
    for (a=3; !found && a<PERIM; ++a)
    {
        b = (PERIM*(PERIM-2*a)) / (2*(PERIM-a));
        c = PERIM - a - b;
        //(PERIM*(PERIM-2*a)) % (2*(PERIM-a)) == 0
        //ellenorzes, hogy pitagoraszi szamharmas-e
        if (a*a+b*b==c*c)
        {
            printf("a=%d, b=%d, c=%d\n", a, b, c);
            printf("A szorzatuk: %d\n", a*b*c);
            found = 1;
        }
    }
    return 0;
}
