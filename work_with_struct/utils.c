/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:17:08 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:17:12 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		ft_lengt_x_number(unsigned int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number = number / 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_x(unsigned int nbr, char *base)
{
	char	str[12];
	int		i;

	i = 0;
	if (nbr == 0)
		write(1, "0", 1);
	while (nbr > 0)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	str[i] = '\0';
	while (i - 1 >= 0)
	{
		write(1, &str[i - 1], 1);
		i--;
	}
	return ;
}

int		ft_format_percent(const char **format, t_printf_list *list,
int length_out)
{
	length_out = list->width;
	if (list->width == 0)
		write(1, "%", 1);
	else if (list->flag_minus != 0)
	{
		write(1, "%", 1);
		while (--list->width)
			write(1, " ", 1);
	}
	else if ((list->flag_minus == 0) && (list->flag_zero != 0))
	{
		while (--list->width)
			write(1, "0", 1);
		write(1, "%", 1);
	}
	else if ((list->flag_minus == 0) && (list->flag_zero == 0))
	{
		while (--list->width)
			write(1, " ", 1);
		write(1, "%", 1);
	}
	if (**format)
		(*format)++;
	return (length_out);
}

int		ft_precision_is_bigger_d_or_i(int precision, int i, int number)
{
	int j;

	j = 0;
	while (precision > i)
	{
		write(1, "0", 1);
		(precision)--;
		j++;
	}
	ft_putnbr_base(number, "0123456789");
	return (i + j);
}

int		ft_numlen_unsigned(unsigned int nb)
{
	int				len;
	unsigned int	copy;

	copy = nb;
	len = 0;
	if (nb == 0)
		len = 1;
	else if (nb < 0)
	{
		len++;
		copy = copy * -1;
	}
	while (copy > 0)
	{
		copy = copy / 10;
		len++;
	}
	return (len);
}
