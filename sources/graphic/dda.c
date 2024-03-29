/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:08:27 by nluya             #+#    #+#             */
/*   Updated: 2022/03/10 20:08:29 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	ray_init(t_cube *cube, int x, t_ray *ray)
{
	ray->camerax = 2 * x / (double)WIDTH - 1;
	ray->raydirx = cube->coords->dirx + cube->coords->planex * ray->camerax;
	ray->raydiry = cube->coords->diry + cube->coords->planey * ray->camerax;
	ray->mapx = (int)(cube->coords->posx);
	ray->mapy = (int)(cube->coords->posy);
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
}

void	step_sidedist_init(t_cube *cube, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->sidedistx = (cube->coords->posx - ray->mapx) * ray->deltadistx;
		ray->stepx = -1;
	}
	else
	{
		ray->sidedistx = (ray->mapx - cube->coords->posx + 1.0) \
		* ray->deltadistx;
		ray->stepx = 1;
	}
	if (ray->raydiry < 0)
	{
		ray->sidedisty = (cube->coords->posy - ray->mapy) \
		* ray->deltadisty;
		ray->stepy = -1;
	}
	else
	{
		ray->sidedisty = (ray->mapy - cube->coords->posy + 1.0) \
		* ray->deltadisty;
		ray->stepy = 1;
	}
}

void	dda(t_cube *cube, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (cube->src->map[ray->mapy][ray->mapx] != '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
}

void	line_height(t_ray *ray)
{
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
}

void	draw_stripe(t_cube *cube, int x, t_ray *ray)
{
	int	y;

	y = ray->drawstart;
	while (y < ray->drawend)
	{
		my_mlx_pixel_put(cube->img, x, y, 0x00232323);
		y++;
	}
}
