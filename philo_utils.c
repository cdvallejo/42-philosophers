/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:43:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/09/07 16:57:28 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Subfunción que controlamos si el caracter es un dígito.
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (-1);
}

/*
	Controlamos si el str es un número y que no tenga signo.
*/
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '\0') || (str[i] == '-' || str[i] == '+'))
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

/*
	Si pasa el chequeo y el parámetro es un número sin signo, lo convertimos
	a int con el clásico ft_atoi.
*/
int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result);
}

/*
	Comprobamos el número de argumentos introducidos válidos
	y se asegura de que son números.
*/
void	ft_check_args(int ac, char **av)
{
	int	i;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (i < ac)
		{
			if (ft_isnumber(av[i]) != 0)
			{
				exit(1);
			}
			i++;
		}
	}
	else
		exit (1);
}
