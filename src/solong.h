#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <stdio.h>

# define BUFFER_SIZE 5

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*img_ptr;
	t_vector	size;
	t_vector	pos;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_map
{
	char		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_game
{
	int			count_collec;
	int			count_steps;
}	t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_img		img;
}	t_var;

void	ft_putchar(const char c);
void	ft_putstr(const char *str);
int		ft_strlen(char *str);
void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
char	*ft_strjoin(char *left_str, char *buff);

void	ft_control_file(char *map);
int		ft_av_control(char *map, char *true_map);
char	*get_map(int fd);
int get_x_y(t_var *var, char **av);

#endif
