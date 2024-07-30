/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:55:20 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/13 16:06:21 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_check(const char format, va_list ap)
{
	int		n_add;

	n_add = 0;
	if (format == 'c')
		n_add += c_process(va_arg(ap, int));
	else if (format == 's')
		n_add += s_process(va_arg(ap, char *));
	else if (format == 'p')
		n_add += p_process(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		n_add += d_i_process(va_arg(ap, int));
	else if (format == 'u')
		n_add += u_process((unsigned long)va_arg(ap, unsigned int));
	else if (format == 'x')
		n_add += x_process(va_arg(ap, unsigned int));
	else if (format == 'X')
		n_add += bigx_process(va_arg(ap, unsigned int));
	else
		n_add = ft_putchar_n(format);
	return (n_add);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;

	n = 0;
	va_start(ap, format);
	if (!format)
		n = -1;
	while (*format)
	{
		if (*format != '%')
			n += ft_putchar_n(*format);
		else
			n += specifier_check(*(++format), ap);
		format++;
	}
	va_end(ap);
	return (n);
}

// #include <stdio.h>
// #include <assert.h>
// int	main(void)
// {
// 	void *p = NULL;
// 	char c = 'i';
// 	char s[] = "haha";
// 	int d = INT_MIN;
// 	unsigned int u = -10;
// 	unsigned int x = 140;
// 	unsigned int X = 140;
// 	// Mixing  output //
// 	ft_printf("Beginning\n c %c\n s %s\n p %p\n d %d\n u %u\n x %x\n 
// 	X %X\n % %\n End\n", c, s, p, d, u, x, X);
// 	// Random asserts //
// 	assert(ft_printf("%p\n", p) == printf("%p\n", p));
// 	assert(ft_printf("%p\n", s) == printf("%p\n", s));
// 	assert(ft_printf("%d\n", INT_MIN) == printf("%d\n", INT_MIN));
// 	assert(ft_printf("%d\n", INT_MIN - 1) == printf("%d\n", INT_MIN - 1));
//	// Check %m and %% //
// int ret = printf("%%");
// printf("%d\n", ret);
// assert(ft_printf("%a") == printf("%a"));
// system("leaks a.out");
// return (0);
// }
