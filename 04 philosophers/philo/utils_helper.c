/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:36:16 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/12 18:26:50 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_eating(t_thread *t_one)
{
	struct timeval	ct;
	long long		a;

	pthread_mutex_lock(&t_one->v_fork[0]);
	if (any_dead_check(t_one))
		return ;
	pthread_mutex_lock(&t_one->next->v_fork[0]);
	if (any_dead_check(t_one))
		return ;
	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	printf("%lld %d has taken a fork\n", a, t_one->id);
	printf("%lld %d is eating\n", a, t_one->id);
	t_one->last = a;
	ft_usleep(t_one, t_one->tte);
	pthread_mutex_unlock(&t_one->next->v_fork[0]);
	pthread_mutex_unlock(&t_one->v_fork[0]);
}

void	ft_sleeping(t_thread *t_one)
{
	struct timeval	ct;
	long long		a;
	long long		b;

	a = 0;
	gettimeofday(&ct, NULL);
	b = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	printf("%lld %d is sleeping\n", b, t_one->id);
	while (a - b < t_one->tts)
	{
		usleep(100);
		any_dead_check(t_one);
		gettimeofday(&ct, NULL);
		a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	}
}

void	ft_thinking(t_thread *t_one)
{
	struct timeval	ct;
	long long		a;

	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	printf("%lld %d is thinking\n", a, t_one->id);
}

static void	*one_philo_help(void *arg)
{
	t_args	*t_av;

	t_av = (t_args *)arg;
	printf("0 1 is thinking\n");
	printf("0 1 has taken a fork\n");
	printf("%d 1 died\n", t_av->ttd);
	pthread_exit(NULL);
}

void	one_philo(t_args *t_av)
{
	pthread_t	philo;

	if (!t_av->nop)
		printf("number of philosophers cannot be 0.\n");
	else
	{
		pthread_create(&philo, NULL, one_philo_help, t_av);
		pthread_join(philo, NULL);
	}
	exit_func(t_av, 5);
}
