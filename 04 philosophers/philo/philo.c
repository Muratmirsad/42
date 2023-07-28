/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:58 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/28 14:29:57 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// TODO tek philo test
//     TODO
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void	philo_not_control(t_args *t_av)
{
	int	key;
	int	i;
	
	i = 0;
	key = 0;
	while (i < t_av->nop)
	{
		if (t_av->not_control[i] <= 0)
			key++;
		i++;
	}
	if (key == t_av->nop)
		exit_func(t_av, 4);
}

//! philo 2 | fork l: 2 - r: 3

static void	right_left_init(t_args *t_av, int *right, int *left, int *pth_id)
{
	if (t_av->id_index + 1 == t_av->nop)
		*right = 0;
	else
		*right = t_av->id_index + 1;
	*left = t_av->id_index;
	*pth_id = t_av->id_index;
	t_av->id_index++;
}

static void	*pthread_func(void *arg)
{
	t_args			*t_av;
	struct timeval	current_time;
	long long		a;
	long long		b;
	int				right;
	int				left;
	int 			pth_id;


	pthread_mutex_lock(&mutex);
	t_av = (t_args *)arg;
	right_left_init(t_av, &right, &left, &pth_id);
	pthread_mutex_unlock(&mutex);
	a = 0;
	while (1)
	{
		//!   KONTROL ET
		gettimeofday(&current_time, NULL);
		b = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
		if (b - a > t_av->ttd && a)
			exit_func(t_av, 3);
		a = b;
		printf("[%d] %d is thinking\n", t_av->timestamp_in_ms / 1000, pth_id + 1);
		pthread_mutex_lock(&t_av->fork[left]);
		pthread_mutex_lock(&t_av->fork[right]);
		printf("[%d] %d has taken a fork\n", t_av->timestamp_in_ms / 1000, pth_id + 1);
		printf("[%d] %d is eating\n", t_av->timestamp_in_ms / 1000, pth_id + 1);
		usleep(t_av->tte * 1000);
		t_av->timestamp_in_ms += t_av->tte * 1000;
		if (t_av->ar == 6)
		{
			t_av->not_control[pth_id]--;
			philo_not_control(t_av);
		}
		pthread_mutex_unlock(&t_av->fork[left]);
		pthread_mutex_unlock(&t_av->fork[right]);
		printf("[%d] %d is sleeping\n", t_av->timestamp_in_ms / 1000, pth_id + 1);	
		usleep(t_av->tts * 1000);
		t_av->timestamp_in_ms += t_av->tts * 1000;
	}
    pthread_exit(NULL);
}

static void	philo_handle(t_args *t_av)
{
	int	i;

	t_av->ids = (int *)malloc(sizeof(int) * t_av->nop);
	t_av->not_control = (int *)malloc(sizeof(int) * t_av->nop);
	t_av->threads = (pthread_t *)malloc(sizeof(t_av->threads) * t_av->nop);
	t_av->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * t_av->nop);
	t_av->timestamp_in_ms = 0;
	t_av->id_index = 0;
	i = 0;
	while (i < t_av->nop)
	{
		t_av->ids[i] = i + 1;
		t_av->not_control[i] = t_av->notep;
		pthread_mutex_init(&t_av->fork[i], NULL);
		usleep(10);
		pthread_create(&t_av->threads[i], NULL, pthread_func, t_av);
		i++;
	}
	i = 0;
	while (i < t_av->nop)
		pthread_join(t_av->threads[i++], NULL);
}

int	main(int ar, char **av)
{
	t_args	*t_av;

	if (ar != 5 && ar != 6)
		exit_func(0, 1);
	t_av = (t_args *)malloc(sizeof(t_args));
	t_av->ar = ar;
	check_args(t_av, av);
	philo_handle(t_av);
	return (0);
}
