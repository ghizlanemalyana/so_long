/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:42:36 by gmalyana          #+#    #+#             */
/*   Updated: 2024/06/14 16:35:56 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		map[y][x] = '1';
	if (map[y][x] != '1')
	{
		map[y][x] = '1';
		flood_fill(map, y - 1, x);
		flood_fill(map, y, x + 1);
		flood_fill(map, y + 1, x);
		flood_fill(map, y, x - 1);
	}
}

static char	*read_map(int fd)
{
	char	*line;
	char 	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '1')
			return (free(map), free(line), NULL);
		map = ft_strjoin(map, line);
		free(line);
		if (map == NULL)
			return (NULL);
	}
	if (map != NULL && *(ft_strrchr(map, '1') + 1) != '\0')
		return (free(map), NULL);
	return (map);
}

static int	is_map_valid(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_map(t_game *game, int fd)
{
	char *line;

	line = read_map(fd);
	if (line == NULL)
		return (close(fd), 0);
	game->map = ft_split(line, '\n');
	if (game->map == NULL)
		return (free(line), 0);
	if (map_checker(game) == 0)
		return (free(line), ft_free(game->map), 0);
	flood_fill(game->map, game->y_player, game->x_player);
	if (is_map_valid(game->map) == 0)
		return (free(line), ft_free(game->map), 0);
	ft_free(game->map);
	game->map = ft_split(line, '\n');
	free(line);
	if (game->map == NULL)
		return (0);
	return (1);
}
