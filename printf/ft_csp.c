/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:04:10 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/13 15:45:56 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_process(int nb)
{	
	unsigned char	uc_ap;

	uc_ap = (unsigned char)nb;
	write(1, &uc_ap, 1);
	return (1);
}

int	s_process(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	p_process(void *ptr)
{
	char	*str;
	int		len;

	str = ft_tolower_all(base_start((unsigned long long)ptr, 16));
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (len + 2);
}
