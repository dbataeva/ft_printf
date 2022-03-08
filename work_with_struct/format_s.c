/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:56 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:15:57 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		ft_precision_is_exist(t_printf_list *list, char *str, int i, int j)
{
	if (list->width > list->precision)
	{
		j = list->width - list->precision;
		if (!list->flag_minus)
		{
			while (j--)
				write(1, " ", 1);
			write(1, str, list->precision);
		}
		else
		{
			write(1, str, list->precision);
			while (j--)
				write(1, " ", 1);
		}
		return (list->width);
	}
	if (list->precision <= i)
	{
		write(1, str, list->precision);
		return (list->precision);
	}
	write(1, str, i);
	return (i);
}

int		ft_precision_is_not_exist(t_printf_list *list, char *str, int i)
{
	int j;

	if (list->width > i)
	{
		j = list->width - i;
		if (!list->flag_minus)
		{
			while (j--)
				write(1, " ", 1);
			write(1, str, i);
		}
		else
		{
			write(1, str, i);
			while (j--)
				write(1, " ", 1);
		}
		return (list->width);
	}
	write(1, str, i);
	return (i);
}

int		ft_format_s(t_printf_list *list, va_list *factor)
{
	char	*str;
	int		i;
	int		j;

	str = va_arg(*factor, char*);
	if (str == NULL)
		str = "(null)";
	i = ft_strlen(str);
	if (list->precision < 0)
	{
		list->precision = 0;
		list->char_precision = '-';
	}
	j = 0;
	if (list->precision || (list->char_precision == '+'))
	{
		if (list->precision > i)
			list->precision = i;
		return (ft_precision_is_exist(list, str, i, j));
	}
	return (ft_precision_is_not_exist(list, str, i));
}
