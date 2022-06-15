/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:59:05 by jvander-          #+#    #+#             */
/*   Updated: 2021/08/27 14:44:01 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nbr, const char *base)
{
	char	nb_to_print[256];
	int		cpt;
	long	nbr_to_use;
	int		ret;

	nb_to_print[ft_nb_len(nbr)] = '\0';
	cpt = 0;
	ret = 1;
	nbr_to_use = nbr;
	if (nbr_to_use < 0)
	{
		ft_putchar('-');
		nbr_to_use = -nbr_to_use;
		ret++;
	}
	while (nbr_to_use > 9)
	{
		nb_to_print[cpt++] = base[nbr_to_use % ft_strlen(base)];
		nbr_to_use /= ft_strlen(base);
		ret++;
	}
	nb_to_print[cpt++] = base[nbr_to_use % ft_strlen(base)];
	while (--cpt >= 0)
		ft_putchar(nb_to_print[cpt]);
	return (ret);
}
