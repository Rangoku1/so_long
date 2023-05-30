/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:24:11 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/11/28 13:20:49 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_s;
	size_t	src_s;
	size_t	j;

	if (dstsize == 0 || (!src && !dst))
	{
		if (dstsize == 0 && src)
			return (ft_strlen(src));
		return (0);
	}
	j = dstsize;
	src_s = ft_strlen(src);
	dst_s = ft_strlen(dst);
	while (*dst)
	{
		dst++;
		if (j > 0)
			j--;
	}
	while (*src && j-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	if (dstsize > dst_s)
		return (dst_s + src_s);
	return (dstsize + src_s);
}
