#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

#define BUFFER_SIZE 100000
typedef struct s_game
{
	char	**map;
	char	**map2;
	int		len;
	int		p_count;
	int		e_count;
	int		c_count;

}	t_game;

#endif
