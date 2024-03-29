/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:08:10 by nluya             #+#    #+#             */
/*   Updated: 2022/03/10 20:08:12 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	move_forward(t_cube *cube)
{
	if (cube->src->map[(int)(cube->coords->posy)] \
	[(int)(cube->coords->posx + cube->coords->dirx)] == '0')
		cube->coords->posx += MS * cube->coords->dirx;
	if (cube->src->map[(int)(cube->coords->posy + cube->coords->diry)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy += MS * cube->coords->diry;
}

void	move_backward(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy] \
	[(int)(cube->coords->posx - cube->coords->dirx)] == '0')
		cube->coords->posx -= MS * cube->coords->dirx;
	if (cube->src->map[(int)(cube->coords->posy - cube->coords->diry)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy -= MS * cube->coords->diry;
}

void	move_left(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy] \
	[(int)(cube->coords->posx - cube->coords->planex)] == '0')
		cube->coords->posx -= MS * cube->coords->planex;
	if (cube->src->map[(int)(cube->coords->posy - cube->coords->planey)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy -= MS * cube->coords->planey;
}

void	move_right(t_cube *cube)
{
	if (cube->src->map[(int)cube->coords->posy] \
	[(int)(cube->coords->posx + cube->coords->planex)] == '0')
		cube->coords->posx += MS * cube->coords->planex;
	if (cube->src->map[(int)(cube->coords->posy + cube->coords->planey)] \
	[(int)cube->coords->posx] == '0')
		cube->coords->posy += MS * cube->coords->planey;
}

void	move(t_cube *cube)
{
	if (cube->key->w)
		move_forward(cube);
	if (cube->key->s)
		move_backward(cube);
	if (cube->key->right)
		rot_right(cube);
	if (cube->key->left)
		rot_left(cube);
	if (cube->key->a)
		move_left(cube);
	if (cube->key->d)
		move_right(cube);
}
