/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:59:17 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/02/01 15:28:14 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
		}
		if (*s)
			count++;
		while (*s != c && *s)
		{
			s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;
	int		j;
	size_t	start;

	lst = (char **)malloc(sizeof(char *) * ((ft_countword(s, c)) + 1));
	if (!lst)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			lst[j++] = ft_substr(s, start, (i - start));
		}
	}
	lst[j] = NULL;
	return (lst);
}

/* int main(void)
{
	const char *s = "it,is,something";
	char **result = ft_split(s, ',');
	if (result)
	{
		int i = 0;
		while (result[i] != NULL)
		{
			int j = 0;
			while (result[i][j] != '\0')
			{
				printf("%c", result[i][j]);
				j++;
			}
			printf("\n");
			free(result[i]);
			i++;
		}
		free(result);
	}
} */