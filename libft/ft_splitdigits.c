/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:36:24 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/22 14:56:01 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_splitdigits(int n, int len, char *s)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		s[len - len] = '-';
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_splitdigits((int)nb / 10, len - 1, s);
		s[len] = nb % 10 + '0';
	}
	else
		s[len] = nb + '0';
}
