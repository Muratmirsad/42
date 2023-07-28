/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:42:07 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/28 14:36:44 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notep;
	int				ar;
	int				timestamp_in_ms;
	int				id_index;
	int				*ids;
	int				*not_control;
	pthread_t		*threads;
	pthread_mutex_t	*fork;
}	t_args;

void		exit_func(t_args *t_av, int i);
void		check_args(t_args *t_av, char **av);
int			ft_atoi(char *str);

#endif