/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:03:19 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/05 16:27:15 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res[16];
	int		i;

	i = 15;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	n = n < 0 ? -1 * n : n;
	while (n)
	{
		res[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	while (i + 1 < 16)
	{
		write(fd, &res[i + 1], 1);
		i++;
	}
}