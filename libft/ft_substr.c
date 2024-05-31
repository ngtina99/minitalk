/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:47:44 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/02/04 22:23:03 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		substring = ft_strdup("");
		return (substring);
	}
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		i++;
	}
	substring = (char *)malloc((sizeof(char)) * (i) + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
/*int main()
{
	const char *s = "something";
	unsigned int start = 4;
	size_t len = sizeof(s);

	char *result = ft_substr(s, start, len);

	if (result) 
	{
		printf("%s\n", result);
		free(result);
	}
}*/