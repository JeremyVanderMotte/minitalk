/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:34:52 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/27 09:55:14 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <limits.h>

int	ft_atoi(const char *s);
int	check_number(const char *s);

#endif
