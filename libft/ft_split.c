/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:26:34 by akurz             #+#    #+#             */
/*   Updated: 2021/08/23 09:23:15 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

//columns comes from create_map
//declared with strlen(substr)
static char	*ft_getsubstr(const char *s, char c, int *pos, int *columns)
{
	int		i;
	char	*substr;

	while (s[*pos] == c)
		(*pos)++;
	i = *pos;
	while (s[i] != c && s[i] != '\0')
		i++;
	substr = ft_substr(s, *pos, i - *pos + 1);
	(*columns) = ft_strlen(substr);
	if (substr == NULL)
		return (NULL);
	*pos = i + 1;
	return (substr);
}

char	**ft_split(char const *s, char c, int *columns)
{
	char	**array;
	int		wordcount;
	char	*substr;
	int		i;
	int		pos;

	if (s == 0)
		return (0);
	wordcount = ft_countwords(s, c);
	array = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < wordcount)
	{
		substr = ft_getsubstr(s, c, &pos, columns);
		if (substr == NULL)
			return (NULL);
		array[i] = substr;
		i++;
	}
	array[i] = NULL;
	return (array);
}
