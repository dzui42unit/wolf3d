/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:49:32 by dzui              #+#    #+#             */
/*   Updated: 2016/11/24 14:35:06 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				count_dig(int n)
{
	int dig;

	dig = 1;
	while ((n /= 10) != 0)
		dig++;
	return (dig);
}

static unsigned long	count_pow(int n)
{
	unsigned long pow;

	pow = 10;
	while ((n /= 10) != 0)
		pow *= 10;
	return (pow);
}

static char				*ret_nbr(int n)
{
	unsigned long	pow;
	char			*res;
	int				digits;
	int				i;

	pow = count_pow(n);
	digits = count_dig(n);
	i = 0;
	if (n < 0)
	{
		digits++;
		res = (char *)malloc((sizeof(char) * digits) + 1);
		if (!res)
			return (NULL);
		res[i++] = '-';
		n *= -1;
	}
	else
		res = (char *)malloc((sizeof(char) * digits) + 1);
	if (!res)
		return (NULL);
	while (i < digits && ((pow /= 10) != 0))
		res[i++] = ((n / pow) % 10) + '0';
	res[i] = '\0';
	return (res);
}

char					*ft_itoa(int n)
{
	char *res;

	if (n != -2147483648)
		res = ret_nbr(n);
	else
	{
		n++;
		res = ret_nbr(n);
		res[ft_strlen(res) - 1]++;
	}
	return (res);
}
