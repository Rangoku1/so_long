#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 100000
typedef struct s_game
{
	char **map;
	int len;
	char *name;
}	t_game;

char	**ft_split(char const *s, char c);

#endif
