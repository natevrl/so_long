#include <unistd.h>


void    triangle()
{
    int x = 0;
    int y;

    while (x < 6)
    {
        y = x;
        while (y != 0)
        {
            write(1, "*", 1);
            y--;
        }
        x++;
        write(1, "\n", 1);
    }
}

int main()
{
    int x = 10;
    printf("%d&& %d\n", x, -x);
    triangle();

    return 0;
}