/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:54:41 by nfujisak          #+#    #+#             */
/*   Updated: 2024/06/26 16:27:00 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

/* ft_base.c */
char	*base_change(unsigned long long ptr_alt, int base, char *str, int dig);
char	*base_start(unsigned long long ptr, int base);

/* ft_csp.c */
int		c_process(int nb);
int		s_process(char *str);
int		p_process(void *ptr);

/* ft_diux.c */
int		d_i_process(int nb);
int		u_process(unsigned int nb);
int		x_process(unsigned int nb);
int		bigx_process(unsigned int nb);

/* ft_helpers.c */
int		ft_putchar_n(char c);
char	*ft_tolower_all(char *str);
char	*ft_toupper_all(char *str);

/* ft_printf.c */
int		specifier_check(const char format, va_list ap);
int		ft_printf(const char *format, ...);

#endif