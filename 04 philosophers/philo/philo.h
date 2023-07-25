/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:42:07 by mdiraga           #+#    #+#             */
/*   Updated: 2023/07/25 19:48:41 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int	nop;
	int	ttd;
	int	tte;
	int	tts;
	int	not;
	int	ar;
}	t_args;

void	exit_func(t_args *t_av, int i);
void	check_args(t_args *t_av, char **av);
int		ft_atoi(char *str);

#endif