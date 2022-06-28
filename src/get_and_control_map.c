#include "solong.h"

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

char	*get_map(int fd)
{
	static char	*left_str;
	char		*buff;
	int			rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	printf("%s", left_str);
	return (left_str);
}
