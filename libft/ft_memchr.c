/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:41:29 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/11/25 20:10:13 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*p;
	size_t	cu;

	p = (char *)str;
	cu = 0;
	while (cu < n)
	{
		if (*(p + cu) == (char)c)
			return (p + cu);
		cu++;
	}
	return (NULL);
}
