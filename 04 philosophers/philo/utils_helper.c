/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:36:16 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/06 00:32:41 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_thread *t_one, long long a)
{
	printf("%lld %d has taken a fork\n", a, t_one->id);
	printf("%lld %d is eating\n", a, t_one->id);
	usleep(t_one->tte * 1000);
}

void	ft_sleeping(t_thread *t_one, long long a)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	printf("%lld %d is sleeping\n", a, t_one->id);
	usleep(t_one->tts * 1000);
}

int	ft_thinking(t_thread *t_one, int key)
{
	struct timeval	ct;
	long long		a;

	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	if (key)
		printf("%lld %d is thinking\n", a, t_one->id);
	return (a);
}

static void	*one_philo_help(void *arg)
{
	t_args	*t_av;

	t_av = (t_args *)arg;
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
