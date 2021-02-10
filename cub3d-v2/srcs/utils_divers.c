/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_divers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:14:08 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 18:15:10 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			ft_atoi_cub(const char *str, int *pos)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	*pos = *pos + i;
	return (res);
}

int			define_tile_size(t_map *map)
{
	map->tile_col = map->r_x / map->map_col;
	map->tile_lin = map->r_y / map->map_lin;
	if (map->tile_col > map->tile_lin)
		map->tile_min = map->tile_lin;
	else
		map->tile_min = map->tile_col;
	map->tile_col = map->tile_min; // A CHANGER
	map->tile_lin = map->tile_min; // A CHANGER
	return (1);
}

int			hit_a_wall(double x, double y, char **map_tab, t_map *map)
{
	int		i_lin;
	int		j_col;

	if (x < 0 || y < 0)
		return (1);
	i_lin = y / map->tile_lin;
	j_col = x / map->tile_col;
	if (i_lin < map->map_lin && j_col < map->map_col
		&& map_tab[i_lin][j_col] == '0')
		return (0); //peut ton marcher sur un objet?
	else if (i_lin < map->map_lin && j_col < map->map_col
			&& (map_tab[i_lin][j_col] == '1' || map_tab[i_lin][j_col] == 'x'))
		return (1);
	else if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '2')
		return (2);
	else
		return (-1);
}

void		check_res(t_data *d, int mod)
{
	int		width;
	int		height;

	mlx_get_screen_size(d->mlx->ptr, &width, &height);
	if (mod == 2)
	{
		if (d->map->r_x > (unsigned int)width)
			d->map->r_x = (unsigned int)width;
		if (d->map->r_y > (unsigned int)height)
			d->map->r_y = (unsigned int)height;
	}
	return ;
}

int			create_trgb(int t, int r, int g, int b)
{
	int color;

	color = t << 24;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}
