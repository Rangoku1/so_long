/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:33:53 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/11/25 20:24:06 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ss;
	unsigned char	*ds;

	ss = (unsigned char *) src;
	ds = (unsigned char *) dst;
	if (!ss && !ds)
		return (0);
	if (ss < ds)
		ft_memcpy(ds, ss, len);
	else if (ss > ds)
	{
		while (len)
		{
			*ds = *ss;
			ds++;
			ss++;
			len--;
		}
	}
	return (dst);
}
