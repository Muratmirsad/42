/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:42:07 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/08 20:59:34 by mdiraga          ###   ########.fr       */
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
	long long		last;
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
void		t_av_init_helper(t_args *t_av);
int			any_dead_check(t_thread *t_one);
void		*dead_func(t_thread *t_one, long long a);
void		ft_eating(t_thread *t_one);
void		ft_sleeping(t_thread *t_one);
void		ft_thinking(t_thread *t_one);
int			ft_atoi(char *str);
int			ft_isdigit(int a);


#endif