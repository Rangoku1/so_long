/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:43:37 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/05/23 17:36:29 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
int ftt_strlen(char *line)
{
	int i;

	i = 0;
	while(line[i])
		i++;
	return(i);
}

int	comparison(char **line)
{
	int i;
	int j;
	int size;
	
	i = 0;
	j = 0;
	size = 0;

	while (line[size] != NULL)
		size++;
	
	// int len = ftt_strlen(line[j]);
	printf("%d", size);
	printf("%s", line[4]);
	
	while(line[0][i] != '\0')
	{
		if(line[0][i] != '1' || line[j][0] != '1' || line[j][ftt_strlen(line[j]) - 1] || line[size - 1][i])
			return(0);
		i++;
		j++;
	}
	// printf("%d\n", i);
	return 1;
}

void printarr(char **arr)
{
	for(int i = 0; arr[i]; i++)
		printf("%s\n", arr[i]);
}
void	getmap(int fd, t_game *game)
{
	char buffer[BUFFER_SIZE];
	
	read(fd, buffer, BUFFER_SIZE);
	// printf("%s", )
	game->map = ft_split(buffer, '\n');
}
int main(int ac, char **av)
{
	t_game *game;
	game = malloc(sizeof(t_game));
	int fd = open("map.ber", O_RDONLY);
	if(!game || fd < 0)
		return(0);
	getmap(fd, game);
	comparison(game->map);
	// printarr(game->map);
}
