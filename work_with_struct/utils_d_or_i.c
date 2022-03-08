/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d_or_i_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:46:43 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/27 16:46:45 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		flag_minus_is_not_exist_if_zero(t_printf_list *list, int j,
int length_out)
{
	if (list->width == 0)
		return (length_out);
	if (list->precision > 0)
		j = list->width - list->precision;
	else
		j = list->width;
	length_out = j;
	while (j--)
		write(1, " ", 1);
	if (list->precision > 0)
	{
		j = list->precision;
		length_out = length_out + j;
		while (j--)
			write(1, "0", 1);
	}
	return (length_out);
}

int		width_is_bigger_if_zero(t_printf_list *list, int j, int length_out)
{
	if (list->flag_minus)
	{
		if (list->precision > 0)
		{
			j = list->precision;
			length_out = j;
			while (j--)
				write(1, "0", 1);
		}
		if (list->width > 0)
		{
			j = list->width - list->precision;
			while (j--)
			{
				write(1, " ", 1);
				length_out++;
			}
		}
	}
	else
		length_out = flag_minus_is_not_exist_if_zero(list, j, length_out);
	return (length_out);
}

int		number_and_precision_is_zero(t_printf_list *list)
{
	int length_out;
	int j;

	j = 0;
	length_out = 0;
	if (list->width > list->precision)
		length_out = width_is_bigger_if_zero(list, j, length_out);
	else
	{
		if (list->precision > 0)
			j = list->precision;
		length_out = j;
		while (j--)
			write(1, "0", 1);
	}
	return (length_out);
}

int		ft_numlen(int nb)
{
	int len;
	int copy;

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

int		ft_precision_is_bigger_negativ(t_printf_list *list, int i, int number)
{
	int length_out;

	write(1, "-", 1);
	length_out = 0;
	number = number * -1;
	if (i - 1 >= list->precision)
	{
		ft_putnbr_base(number, "0123456789");
		return (length_out + i);
	}
	while (list->precision > (i - 1))
	{
		write(1, "0", 1);
		list->precision--;
		length_out++;
	}
	ft_putnbr_base(number, "0123456789");
	return (length_out + i);
}
