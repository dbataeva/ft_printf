/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchromos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:02:01 by cchromos          #+#    #+#             */
/*   Updated: 2020/12/27 17:02:03 by cchromos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORK_WITH_STRUCT_H
# define WORK_WITH_STRUCT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef struct	s_printf_list
{
	int						flag_minus;
	int						flag_zero;
	int						width;
	int						precision;
	char					char_precision;
	char					type;
	int						length;
	struct s_printf_list	*next;
}				t_printf_list;
int				ft_find_argcs(const char *format, va_list *factor, int count);
int				ft_is_width(const char **format, int *list_width,
va_list *factor);
void			ft_is_flags(const char **format, int *flag_minus,
int *flag_zero);
int				ft_is_type(const char **format, char *type);
int				ft_is_precision(const char **format, int *list_precision,
va_list *factor, char *list_char_precision);
int				ft_format_d_or_i(t_printf_list *list, va_list *factor);
int				ft_print_negativ_number(int number, t_printf_list *list);
void			ft_putnbr_base(int nbr, char *base);
int				ft_format_u(t_printf_list *list, va_list *factor);
int				ft_format_x(t_printf_list *list, va_list *factor);
int				ft_format_big_x(t_printf_list *list, va_list *factor);
int				ft_lengt_x_number(unsigned int number);
void			ft_putnbr_x(unsigned int nbr, char *base);
int				ft_format_c(t_printf_list *list, va_list *factor);
int				ft_format_s(t_printf_list *list, va_list *factor);
int				ft_format_p(t_printf_list *list, va_list *factor);
int				ft_numlen(int nb);
int				ft_format_percent(const char **format, t_printf_list *list,
int length_out);
int				ft_precision_is_bigger_d_or_i(int precision, int i, int number);
int				number_and_precision_is_zero(t_printf_list *list);
int				width_is_bigger_if_zero(t_printf_list *list, int j,
int length_out);
int				ft_numlen_unsigned(unsigned int nb);
int				ft_precision_is_bigger_negativ(t_printf_list *list, int i,
int number);
int				number_is_zero(t_printf_list *list, int length_out, int j);

#endif
