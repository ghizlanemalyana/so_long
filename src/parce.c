/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:31:03 by gmalyana          #+#    #+#             */
/*   Updated: 2024/06/14 14:27:51 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
 
static int	is_rectangular(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i] != NULL && game->map[i + 1] != NULL)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
			return (0);
		i++;
	}
	game->width = ft_strlen(game->map[0]);
	game->height = i + 1;
	return (1);
}

static int	ft_parce(t_game *game, int x, int y, int exit)
{
	if (ft_strchr("01PCE", game->map[y][x]) == NULL
		|| game->map[y][x] == 'P' && game->x_player != 0
		|| game->map[y][x] == 'E' && exit == 1)
		return (0);
	if (x == 0 || y == 0 || y == game->height - 1 || x == game->width - 1)
		if (game->map[y][x] != '1')
			return (0);
	if (game->map[y][x] == 'C')
		game->collectibles++;
	if (game->map[y][x] == 'E')
		exit++;
	if (game->map[y][x] == 'P')
	{
		game->x_player = x;
		game->y_player = y;
	}
	return (1);
}

int map_checker(t_game *game)
{
	int	x;
	int	y;
	int	exit;

	y = 0;
	exit = 0;
	if (is_rectangular(game) == 0)
		return (0);
	while (game->map[y] != NULL)
	{
		x = 0;
		while(game->map[y][x] != '\0')
		{
			if (ft_parce(game, x, y, exit) == 0)
				return (0);
			x++;
		}
		y++; 
	}
	if (game->collectibles == 0)
		return (0);
	return (1);
}
