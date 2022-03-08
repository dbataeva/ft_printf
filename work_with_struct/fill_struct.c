/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:03 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:15:06 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		ft_precision_is_string(const char **format, int *list_precision,
char *list_char_precision)
{
	char	*precision;
	int		i;

	i = 0;
	while ((*(*format + i) >= '0') && (*(*format + i) <= '9'))
		i++;
	if (!(precision = ft_calloc((i + 1), 1)))
		return (-1);
	precision = ft_memcpy(precision, *format, i);
	*list_precision = ft_atoi(precision);
	*list_char_precision = '+';
	free(precision);
	precision = NULL;
	*format = *format + i;
	return (0);
}

int		ft_is_precision(const char **format, int *list_precision,
va_list *factor, char *list_char_precision)
{
	if (**format == '.')
	{
		*list_char_precision = '+';
		(*format)++;
		if (**format == '*')
		{
			*list_precision = va_arg(*factor, int);
			if (*list_precision < 0)
			{
				*list_precision = 0;
				*list_char_precision = '-';
			}
			(*format)++;
		}
		else if ((**format >= '0') && (**format <= '9'))
		{
			if (ft_precision_is_string(format, list_precision,
			list_char_precision) == -1)
				return (-1);
		}
	}
	return (0);
}

int		ft_is_type(const char **format, char *type)
{
	if ((**format == 'd') || (**format == 'i') || (**format == 'u') ||
	(**format == 'x') || (**format == 'X') || (**format == 'c') ||
	(**format == 'p') || (**format == 's') || (**format == '%'))
	{
		*type = **format;
		(*format)++;
		return (0);
	}
	return (-1);
}

void	ft_is_flags(const char **format, int *flag_minus, int *flag_zero)
{
	if ((**format == '-') || (**format == '0'))
	{
		while ((**format == '-') || (**format == '0'))
		{
			if (**format == '-')
			{
				(*flag_minus)++;
				(*format)++;
			}
			if (**format == '0')
			{
				(*flag_zero)++;
				(*format)++;
			}
		}
	}
	return ;
}

int		ft_is_width(const char **format, int *list_width, va_list *factor)
{
	int		i;
	char	*width;

	i = 0;
	if ((**format == '*') || ((**format >= '0') && (**format <= '9')))
	{
		if (**format == '*')
		{
			*list_width = va_arg(*factor, int);
			(*format)++;
		}
		else
		{
			while ((*(*format + i) >= '0') && (*(*format + i) <= '9'))
				i++;
			if (!(width = ft_calloc((i + 1), 1)))
				return (-1);
			width = ft_memcpy(width, *format, i);
			*list_width = ft_atoi(width);
			free(width);
			width = NULL;
			*format = *format + i;
		}
	}
	return (0);
}
