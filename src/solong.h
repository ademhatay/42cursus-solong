#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <stdio.h>

# define UP_KEY			13
# define DOWN_KEY		1
# define RIGHT_KEY		2
# define LEFT_KEY		0
# define EXIT_BOTTON	17
# define BUFFER_SIZE 5

typedef struct components
{
    int     count_coin;
    int     count_exit;
    int     count_player;
    void    *empty;
    void    *wall;
    void    *mlx;
    void    *win;
    void    *player_w;
    void    *player_s;
    void    *player_a;
    void    *player_d;
    int     move;
    char    **map;
} t_comp;

typedef struct map
{
	int height;
	int width;
} t_map;

void	ft_putchar(const char c);
void	ft_putstr(const char *str);
int     ft_strlen(char *str);
void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
char	*ft_strjoin(char *left_str, char *buff);
char	*check(int fd);

#endif
