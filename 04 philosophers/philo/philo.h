/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:42:07 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/05 16:59:53 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_thread
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notep;
	int				id;
	long long		start_time;
	pthread_mutex_t	*v_fork;
	pthread_mutex_t	*m_dead;
	struct s_philo	*t_av;
	struct s_thread	*next;
}	t_thread;

typedef struct s_philo
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notep;
	int				ar;
	int				any_dead;
	t_thread		*beg;
	t_thread		**tmp_hold;
	pthread_t		*threads;
	pthread_mutex_t	*fork;
}	t_args;

void		exit_func(t_args *t_av, int i);
void		check_args(t_args *t_av, char **av);
void		one_philo(t_args *t_av);
int			ft_atoi(char *str);

#endif