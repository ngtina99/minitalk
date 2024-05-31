/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:47:44 by thuy-ngu          #+#    #+#             */
/*   Updated: 2023/10/14 17:44:38 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size == 0 || size < dstlen)
		return (srclen + size);
	while (src[i] && (dstlen + i) < (size - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*int main()
{
	char dst[] = "is";
	char src[] = "something";
	printf("%zu\n", sizeof(dst));
	printf("%zu\n", ft_strlcat(dst, src, sizeof(dst)));
	printf("%s\n", dst);
}*/
