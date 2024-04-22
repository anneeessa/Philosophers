/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmohamm <anmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:04:04 by anmohamm          #+#    #+#             */
/*   Updated: 2024/02/03 19:13:38 by anmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || 32 == c);
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Feed me only positive values");
	if (!is_digit(*str))
		error_exit("The input contains incorrect value");
	number = str;
	while (is_digit(*str++))
		++len;
	--str;
	if (!is_digit(*str) && (*str != '\0'))
		error_exit("The input contains incorrect value");
	if (len > 10)
		error_exit("The value is too big, INT_MAX is the limit");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
	{
		num = (num * 10) + (*str++ - '0');
	}
	if (num > INT_MAX)
		error_exit("INT_MAX is the limit");
	return (num);
}

void	parse_input(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(av[1]);
	if (table->philo_nbr > PHILO_MAX)
	{
		printf("Max philos are %d\n"
			"make fclean and re-make with PHILO_MAX=nbr to change it\n",
			PHILO_MAX);
		exit(EXIT_FAILURE);
	}
	if (table->philo_nbr < 1)
		error_exit("Error. Give atleast 1 philosopher");
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (table->time_to_die < 6e4
		|| table->time_to_sleep < 6e4
		|| table->time_to_eat < 6e4)
		error_exit("Use timestamps major than 60ms");
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
}
