#include "header.h"

#include <stdio.h>
int main()
{
    t_mlx      *vars;
    printf("TEEEST");

    vars = malloc(sizeof(t_mlx));
    if (vars == 0)
        return (0);
    vars->soldat = malloc(sizeof(t_img));

	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, X_RESOLUTION, Y_RESOLUTION, "NbenhaGame");

    vars->soldat->relative_path = "./character.xpm";
	vars->soldat->img = mlx_xpm_file_to_image(vars->mlx, vars->soldat->relative_path, &vars->soldat->img_width, &vars->soldat->img_height);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, 64, 64);

	vars->soldat->img = mlx_xpm_file_to_image(vars->mlx, "./rock.xpm", &vars->soldat->img_width, &vars->soldat->img_height);

    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, 256, 64);

    mlx_destroy_image(vars->mlx, vars->soldat->img);
    sleep(2);
	vars->soldat->img = mlx_xpm_file_to_image(vars->mlx, "./rock.xpm", &vars->soldat->img_width, &vars->soldat->img_height);


    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, 256, 128);

    //mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, 512, 64);



    mlx_loop(vars->mlx);
}
