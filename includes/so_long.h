/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:58:02 by gmalyana          #+#    #+#             */
/*   Updated: 2024/06/14 17:37:24 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define IMG_WIDTH 100 
# define IMG_HEIGHT 100

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13
# define ESC_KEY 53

# define WIN_TITLE "So long"
# define WALL_IMG "textures/WALL.xpm"
# define SPACE_IMG "textures/SPACE.xpm"
# define PLAYER_IMG "textures/PLAYER.xpm"
# define BANANA_IMG "textures/BANANA.xpm"
# define EXIT_IMG "textures/EXIT.xpm"

typedef struct	s_game {
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		collectibles;
	int		moves;
	int		width;
	int		height;
	int 	x_player;
	int 	y_player;
}				t_game;

/*		Game	*/
void	run(t_game *game); 

/*		Parce	*/
int 	map_checker(t_game *game);
int		get_map(t_game *game, int fd);

/*		Utils	*/
int		is_valid_file(char *filename);
void	ft_exit(t_game *game, char *error);
void	ft_free(char **arr);
int		quit(t_game *game);

#endif
