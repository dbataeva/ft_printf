/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:46 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/21 15:15:48 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "work_with_struct.h"

void	ft_putnbr_unsigned_long(unsigned long nbr, char *base)
{
	char	str[14];
	int		i;

	i = 0;
	if (nbr == 0)
		write(1, "0", 1);
	while (nbr > 0)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
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

int		ft_numlen_unsigned_long(unsigned long nb)
{
	int				len;
	unsigned long	copy;

	copy = nb;
	len = 0;
	if (nb == 0)
		len = 1;
	while (copy > 0)
	{
		copy = copy / 16;
		len++;
	}
	return (len);
}

int		ft_width_is_bigger_p(t_printf_list *list, unsigned long number, int i,
int j)
{
	if (list->flag_minus != 0)
	{
		j = list->width - i;
		write(1, "0x", 2);
		ft_putnbr_unsigned_long(number, "0123456789abcdef");
		while (j--)
		{
			write(1, " ", 1);
			i++;
		}
		return (i);
	}
	else
	{
		j = list->width - i;
		while (j--)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, "0x", 2);
		ft_putnbr_unsigned_long(number, "0123456789abcdef");
		return (i);
	}
	return (-1);
}

int		number_is_zero_p(t_printf_list *list, int j, int length_out)
{
	if ((list->char_precision == '-') && (list->width > 2))
		list->width--;
	if (list->width > 1)
		j = list->width - 2;
	if (list->char_precision == '-')
		length_out++;
	length_out = length_out + j;
	if (list->flag_minus != 0)
	{
		write(1, "0x", 2);
		if (list->char_precision == '-')
			write(1, "0", 1);
		while (j--)
			write(1, " ", 1);
	}
	else
	{
		while (j--)
			write(1, " ", 1);
		write(1, "0x", 2);
		if (list->char_precision == '-')
			write(1, "0", 1);
	}
	return (length_out);
}

int		ft_format_p(t_printf_list *list, va_list *factor)
{
	unsigned long	number;
	int				i;
	int				j;
	int				lenght_out;

	j = 0;
	lenght_out = 2;
	number = (unsigned long)va_arg(*factor, void *);
	if (number == 0)
		return (number_is_zero_p(list, j, lenght_out));
	if ((i = ft_numlen_unsigned_long(number) + 2) >= list->width)
	{
		write(1, "0x", 2);
		if (number)
		{
			ft_putnbr_unsigned_long(number, "0123456789abcdef");
			return (i);
		}
		return (2);
	}
	return (ft_width_is_bigger_p(list, number, i, j));
}
