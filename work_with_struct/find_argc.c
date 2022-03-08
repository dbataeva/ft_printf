/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_argc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:12 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:15:14 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int				ft_print(t_printf_list *list, va_list *factor,
const char **format)
{
	if (list->width < 0)
	{
		list->flag_minus++;
		list->width = list->width * -1;
	}
	if ((list->type == 'd') || (list->type == 'i'))
		return (ft_format_d_or_i(list, factor));
	else if (list->type == 'u')
		return (ft_format_u(list, factor));
	else if (list->type == 'x')
		return (ft_format_x(list, factor));
	else if (list->type == 'X')
		return (ft_format_big_x(list, factor));
	else if (list->type == 'c')
		return (ft_format_c(list, factor));
	else if (list->type == 's')
		return (ft_format_s(list, factor));
	else if (list->type == 'p')
		return (ft_format_p(list, factor));
	else if (list->type == '%')
		return (ft_format_percent(format, list, 0));
	return (-1);
}

t_printf_list	*ft_create_elem(void *content)
{
	t_printf_list *elem;

	elem = (struct s_printf_list *)malloc(sizeof(t_printf_list));
	if (!elem)
		return (NULL);
	elem->flag_minus = 0;
	elem->flag_zero = 0;
	elem->width = 0;
	elem->precision = 0;
	elem->char_precision = '-';
	elem->type = '\0';
	elem->length = 0;
	elem->next = NULL;
	(void)content;
	return (elem);
}

int				ft_if_find_percent(const char **format, int *count,
va_list *factor)
{
	t_printf_list	*list;
	int				i;

	if (*(*format) == '%')
	{
		write(1, *format, 1);
		(*format)++;
		return (1);
	}
	if (!(*count) || !(list = ft_create_elem(NULL)))
		return (-1);
	ft_is_flags(format, &list->flag_minus, &list->flag_zero);
	if (((ft_is_width(format, &list->width, factor)) == -1) ||
	((ft_is_precision(format, &list->precision, factor, &list->char_precision))
	== -1) || ((ft_is_type(format, &list->type)) == -1))
	{
		free(list);
		list = NULL;
		return (-1);
	}
	i = ft_print(list, factor, format);
	free(list);
	list = NULL;
	(*count)--;
	return (i);
}

int				ft_find_argcs(const char *format, va_list *factor, int count)
{
	int i;
	int result;
	int final_result;

	i = 0;
	final_result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((result = ft_if_find_percent(&format, &count, factor)) == -1)
				return (-1);
			final_result = final_result + result;
		}
		else if (*format && (*format != '%'))
		{
			write(1, format, 1);
			format++;
			i++;
		}
	}
	return (final_result + i);
}
