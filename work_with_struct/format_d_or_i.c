/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_or_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:36 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:15:38 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		if_no_flag_minus_d_or_i(t_printf_list *list, int length_out, int i,
int j)
{
	if (list->precision > i)
		j = list->width - list->precision;
	else
		j = list->width - i;
	length_out = j;
	if (((list->char_precision == '-') && !list->flag_zero) || list->precision
	|| ((list->char_precision == '+') && !list->precision))
	{
		while (j--)
			write(1, " ", 1);
	}
	else if ((list->char_precision == '-') && list->flag_zero)
	{
		while (j--)
			write(1, "0", 1);
	}
	if (list->precision > i)
	{
		j = list->precision - i;
		length_out = length_out + j;
		while (j--)
			write(1, "0", 1);
	}
	return (length_out);
}

int		if_flag_minus_d_or_i(t_printf_list *list, int number, int i,
int length_out)
{
	int j;

	j = 0;
	if (list->precision > i)
	{
		j = list->precision - i;
		length_out = j;
		while (j--)
			write(1, "0", 1);
	}
	ft_putnbr_base(number, "0123456789");
	if (list->width > i)
	{
		if (i > list->precision)
			j = list->width - i;
		else
			j = list->width - list->precision;
		while (j--)
		{
			write(1, " ", 1);
			length_out++;
		}
	}
	return (length_out);
}

int		width_or_precision_d_or_i(t_printf_list *list, int number, int i,
int length_out)
{
	int j;

	j = 0;
	if (list->width > list->precision)
	{
		if (list->flag_minus)
			length_out = if_flag_minus_d_or_i(list, number, i, length_out);
		else
		{
			if (list->width > i)
				length_out = if_no_flag_minus_d_or_i(list, length_out, i, j);
			ft_putnbr_base(number, "0123456789");
		}
	}
	else
	{
		if (list->precision > i)
			j = list->precision - i;
		length_out = j;
		while (j--)
			write(1, "0", 1);
		ft_putnbr_base(number, "0123456789");
	}
	return (length_out + i);
}

int		ft_format_d_or_i(t_printf_list *list, va_list *factor)
{
	int number;
	int length_out;
	int i;
	int j;

	length_out = 0;
	j = 0;
	number = va_arg(*factor, int);
	if (number < 0)
	{
		if (!list->precision && (list->char_precision == '+'))
			list->flag_zero = 0;
		return (ft_print_negativ_number(number, list));
	}
	if (number == 0)
		return (number_is_zero(list, length_out, j));
	i = ft_numlen(number);
	return (width_or_precision_d_or_i(list, number, i, length_out));
}
