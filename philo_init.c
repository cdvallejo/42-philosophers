/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:39:26 by cvallejo          #+#    #+#             */
/*   Updated: 2024/05/01 16:58:57 by cvallejo         ###   ########.fr       */
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
	ft_mutex_init(data);
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
		if (philo[i].id != data->philo_total)
		{
			philo[i].left_fork = philo[i].id + 1;
			philo[i].right_fork = philo[i].id;
		}
		else
		{
			philo[i].left_fork = philo[0].id;
			philo[i].right_fork = philo[i].id;
		}
		i++;
	}
	/*
	i = 0;
	while (i < data->philo_total)
	{
		printf("Soy el philo nº %d, mi fork izquierdo es el
			%d y mi fork derecho el es %d\n ", philo[i].id, philo[i].left_fork,
			philo[i].right_fork);
		i++;
	}*/
}

/* Iniciamos el array de mutex y lo asignamos a un hilo de mutex con la
función pthrad_mutex_init */
void	ft_mutex_init(t_data *data)
{
	pthread_mutex_t	*mutex_array;
	int				i;

	mutex_array = malloc(sizeof(pthread_mutex_init) * data->philo_total);
	i = 0;
	while (i < data->philo_total)
	{
		if (pthread_mutex_init(&mutex_array[i], NULL) != 0)
		{
			free(mutex_array);
			return ;
		}
		printf("Mutex %d inicializado correctamente\n", i + 1);
		i++;
	}
}
