#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (len + start > s_len && s_len > start)
		len = s_len - start;
	if (s_len <= start)
		len = 0;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;
	size_t	start;
	size_t	end;

	start = 0;
	count = 0;
	while (s[start])
	{
		if (s[start] == c)
		{
			start++;
			continue ;
		}
		end = start;
		while (s[end] != c && s[end])
			end++;
		count++;
		start = end;
	}
	return (count);
}

static size_t	ft_splitword(char **split, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*word;

	i = 0;
	start = 0;
	while (s[start])
	{
		if (s[start] == c)
		{
			start++;
			continue ;
		}
		end = start;
		while (s[end] != c && s[end])
			end++;
		word = ft_substr(s, start, end - start);
		if (!word)
			return (i);
		split[i++] = word;
		start = end;
	}
	split[i] = 0;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;
	size_t	split_i;

	if (!s)
		return (0);
	count = ft_countword(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	split_i = ft_splitword(split, s, c);
	if (split_i < count)
	{
		i = 0;
		while (i < split_i)
		{
			free(split[i]);
			i++;
		}
		free(split);
		split = 0;
	}
	return (split);
}
