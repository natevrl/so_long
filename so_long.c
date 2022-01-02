#include <mlx.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    carre(t_data img)
{
    int x;
    int y;

    x = -1;
    while (++x != 60)
    {
        y = -1;
        while (++y != 60)
	        my_mlx_pixel_put(&img, 960 + x, 540 + y, 0x000000FF);
    }
}

void    triangle_rectangle(t_data img)
{
    int x = 0;
    int y = 0;

    while (y < 60)
    {
        x = 0;
        while (x != y)
        {
	        my_mlx_pixel_put(&img, 960 + x, 840 + y, 0x000000FF);
            x++;
        }
        y++;
    }
}

void    triangle_isocele(t_data img)
{

    int y;
    int x;

    y = 0;
    while (y < 60)
    {
	    my_mlx_pixel_put(&img, 960 + y, 240 + y, 0x00FF0000);
	    my_mlx_pixel_put(&img, 960 - y, 240 + y, 0x0000FF00);
        if (y == 59)
        {
            x = y;
            while (x-- != 0)
        	    my_mlx_pixel_put(&img, 960 + x, 240 + y, 0x0000FF00);
            while (x++ != y)
        	    my_mlx_pixel_put(&img, 960 - x, 240 + y, 0x000000FF);
        }
        y++;
    }
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    carre(img);
    triangle_rectangle(img);
    triangle_isocele(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}