/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_big_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:21 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:15:23 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		flag_minus_is_exist(t_printf_list *list, unsigned int number, int i,
int length_out)
{
	int j;

	if (list->precision > i)
	{
		j = list->precision - i;
		while (j--)
		{
			write(1, "0", 1);
			length_out++;
		}
	}
	ft_putnbr_x(number, "0123456789ABCDEF");
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

int		flag_minus_is_not_exist(t_printf_list *list, int i, int length_out,
int j)
{
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
		while (j--)
		{
			write(1, "0", 1);
			length_out++;
		}
	}
	return (length_out);
}

int		width_is_bigger(t_printf_list *list, unsigned int number, int i)
{
	int length_out;
	int j;

	length_out = 0;
	j = 0;
	if (list->flag_minus)
		length_out = flag_minus_is_exist(list, number, i, length_out);
	else
	{
		if (list->width > i)
		{
			if (list->precision > i)
				j = list->width - list->precision;
			else
				j = list->width - i;
			length_out = flag_minus_is_not_exist(list, i, length_out, j) + j;
		}
		ft_putnbr_x(number, "0123456789ABCDEF");
	}
	return (length_out);
}

int		width_or_precision_big_x(t_printf_list *list, unsigned int number,
int i)
{
	int length_out;
	int j;

	length_out = 0;
	j = 0;
	if (list->width > list->precision)
		length_out = width_is_bigger(list, number, i);
	else
	{
		if (list->precision > i)
			j = list->precision - i;
		while (j--)
		{
			write(1, "0", 1);
			length_out++;
		}
		ft_putnbr_x(number, "0123456789ABCDEF");
	}
	return (length_out + i);
}

int		ft_format_big_x(t_printf_list *list, va_list *factor)
{
	unsigned int	number;
	int				i;

	number = va_arg(*factor, unsigned int);
	i = ft_lengt_x_number(number);
	if ((number == 0) && (list->char_precision == '+') &&
	(list->precision == 0))
		return (number_and_precision_is_zero(list));
	return (width_or_precision_big_x(list, number, i));
}
