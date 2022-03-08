/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negativ_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:16:29 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:16:31 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		util_minus_2147483648(t_printf_list *list, int length_out)
{
	write(1, "-", 1);
	if (10 >= list->precision)
	{
		write(1, "2147483648", 10);
		return (length_out);
	}
	if (10 < list->precision)
	{
		while (10 < list->precision--)
		{
			write(1, "0", 1);
			length_out++;
		}
		write(1, "2147483648", 10);
	}
	return (length_out);
}

int		flag_minus_is_not_exist_minus_2147483648(t_printf_list *list,
int length_out, int j)
{
	if ((list->flag_zero == 0) || list->precision)
	{
		while (j--)
			write(1, " ", 1);
		length_out = util_minus_2147483648(list, length_out);
	}
	else
	{
		write(1, "-", 1);
		while (j--)
			write(1, "0", 1);
		while (11 < list->precision)
		{
			write(1, "0", 1);
			length_out++;
		}
		write(1, "2147483648", 10);
	}
	return (length_out);
}

int		ft_number_is_minus_2147483648(t_printf_list *list, int length_out)
{
	int j;

	j = 0;
	if (list->width > list->precision)
	{
		if (list->precision >= 10)
			j = list->width - list->precision - 1;
		else if (list->width > 10)
			j = list->width - 10;
	}
	length_out = j + 11;
	if (list->flag_minus == 0)
		length_out = flag_minus_is_not_exist_minus_2147483648(list, length_out,
		j);
	else
	{
		length_out = util_minus_2147483648(list, length_out);
		while (j--)
			write(1, " ", 1);
	}
	return (length_out);
}

int		ft_width_is_bigger_negativ(t_printf_list *list, int i, int number,
int j)
{
	if (list->flag_minus == 0)
	{
		if ((list->flag_zero == 0) || list->precision)
		{
			while (j--)
				write(1, " ", 1);
			i = ft_precision_is_bigger_negativ(list, i, number);
		}
		else
		{
			write(1, "-", 1);
			while (j--)
				write(1, "0", 1);
			i = ft_precision_is_bigger_d_or_i(list->precision, i,
			(number * -1));
		}
	}
	else
	{
		i = ft_precision_is_bigger_negativ(list, i, number);
		while (j--)
			write(1, " ", 1);
	}
	return (i);
}

int		ft_print_negativ_number(int number, t_printf_list *list)
{
	int i;
	int j;
	int length_out;

	length_out = 0;
	if (number == -2147483648)
		return (ft_number_is_minus_2147483648(list, length_out));
	if ((((i = ft_numlen(number)) - 1) >= list->precision) &&
	(i >= list->width))
	{
		ft_putnbr_base(number, "0123456789");
		return (i);
	}
	else if ((list->precision > i - 1) && (list->precision >= list->width))
		return (ft_precision_is_bigger_negativ(list, i, number));
	else if (list->width > list->precision)
	{
		if (list->precision >= (i - 1))
			j = list->width - list->precision - 1;
		else
			j = list->width - i;
		length_out = j;
		return (ft_width_is_bigger_negativ(list, i, number, j) + length_out);
	}
	return (-1);
}
