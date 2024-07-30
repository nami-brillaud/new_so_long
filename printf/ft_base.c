/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:53:57 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/13 15:49:59 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*base_change(unsigned long long ptr_alt, int base, char *str, int dig)
{
	while (ptr_alt != 0)
	{
		if ((ptr_alt % base) < 10)
			str[dig - 1] = (ptr_alt % base) + 48;
		else
			str[dig - 1] = (ptr_alt % base) + 55;
		ptr_alt = ptr_alt / base;
		dig--;
	}
	return (str);
}

char	*base_start(unsigned long long ptr, int base)
{
	unsigned long long	ptr_alt;
	char				*str;
	char				*strdup_save;
	int					digits;

	digits = 0;
	ptr_alt = ptr;
	if (ptr == 0)
	{
		strdup_save = ft_strdup("0");
		if (!strdup_save)
			return (0);
		return (strdup_save);
	}
	while (ptr != 0)
	{
		ptr = ptr / base;
		digits++;
	}
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (0);
	str = base_change(ptr_alt, base, str, digits);
	return (str);
}
