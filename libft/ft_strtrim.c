/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:47:44 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/02/04 22:23:10 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (ft_substr(s1, 0, len));
}
/*int	main()
{
	printf("%s\n", ft_strtrim("abcdefge", "acbe"));
}*/