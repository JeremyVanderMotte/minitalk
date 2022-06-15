/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:59:48 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/21 14:12:19 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr_base(int nbr, const char *base);
int		ft_putstr(char const *str);
size_t	ft_strlen(char const *str);
int		ft_nb_len(long long nbr);
int		ft_putnbr_base_u(unsigned int nbr, const char *base);
int		ft_putnbr_base_ull(unsigned long long nbr, const char *base);

#endif