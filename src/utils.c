/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:10 by gmalyana          #+#    #+#             */
/*   Updated: 2024/06/14 17:37:01 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}

void	ft_exit(t_game *game, char *error)
{
	if (game != NULL)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_free(game->map);
	}
	if (error != NULL)
		ft_printf("Error\n%s\n",error);
	exit(0);
}

int	is_valid_file(char *filename)
{
	char	*ber;
	int		fd;

	ber = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (ber == NULL || ft_strlen(ber) != 4)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

int	quit(t_game *game)
{
	ft_exit(game, NULL);
	return (0);
}
