#include "header.h"

#include <stdio.h>
int main()
{
    t_mlx      *vars;
    printf("TEEEST");

    vars = malloc(sizeof(t_mlx));
    if (vars == 0)
        return (0);
    vars->player = malloc(sizeof(t_img));

	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, X_RESOLUTION, Y_RESOLUTION, "NbenhaGame");

    vars->player->relative_path = "./character.xpm";
	vars->player->img = mlx_xpm_file_to_image(vars->mlx, vars->player->relative_path, &vars->player->img_width, &vars->player->img_height);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, 64, 64);

	vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./rock.xpm", &vars->player->img_width, &vars->player->img_height);

    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, 256, 64);

    mlx_destroy_image(vars->mlx, vars->player->img);
    sleep(2);
	vars->player->img = mlx_xpm_file_to_image(vars->mlx, "./rock.xpm", &vars->player->img_width, &vars->player->img_height);


    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, 256, 128);

    //mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, 512, 64);



    mlx_loop(vars->mlx);
}
