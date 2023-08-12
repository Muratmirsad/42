/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:58 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/12 18:43:51 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*pthread_func(void *arg)
{
	t_thread	*t_one;

	t_one = (t_thread *)arg;
	t_one->last = 0;
	while (1)
	{
		ft_eating(t_one);
		if (any_dead_check(t_one))
			break ;
		ft_sleeping(t_one);
		if (any_dead_check(t_one))
			break ;
		ft_thinking(t_one);
		if (--t_one->notep == 0 || any_dead_check(t_one))
			break ;
	}
	pthread_mutex_unlock(&t_one->m_dead[0]);
	pthread_exit(NULL);
}

static void	init_helper(t_args *t_av)
{
	struct timeval	current_time;
	long long		v_time;
	int				i;

	gettimeofday(&current_time, NULL);
	v_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	i = 0;
	while (i < t_av->nop)
	{
		if (i + 1 == t_av->nop)
			t_av->tmp_hold[i]->next = t_av->tmp_hold[0];
		else
			t_av->tmp_hold[i]->next = t_av->tmp_hold[i + 1];
		t_av->tmp_hold[i]->v_fork = &t_av->fork[i];
		t_av->tmp_hold[i]->m_dead = &t_av->fork[t_av->nop];
		t_av->tmp_hold[i]->id = i + 1;
		t_av->tmp_hold[i]->nop = t_av->nop;
		t_av->tmp_hold[i]->ttd = t_av->ttd;
		t_av->tmp_hold[i]->tte = t_av->tte;
		t_av->tmp_hold[i]->tts = t_av->tts;
		t_av->tmp_hold[i]->notep = t_av->notep;
		t_av->tmp_hold[i]->start_time = v_time;
		t_av->tmp_hold[i]->last = v_time;
		t_av->tmp_hold[i++]->t_av = t_av;
	}
}

static void	philo_handle(t_args *t_av)
{
	t_thread	*tmp;
	int			i;

	t_av_init_helper(t_av);
	i = 0;
	while (i < t_av->nop + 1)
	{
		pthread_mutex_init(&t_av->fork[i], NULL);
		tmp = (t_thread *)malloc(sizeof(t_thread));
		t_av->tmp_hold[i] = tmp;
		i++;
	}
	t_av->any_dead = 0;
	init_helper(t_av);
	i = -1;
	while (++i < t_av->nop)
	{
		pthread_create(&t_av->threads[i], NULL,
			pthread_func, t_av->tmp_hold[i]);
		usleep(2);
	}
	i = 0;
	while (i < t_av->nop)
		pthread_join(t_av->threads[i++], NULL);
	exit_func(t_av, 4);
}

int	main(int ar, char **av)
{
	t_args	*t_av;

	if (ar != 5 && ar != 6)
		exit_func(0, 1);
	t_av = (t_args *)malloc(sizeof(t_args));
	t_av->ar = ar;
	check_args(t_av, av);
	if (t_av->nop < 2)
		one_philo(t_av);
	philo_handle(t_av);
	return (0);
}
