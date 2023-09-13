/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PHILO.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:05:47 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/25 17:30:23 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

/*
    Struct for data values
*/
typedef struct s_data
{
    int philo_total;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int eat_total;
}				t_data;

/*
    Struct for philosophers values
*/
typedef struct s_philo
{
    int	id;
}				t_philo;

//philo_main.c
void	ft_init_data(char **av, t_data *data);
void	ft_init_philo(t_data *data);

//philo_utils.c
int     ft_isdigit(int c);
int     ft_isnumber(char *str);
int	    ft_atoi(char *str);
void    ft_check_args(int ac, char **av);

#endif