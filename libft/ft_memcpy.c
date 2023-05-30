/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:52:10 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/11/24 19:30:42 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dc;
	unsigned char	*cc;

	dc = (unsigned char *)dst;
	cc = (unsigned char *)src;
	if (!dc && !cc)
		return (0);
	while (n--)
		dc[n] = cc[n];
	return (dst);
}
