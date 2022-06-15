/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:35:58 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/27 13:19:40 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_send_signal(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Error sending signal\n");
		return (0);
	}
	usleep(150);
	return (1);
}

static int	ft_send_end(int pid)
{
	int	i;

	i = 64;
	while (i)
	{
		if (!ft_send_signal(pid, SIGUSR2))
			return (0);
		i /= 2;
	}
	return (1);
}

static int	ft_send_message(int pid, char *str)
{
	int	bit_in;
	int	i;

	i = 0;
	while (str[i])
	{
		bit_in = 64;
		while (bit_in)
		{
			if (str[i] / bit_in)
			{
				str[i] -= bit_in;
				if (!ft_send_signal(pid, SIGUSR1))
					return (0);
			}
			else
			{
				if (!ft_send_signal(pid, SIGUSR2))
					return (0);
			}
			bit_in /= 2;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong numbers of args\n");
		return (1);
	}
	if (!check_number(argv[1]))
	{
		ft_printf("PID server is not valid\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!ft_strlen(argv[2]))
		return (0);
	if (!ft_send_message(pid, argv[2]))
		return (1);
	if (!ft_send_end(pid))
		return (1);
	return (0);
}
