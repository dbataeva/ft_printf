/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:28 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:15:30 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

int		ft_format_c(t_printf_list *list, va_list *factor)
{
	char	c;
	int		length_out;

	c = va_arg(*factor, int);
	length_out = 0;
	if (list->width > 1)
	{
		length_out = list->width;
		if (list->flag_minus == 0)
		{
			while (--list->width)
				write(1, " ", 1);
			write(1, &c, 1);
		}
		else
		{
			write(1, &c, 1);
			while (--list->width)
				write(1, " ", 1);
		}
	}
	else
		write(1, &c, 1);
	return (length_out ? length_out : 1);
}
