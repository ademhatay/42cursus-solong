#include "solong.h"


int control_map(char *str)
{
	int x;
	t_map *map = NULL;
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\n')
			x = map -> height++;
		i++;
	}
	return(x);
}

void	ft_control_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Girdiğiniz Dosyayı Bulamadım.");
		exit(0);
	}
	else
		close(fd);
}


int	ft_av_control(char *map, char *true_map)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(map);
	while (map[len - 1] != '.')
	{
		if (map[len - 1] == true_map[i])
			i++;
		else
		{
			ft_putendl("Harita uzantısı '.ber' değil");
			return (0);
		}
		len--;
	}
    ft_control_file(map);
	return (1);
}


/*
	1 - check args
	2 - check extention
	3 - open file
	4 - file check and start game 
*/

int main(int ac, char **av)
{
    int fd;
	int map_c;

    if (ac != 2)
    {
        ft_putendl("Haritayı Belirtin");
        return (0);
    }
    map_c = ft_av_control(av[1], "reb");
	if (map_c == 0)
		return (0);
    fd = open(av[1], O_RDONLY);
	control_map(check(fd));
	return (EXIT_SUCCESS);
}