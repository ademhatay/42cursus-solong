#include "solong.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = (char *)malloc(len + 1);
	if (!s || !new_str)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

static int	wordcounter(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (i);
		while (*s != c && *s)
			s++;
		i++;
	}
	return (i);
}

static int	charcounter(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && (*s != c))
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		retindex;

	if (!s)
		return (0);
	retindex = 0;
	ret = malloc(sizeof(char *) * wordcounter(s, c) + 1);
	if (!ret)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		ret[retindex] = ft_substr(s, 0, charcounter(s, c));
		retindex++;
		s = s + charcounter(s, c);
	}
	ret[retindex] = NULL;
	return (ret);
}
