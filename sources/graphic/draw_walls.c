/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:13:46 by nluya             #+#    #+#             */
/*   Updated: 2022/03/09 20:13:55 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/parse.h"

unsigned long	color_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	wall_side(t_cube *cube, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = cube->coords->posy + ray->perpwalldist * ray->raydiry;
	else
		wall_x = cube->coords->posx + ray->perpwalldist * ray->raydirx;
	wall_x -= floor(wall_x);
	ray->texx = (int)(wall_x * (double)(TEX));
	if (ray->side == 0 && ray->raydirx > 0)
		ray->texx = TEX - ray->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texx = TEX - ray->texx - 1;
	ray->step = 1.0 * TEX / ray->lineheight;
	ray->texpos = (ray->drawstart - HEIGHT / 2 + ray->lineheight / 2);
	ray->texpos *= ray->step;
}

void	draw_walls(t_cube *cube)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ray_init(cube, x, &ray);
		step_sidedist_init(cube, &ray);
		dda(cube, &ray);
		line_height(&ray);
		wall_side(cube, &ray);
		texturing(cube, &ray, x);
		x++;
	}
}
