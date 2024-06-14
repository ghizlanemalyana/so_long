/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:11:54 by gmalyana          #+#    #+#             */
/*   Updated: 2024/06/14 17:30:10 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		return (1);	// Print message
	ft_bzero(&game, sizeof(t_game));
	fd = is_valid_file(argv[1]);
	if (fd == 0)
		ft_exit(NULL, "Invalid file");
	if (get_map(&game, fd) == 0)
		ft_exit(NULL, "Invalid map");
	run(&game);
}
