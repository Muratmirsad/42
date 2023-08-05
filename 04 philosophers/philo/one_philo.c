/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:30:02 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/05 17:35:30 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
