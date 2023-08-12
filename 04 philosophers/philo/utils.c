/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:41:25 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/12 18:43:19 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	convert_args(t_args *t_av, char **av)
{
	t_av->nop = ft_atoi(av[1]);
	t_av->ttd = ft_atoi(av[2]);
	t_av->tte = ft_atoi(av[3]);
	t_av->tts = ft_atoi(av[4]);
	if (t_av->ar == 6)
		t_av->notep = ft_atoi(av[5]);
}

void	exit_func(t_args *t_av, int i)
{
	if (i == 1)
		printf("Enter only 4 or 5 positive integers.\n");
	else if (i == 2)
	{
		printf("Enter only positive integers.\n");
		free(t_av);
	}
	else if (i == 3 || i == 4)
	{
		if (!t_av->any_dead)
			printf("Each of the philosophers ate %d times.\n", t_av->notep);
		i = 0;
		while (i < t_av->nop)
		{
			free(t_av->tmp_hold[i]);
			i++;
		}
		free(t_av->tmp_hold);
		free(t_av->threads);
		free(t_av->fork);
	}
	else if (i == 5)
		free(t_av);
	exit (i);
}

void	check_args(t_args *t_av, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < t_av->ar)
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				exit_func(t_av, 2);
		i++;
	}
	convert_args(t_av, av);
}

void	t_av_init_helper(t_args *t_av)
{
	t_av->threads = (pthread_t *)malloc(sizeof(t_av->threads) * t_av->nop);
	t_av->fork
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (t_av->nop + 1));
	t_av->tmp_hold = (t_thread **)malloc(sizeof(t_thread *) * t_av->nop);
}

void	ft_usleep(t_thread *t_one, long long _time)
{
	struct timeval	ct;
	long long		a;
	long long		b;
	int				key;

	a = 0;
	key = 0;
	if (t_one->tte * 2 >= t_one->ttd)
		key = t_one->ttd - t_one->tte;
	else if (t_one->tte * 3 >= t_one->ttd)
		key = t_one->ttd - t_one->tte * 2;
	gettimeofday(&ct, NULL);
	b = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	while (a - b < _time)
	{
		usleep(100);
		any_dead_check(t_one);
		gettimeofday(&ct, NULL);
		a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
		if (key && a - b > key)
			pthread_mutex_unlock(&t_one->next->v_fork[0]);
	}
}
