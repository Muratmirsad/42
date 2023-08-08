/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:36:16 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/08 03:57:51 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_thread *t_one)
{
	struct timeval	ct;
	long long		a;
	int				tmp;

	tmp = 5000;
	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	t_one->last = a;
	printf("%lld %d has taken a fork\n", a - 2, t_one->id);
	printf("%lld %d is eating\n", a - 2, t_one->id);
	if (t_one->tte - t_one->tts > 0)//!
		tmp += t_one->tte - t_one->tts;
	usleep((t_one->tte * 1000) - tmp);
	gettimeofday(&ct, NULL);
	pthread_mutex_unlock(&t_one->v_fork[0]);
	pthread_mutex_unlock(&t_one->next->v_fork[0]);
}

void	ft_sleeping(t_thread *t_one)
{
	struct timeval	ct;
	long long		a;

	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	printf("%lld %d is sleeping\n", a, t_one->id);
	usleep(t_one->tts * 1000);
	if (t_one->tte - t_one->tts > 0)//!
		usleep((t_one->tte - t_one->tts) * 1000);
}

void	ft_thinking(t_thread *t_one)
{
	struct timeval	ct;
	long long		a;

	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	printf("%lld %d is thinking\n", a, t_one->id);
	pthread_mutex_lock(&t_one->v_fork[0]);
	pthread_mutex_lock(&t_one->next->v_fork[0]);
	usleep(2000);
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
