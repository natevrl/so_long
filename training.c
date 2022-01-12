typedef struct s_base
{
    int y;
    int x;
} t_base;

typedef struct s_training
{
    int test;
    t_base *soldat;
    t_base *maps;
} t_training;

#include <stdio.h>
int main()
{
    t_training pos;
    t_base coord;

    pos.test = 777;
    pos.soldat = &coord;



    coord.x = 10;
    coord.y = 5;

    printf("%d, %p // %d, %p\n", coord.x, &coord.x, pos.soldat->x, &pos.soldat->x);
    return (0);
}
