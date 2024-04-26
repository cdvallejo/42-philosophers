/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:43:40 by cvallejo          #+#    #+#             */
/*   Updated: 2024/04/22 18:32:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Inicialización de la estrutura de datos con:
	av[1] 					= number_of_philosophers
	av[2] 					= time_to_die
	av[3] 					= time_to_eat
	av[4] 					= time_to_sleep
	av[5] (opcional)   		= [number_of_times_each_philosopher_must_eat]
	Si sólo hay 4 argumentos, el quinto elemento de char **av es el NULL del
	string, por tanto es una buena solución. La otra manera de controlar esto
	sería introduciendo ac como parámetro. Sea como sea, sin ese dato n_eat se
	inicializa a 0;
	En el caso de que haya 0 filósofos el programa se cierra.
*/
void	ft_init_data(char **av, t_data *data)
{
	data->philo_total = ft_atoi(av[1]);
	if (data->philo_total == 0)
		exit(0);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->eat_total = ft_atoi(av[5]);
}

/*
	Inicialización de la estructura de filósofos. Se inicializa con un bucle
	que recorre el número de filósofos y se les asigna un id.
*/
void	ft_init_philo(t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_total);
	if (!philo)
		exit(0);
	ft_philo_id_forks(data, philo);
}

/*
	Subfunción que inicializa los id de los filósofos y los tenedores.
*/
void	ft_philo_id_forks(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_total)
	{
		philo[i].id = i + 1;
		if ((philo[i].id != 1) && (philo[i].id != data->philo_total))
		{
			philo[i].left_fork = philo[i].id + 1;
			philo[i].right_fork = philo[i].id - 1;
		}
		else if (philo[i].id == data->philo_total)
		{
			philo[i].left_fork = 1;
			philo[i].right_fork = philo[i].id - 1;
		}
		else
		{
			philo[i].left_fork = philo[i].id + 1;
			philo[i].right_fork = data->philo_total;
		}
		i++;
	}
	i = 0;
	while (i < data->philo_total)
	{
		printf("Soy el philo nº %d, mi fork izquierdo es el %d y mi fork derecho el es %d\n ", philo[i].id, philo[i].left_fork,philo[i].right_fork);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_check_args(ac, av);
	ft_init_data(av, &data);
	ft_init_philo(&data);
	return (0);
}
