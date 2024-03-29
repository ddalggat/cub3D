/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:07:30 by nluya             #+#    #+#             */
/*   Updated: 2022/03/10 20:07:31 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	check_fd(int *fd, char *file_name)
{
	char	buf;
	int		len;
	char	*ext;

	*fd = open(file_name, O_RDONLY);
	if (*fd < 0 || read(*fd, &buf, 0) < 0)
		msg_stderror(file_name);
	len = ft_strlen(file_name);
	ext = ".cub";
	if (ft_strncmp(ext, file_name + len - 4, 5) != 0)
		msg_err("Map has invalid extension\n");
	return (0);
}

void	init_empty_elem(t_elements *elem)
{
	elem->no = NULL;
	elem->so = NULL;
	elem->we = NULL;
	elem->ea = NULL;
	elem->fl[0] = -1;
	elem->fl[1] = -1;
	elem->fl[2] = -1;
	elem->cl[0] = -1;
	elem->cl[1] = -1;
	elem->cl[2] = -1;
	elem->width = 0;
	elem->height = 0;
	elem->dir = '0';
	elem->vec.x = -1;
	elem->vec.y = -1;
}

int	define_map_size(char *line, t_elements *elem)
{
	int	len;
	int	i;

	i = 0;
	elem->width = 0;
	elem->height = 0;
	while (line[i] != '\0')
	{
		len = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			i++;
			len++;
		}
		if (len > elem->width)
			elem->width = len;
		if (line[i] == '\n')
			i++;
		elem->height++;
	}
	return (0);
}

t_elements	*parse(int argc, char **argv)
{
	t_elements	*elem;
	char		*map_str;
	int			fd;

	if (argc != 2)
		msg_err("wrong number of arguments\n");
	check_fd(&fd, argv[1]);
	elem = malloc(sizeof(t_elements));
	if (!elem)
		msg_malloc_fail();
	init_empty_elem(elem);
	map_str = NULL;
	map_str = read_map(fd, elem, &map_str);
	if (map_str == NULL)
		msg_err("Map not found\n");
	define_map_size(map_str, elem);
	elem->map = create_array2(elem);
	fill_map(map_str, elem->map, elem->width, elem->height);
	check_start_point(elem->map, elem);
	check_walls(elem->map, elem);
	free(map_str);
	close(fd);
	return (elem);
}
