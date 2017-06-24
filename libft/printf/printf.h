/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:41:13 by mfrankev          #+#    #+#             */
/*   Updated: 2017/02/18 17:12:28 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define J  1
# define Z  2
# define DL 3
# define L  4
# define H  5
# define DH 6

# include <stdarg.h>

# define IS_SIGN ((ident->is_negativ || ident->f_s || ident->f_p) ? 1 : 0)
# define S_OR_O (ident->is_prec ? ' ' : '0')

typedef struct	s_ident
{
	char	f_lj;
	char	f_o;
	char	f_p;
	char	f_s;
	char	f_hash;
	short	min_field;
	char	is_sign;
	char	is_prec;
	short	pr;
	char	modifier;
	char	c;
	char	is_negativ;
}				t_ident;

typedef union	u_number
{
	unsigned char		uc;
	char				c;
	unsigned short int	us;
	short				s;
	int					i;
	unsigned int		ui;
	long int			l;
	unsigned long		ul;
	long long int		ll;
	unsigned long long	ull;
	size_t				sizet;
}				t_number;

int				ft_printf(const char *restrict format, ...);
void			identifier(va_list *args, t_ident *ident);
void			parse_flags(const char **format, t_ident *ident);
void			parse_modifier_conv(const char **format, t_ident *ident);
void			parse_width_prec(const char **format, t_ident *ident, \
								va_list *args);
void			ft_put_llint(long long int nb);
void			ft_put_ullint(unsigned long long int nb);
void			print_d(t_ident *ident, va_list *args);
void			print_unsigned_octal(t_ident *ident, va_list *args, char base);
char			*ft_ultoa(unsigned long int nb, char base);
char			*ft_symbols(char symbol, int count);
void			long_long_int(t_ident *ident, char *str_nb);
void			print_n(t_ident *ident, char *str_nb);
void			print_string(t_ident *ident, char *str);
void			print_p(t_ident *ident, char *str);
void			print_simple_num(t_ident *ident, char *str);
void			forgotten_conv(t_ident *ident, va_list *args);
char			*ft_strtoupper(char *str, t_ident *ident);
void			print_c(t_ident *ident, int letter);
void			ft_symbols_p(char symbol, int count);
void			print_big_c(t_ident *ident, wchar_t letter);
void			parce_prec(t_ident *ident, const char **format, va_list *args);
void			print_num_o(t_ident *ident, char *str);
void			print_unsigned_hexal(t_ident *ident, va_list *args, char base);
void			print_decider2(t_number num, t_ident *ident, va_list *args);
void			parce_conv(const char **f, t_ident *ident);

#endif
