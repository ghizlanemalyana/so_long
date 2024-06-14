/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:30:41 by gmalyana          #+#    #+#             */
/*   Updated: 2024/06/14 17:37:58 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*get_image_path(char c)
{
	if (c == '1')
		return (WALL_IMG);
	else if (c == 'P')
		return (PLAYER_IMG);
	else if (c == '0')
		return (SPACE_IMG);
	else if (c == 'C')
		return (BANANA_IMG);
	else
		return (EXIT_IMG);
}

static void	display_game(t_game *game)
{
	int		tmp;
	int		x;
	int 	y;
	void	*img;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			img = mlx_xpm_file_to_image(game->mlx,
				get_image_path(game->map[y][x]), &tmp, &tmp);
			if (img == NULL)
				ft_exit(game, strerror(errno));
			mlx_put_image_to_window(game->mlx, game->mlx_win, img,
				x * IMG_WIDTH, y * IMG_HEIGHT);
			mlx_destroy_image(game->mlx, img);
			x++;
		}
		y++;
	}
}

static int	move_player(t_game *game, int x, int y)
{
	char	next;

	next = game->map[game->y_player + y][game->x_player + x];
	if (next == '1'|| (next == 'E' && game->collectibles > 0))
		return (0);
	else
	{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + y][game->x_player + x] = 'P';
		game->x_player = game->x_player + x;
		game->y_player = game->y_player + y;
		game->moves++;
		ft_printf("Number of Moves: %d\n", game->moves);
		if (next == 'C')
			game->collectibles--;
		if (next == 'E')
		{
			ft_printf("Good job!\n");
			ft_exit(game, NULL);
		}
	}
	return (1);
}

static int	key_hook(int key, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == ESC_KEY)
		ft_exit(game, NULL);
	if (key == A_KEY || key == W_KEY || key == S_KEY || key == D_KEY)
	{
		if (key == A_KEY)
			x = -1;
		if (key == D_KEY)
			x = 1;
		if (key == W_KEY)
			y = -1;
		if (key == S_KEY)
			y = 1;
		if (move_player(game, x, y) == 1)
			display_game(game);
	}
	return (0);
}

void	run(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_exit(game, strerror(errno));
	game->mlx_win = mlx_new_window(game->mlx, game->width * IMG_WIDTH, game->height * IMG_HEIGHT, WIN_TITLE);
	if (game->mlx_win == NULL)
		ft_exit(game, strerror(errno));
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0, quit, game); // To be edited
	display_game(game);
	mlx_loop(game->mlx);
}
