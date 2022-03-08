/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:45:39 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/27 16:45:42 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_check_base(char *b)
{
	int i;

	i = 0;
	while ((b[i] == '0') || (b[i] == '1'))
		i++;
	if (b[i] == '\0')
		return (2);
	i = 0;
	while ((b[i] >= '0') && (b[i] <= '9'))
		i++;
	if (b[i] == '\0')
		return (10);
	i = 0;
	while (((b[i] >= '0') && (b[i] <= '9')) || ((b[i] >= 'A') && (b[i] <= 'F')))
		i++;
	if (b[i] == '\0')
		return (16);
	return (1);
}

void	ft_print_nbr(int nb, char *base, int check)
{
	int		i;
	char	str[12];

	i = 0;
	while (nb > 0)
	{
		str[i] = base[nb % check];
		nb = nb / check;
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

void	ft_putnbr(int nb, int check)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb == 0)
		write(1, "0", 1);
	else if (check == 2)
		ft_print_nbr(nb, "01", check);
	else if (check == 10)
		ft_print_nbr(nb, "0123456789", check);
	else if (check == 16)
		ft_print_nbr(nb, "123456789ABCDEF", check);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int check;
	int i;

	i = 0;
	check = ft_check_base(base);
	if (check == 1)
		return ;
	if ((check == 2) && (nbr == -2147483648))
		write(1, "10000000000000000000000000000000", 32);
	else if ((check == 10) && (nbr == -2147483648))
		write(1, "-2147483648", 11);
	else
		ft_putnbr(nbr, check);
	return ;
}
