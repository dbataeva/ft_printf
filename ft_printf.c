/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:39:05 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/01 10:51:50 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_format(const char *format, int percent)
{
	while (((*(format + percent) == '-') || (*(format + percent) == '0')) &&
	*(format + percent))
		percent++;
	while (((*(format + percent) >= '0') && (*(format + percent) <= '9')) &&
	*(format + percent))
		percent++;
	if ((*(format + percent) == '*') || (*(format + percent) == '.'))
		percent++;
	if ((*(format + percent) == '*') || (*(format + percent) == '.'))
		percent++;
	if ((*(format + percent) == '*') || (*(format + percent) == '.'))
		percent++;
	while (((*(format + percent) >= '0') && (*(format + percent) <= '9')) &&
	*(format + percent))
		percent++;
	if ((*(format + percent) == 'd') || (*(format + percent) == 'i') ||
	(*(format + percent) == 'u') || (*(format + percent) == 'X') ||
	(*(format + percent) == 'x') || (*(format + percent) == 'c') ||
	(*(format + percent) == 's') || (*(format + percent) == 'p'))
		return (1);
	if ((*(format + percent) == '%'))
		return (2);
	return (0);
}

int		ft_how_much_percents(const char *format)
{
	int count;
	int percent;
	int i;

	count = 0;
	while (*format)
	{
		percent = 0;
		while ((*(format + percent) == '%') && *(format + percent) &&
		(percent < 2))
			percent++;
		if (percent)
		{
			if (((i = ft_check_format(format, percent)) == 2) && i--)
			{
				format++;
				while ((*format) && (*format != '%'))
					format++;
			}
			count = count + i;
		}
		format++;
	}
	return (count);
}

int		ft_how_much_percents_in_str(const char *format)
{
	int count;
	int proc;
	int i;

	i = 0;
	count = 0;
	while (format[i])
	{
		proc = 0;
		while ((format[i] == '%') && format[i])
		{
			proc++;
			i++;
		}
		count = count + proc / 2;
		if (format[i])
			i++;
	}
	return (count);
}

int		ft_num_argcs(const char *format, va_list *factor)
{
	int count;

	count = ft_how_much_percents(format);
	if ((count != -1) && count)
		count = ft_find_argcs(format, factor, count);
	else
	{
		count = ft_strlen(format) - ft_how_much_percents_in_str(format);
		while (*format)
		{
			write(1, format, 1);
			if (*format == '%')
				format++;
			if (*format)
				format++;
		}
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list factor;
	int		i;

	va_start(factor, format);
	if ((i = ft_num_argcs(format, &factor)) == -1)
		return (-1);
	va_end(factor);
	return (i);
}
