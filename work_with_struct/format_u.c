/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:16:04 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:16:06 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

void	ft_putnbr_unsigned(unsigned int nbr, char *base)
{
	char	str[12];
	int		i;

	i = 0;
	if (nbr == 0)
		write(1, "0", 1);
	while (nbr > 0)
	{
		str[i] = base[nbr % 10];
		nbr = nbr / 10;
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

int		flag_minus_is_not_exist_u(t_printf_list *list, int i, int length_out,
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

int		flag_minus_is_exist_u(t_printf_list *list, unsigned int number, int i)
{
	int length_out;
	int j;

	length_out = 0;
	j = 0;
	if (list->precision > i)
	{
		j = list->precision - i;
		length_out = j;
		while (j--)
			write(1, "0", 1);
	}
	ft_putnbr_unsigned(number, "0123456789");
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

int		width_or_precision_u(t_printf_list *list, unsigned int number, int i,
int length_out)
{
	int j;

	j = 0;
	if (list->width > list->precision)
	{
		if (list->flag_minus)
			length_out = flag_minus_is_exist_u(list, number, i);
		else
		{
			if (list->width > i)
				length_out = flag_minus_is_not_exist_u(list, i, length_out, j);
			ft_putnbr_unsigned(number, "0123456789");
		}
	}
	else
	{
		if (list->precision > i)
			j = list->precision - i;
		length_out = j;
		while (j--)
			write(1, "0", 1);
		ft_putnbr_unsigned(number, "0123456789");
	}
	return (length_out + i);
}

int		ft_format_u(t_printf_list *list, va_list *factor)
{
	unsigned int	number;
	int				i;
	int				length_out;

	number = va_arg(*factor, unsigned int);
	i = ft_numlen_unsigned(number);
	if ((number == 0) && (list->char_precision == '+') &&
	(list->precision == 0))
		return (number_and_precision_is_zero(list));
	length_out = 0;
	return (width_or_precision_u(list, number, i, length_out));
}
