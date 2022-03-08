/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d_or_i_is_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:39:13 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/28 18:39:16 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		flag_minus_is_not_exist_if_d_or_i_is_zero(t_printf_list *list, int j,
int length_out)
{
	if (list->precision)
	{
		while (j--)
			write(1, " ", 1);
		length_out = length_out + list->precision;
		while (list->precision--)
			write(1, "0", 1);
	}
	else if (list->flag_zero == 0)
	{
		while (j--)
			write(1, " ", 1);
		write(1, "0", 1);
		length_out++;
	}
	else
	{
		while (j--)
			write(1, "0", 1);
		write(1, "0", 1);
		length_out++;
	}
	return (length_out);
}

int		width_is_bigger_if_d_or_i_zero(t_printf_list *list, int j,
int length_out)
{
	if ((list->width > 0) && !list->precision)
		j = list->width - 1;
	else
		j = list->width - list->precision;
	length_out = j;
	if (list->flag_minus == 0)
		length_out = flag_minus_is_not_exist_if_d_or_i_is_zero(list, j,
		length_out);
	else if (list->width && list->precision && list->flag_minus)
	{
		length_out = length_out + list->precision;
		while (list->precision--)
			write(1, "0", 1);
		while (j--)
			write(1, " ", 1);
	}
	else
	{
		write(1, "0", 1);
		length_out++;
		while (j--)
			write(1, " ", 1);
	}
	return (length_out);
}

int		number_is_zero(t_printf_list *list, int length_out, int j)
{
	if (list->width && (list->precision == 0) && (list->char_precision == '+'))
	{
		length_out = list->width;
		while (list->width--)
			write(1, " ", 1);
		return (length_out);
	}
	else if ((list->width == 0) && (list->precision == 0) &&
	(list->char_precision == '+'))
		return (0);
	if (list->width > list->precision)
		length_out = width_is_bigger_if_d_or_i_zero(list, j, length_out);
	else if ((list->precision && list->width) ||
	(list->precision > list->width))
	{
		length_out = list->precision;
		while (list->precision--)
			write(1, "0", 1);
	}
	else
	{
		write(1, "0", 1);
		length_out = 1;
	}
	return (length_out);
}
