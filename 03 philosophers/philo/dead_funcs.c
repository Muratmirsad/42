/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:44:20 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/13 12:31:26 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_func(t_thread *t_one, long long a)
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
	usleep(100000);
	printf("%lld %d is dead\n", a, t_one->id);
	pthread_exit(NULL);
}

int	any_dead_check(t_thread *t_one)
{
	struct timeval	ct;
	long long		a;

	if (((t_one->ttd >= t_one->tte * 2 && t_one->nop % 3)
			|| (t_one->ttd >= t_one->tte * 3 && t_one->nop % 2))
		&& t_one->ttd >= t_one->tte + t_one->tts)
		return (0);
	gettimeofday(&ct, NULL);
	a = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000)) - t_one->start_time;
	if (a - t_one->last > t_one->ttd || t_one->last == -1)
		if (dead_func(t_one, a) == NULL)
			return (1);
	pthread_mutex_lock(&t_one->m_dead[0]);
	if (t_one->t_av->any_dead)
	{
		pthread_mutex_unlock(&t_one->m_dead[0]);
		return (1);
	}
	pthread_mutex_unlock(&t_one->m_dead[0]);
	return (0);
}
