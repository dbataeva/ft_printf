/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:16:12 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:16:20 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		flag_minus_is_not_exist_x(t_printf_list *list, int i, int length_out,
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

int		flag_minus_is_exist_x(t_printf_list *list, unsigned int number, int i,
int j)
{
	int length_out;

	length_out = 0;
	if (list->precision > i)
	{
		j = list->precision - i;
		length_out = j;
		while (j--)
			write(1, "0", 1);
	}
	ft_putnbr_x(number, "0123456789abcdef");
	if (list->width > i)
	{
		if (i > list->precision)
			j = list->width - i;
		else
			j = list->width - list->precision;
		length_out = length_out + j;
		while (j--)
			write(1, " ", 1);
	}
	return (length_out);
}

int		width_or_precision_x(t_printf_list *list, unsigned int number, int i,
int length_out)
{
	int j;

	j = 0;
	if (list->width > list->precision)
	{
		if (list->flag_minus)
			length_out = flag_minus_is_exist_x(list, number, i, j);
		else
		{
			if (list->width > i)
				length_out = flag_minus_is_not_exist_x(list, i, length_out, j);
			ft_putnbr_x(number, "0123456789abcdef");
		}
	}
	else
	{
		if (list->precision > i)
			j = list->precision - i;
		length_out = j;
		while (j--)
			write(1, "0", 1);
		ft_putnbr_x(number, "0123456789abcdef");
	}
	return (length_out + i);
}

int		ft_format_x(t_printf_list *list, va_list *factor)
{
	unsigned int	number;
	int				i;
	int				length_out;

	number = va_arg(*factor, unsigned int);
	i = ft_lengt_x_number(number);
	if ((number == 0) && (list->char_precision == '+') &&
	(list->precision == 0))
		return (number_and_precision_is_zero(list));
	length_out = 0;
	return (width_or_precision_x(list, number, i, length_out));
}
