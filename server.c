/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:36:10 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/27 13:19:50 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_bit = 64;

static void	ft_catch(int sig)
{
	static char	c = 0;

	if (sig == SIGUSR1)
	{
		c += g_bit;
		g_bit /= 2;
	}
	else if (sig == SIGUSR2)
		g_bit /= 2;
	if (g_bit == 0)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		g_bit = 64;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void) argc;
	(void) argv;
	sa.sa_handler = ft_catch;
	if (sigemptyset(&sa.sa_mask) == -1)
		return (ft_printf("Error sigemptyset\n"));
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1)
		return (ft_printf("Error sigaddset\n"));
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		return (ft_printf("Error sigaddset\n"));
	ft_printf("PID : %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Error receiving signal\n"));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error receiving signal\n"));
	while (1)
		pause();
	return (0);
}
