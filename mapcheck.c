/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:43:37 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/06/12 17:50:52 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


void	floodfill(char **map, int y, int x, int *coin , int *exit)
{
	if(coin == 0 && exit == 0)
		return;
	if (map[y][x] == '1')
		return ;
	if(map[y][x] == 'C')
			*coin -= 1;
	if(map[y][x] == 'E')
			*exit -= 1;
	map[y][x] = '1';
	floodfill(map, y, x + 1,coin, exit);
	floodfill(map, y, x - 1,coin, exit);
	floodfill(map, y + 1, x,coin, exit);
	floodfill(map, y - 1, x,coin, exit);
}


int	comparison(char **line)
{
	int i;
	int j;
	int size;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(line[j]);
	size = 0;

	while (line[size] != NULL)
		size++;
	while(line[j])
	{
		i = 0;
		while(line[j][i])
		{
			if(line[0][i] != '1' || line[j][0] != '1' || line[j][len - 1] != '1' || line[size - 1][i] != '1')
				{
					write(2, "Error: mapp shape\n", 18);
					exit(1);
				}
			i++;
		}
		j++;
	}
	return (1);
}

void	printarr(char **arr) 
{
    int i = 0;
    while (arr[i]) 
	{
        printf("%s\n", arr[i]);
        i++;
    }
}

void	getmap(int fd, t_game *game)
{
	char buffer[BUFFER_SIZE];
	
	read(fd, buffer, BUFFER_SIZE);
	game->map = ft_split(buffer, '\n');
	game->map2 = ft_split(buffer, '\n');
}

void	check_rep(t_game *game)
{
	int i;
	int j;

	i = 0;
	game->p_count = 0;
	game->c_count = 0;
	game->e_count = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p_count++;
				game->p_y = i;
				game->p_x = j;
			}
			else if (game->map[i][j] == 'C')
				game->c_count++;
			else if(game->map[i][j] == 'E')
				game->e_count++;
			j++;
		}
		i++;
	}
	if(game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
	{
		printf("error\n");
		exit(1);
	}
}
	
void	check_components(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'E' || game->map[i][j] == '1'
				|| game->map[i][j] == '0')
				j++;
			else
			{
				printf("error\n");
				exit(1);
			}
		}
		i++;
	}
}

int main()
{

	t_game *game;
	game = malloc(sizeof(t_game));
	int fd = open("map.ber", O_RDONLY);
	if(!game || fd < 0)
		return(0);
	getmap(fd, game);
	comparison(game->map);
	check_components(game);
	check_rep(game);
	
	int cop_coin=game->c_count;
	int cop_exit=game->e_count;

	floodfill(game->map,game->p_y,game->p_x,&cop_coin, &cop_exit);
	for (int i = 0; i < 5; i++)
		printf("%s\n",game->map[i]);
	

	if(cop_coin != 0 || cop_exit != 0)
		printf("NOT a valid path: %d  \n", game->c2_count);
}
