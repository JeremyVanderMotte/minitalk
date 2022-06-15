/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ull.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:59:02 by jvander-          #+#    #+#             */
/*   Updated: 2021/08/27 14:43:58 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_ull(unsigned long long nbr, const char *base)
{
	char				nb_to_print[256];
	int					cpt;
	int					ret;

	nb_to_print[ft_nb_len(nbr)] = '\0';
	cpt = 0;
	ret = 1;
	while (nbr > ft_strlen(base) - 1)
	{
		nb_to_print[cpt++] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		ret++;
	}
	nb_to_print[cpt++] = base[nbr % ft_strlen(base)];
	while (--cpt >= 0)
		ft_putchar(nb_to_print[cpt]);
	return (ret);
}
