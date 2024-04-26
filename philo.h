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
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

/*
	Struct for data values
*/
typedef struct s_data
{
	int	philo_total;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_total;
}		t_data;

/*
	Struct para los philosophers, con sus id
	Los tenedores izquierdo y derecho son los identificadores de los mutex
*/
typedef struct s_philo
{
	int	id;
	int	eat_count;
	int	left_fork;
	int	right_fork;
}		t_philo;

// philo_main.c
void	ft_init_data(char **av, t_data *data);
void	ft_init_philo(t_data *data);
void	ft_philo_id_forks(t_data *data, t_philo *philo);

// philo_utils.c
int		ft_isdigit(int c);
int		ft_isnumber(char *str);
int		ft_atoi(char *str);
void	ft_check_args(int ac, char **av);

#endif

// Supongamos que tenemos 5 filosofos

// Creamos un array con 5 mutex
array_de_mutex = pthread_mutex[5];

philo[0].left_fork = 0;
philo[0].right_fork = 1;

// Queremos que el philo[0] coja el tenedor 0 y 1
pthread_mutex_lock(&array_de_mutex[philo[0].left_fork]); // == pthread_mutex_lock(&array_de_mutex[0]); == bloquear el tenedor 0
pthread_mutex_lock(&array_de_mutex[philo[0].right_fork]); // == pthread_mutex_lock(&array_de_mutex[1]); == bloquear el tenedor 1