/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:58 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/05 22:35:50 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// TODO tek philo test
//     TODO

static void	*dead_func(t_thread *t_one, long long a)
{
	pthread_mutex_lock(&t_one->m_dead[0]);
	if (t_one->t_av->any_dead)
	{
		pthread_mutex_unlock(&t_one->m_dead[0]);
		pthread_mutex_unlock(&t_one->v_fork[0]);
		pthread_mutex_unlock(&t_one->next->v_fork[0]);
		pthread_exit(NULL);
	}
	t_one->t_av->any_dead = 1;
	pthread_mutex_unlock(&t_one->m_dead[0]);
	pthread_mutex_unlock(&t_one->v_fork[0]);
	pthread_mutex_unlock(&t_one->next->v_fork[0]);
	usleep((t_one->tte + t_one->tts + 50) * 1000);
	if (t_one->nop % 2)
		printf("%lld %d is dead\n", a + t_one->tte + 5, t_one->id);
	else
		printf("%lld %d is dead\n", a + 5, t_one->id);
	pthread_exit(NULL);
}

static void	*pthread_func(void *arg)
{
	t_thread	*t_one;
	long long	a;
	long long	b;

	t_one = (t_thread *)arg;
	while (1)
	{
		b = ft_thinking(t_one, 1);
		pthread_mutex_lock(&t_one->v_fork[0]);
		pthread_mutex_lock(&t_one->next->v_fork[0]);
		a = ft_thinking(t_one, 0);
		if (a - b > t_one->ttd)
			if (dead_func(t_one, a) == NULL)
				pthread_exit(NULL);
		ft_eating(t_one, a);
		pthread_mutex_unlock(&t_one->v_fork[0]);
		pthread_mutex_unlock(&t_one->next->v_fork[0]);
		ft_sleeping(t_one, a);
		pthread_mutex_lock(&t_one->m_dead[0]);
		if (--t_one->notep == 0 || t_one->t_av->any_dead)
			break ;
		pthread_mutex_unlock(&t_one->m_dead[0]);
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
		t_av->tmp_hold[i]->t_av = t_av;
		i++;
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
