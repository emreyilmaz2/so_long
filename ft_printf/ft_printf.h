/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:49:33 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 20:46:24 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define ANSI_RED "\x1b[31m"
# define ANSI_BLUE "\x1b[34m"
# define ANSI_GREEN "\x1b[32m"
# define ANSI_YELLOW "\x1b[33m"
# define ANSI_RESET "\x1b[0m"

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_printstr(char *str);
int		ft_len_hex(unsigned int nbr);
void	ft_put_hex(unsigned int hex, const char format);
int		ft_print_hex(unsigned int hex, const char format);
void	ft_put_ptr(unsigned long long p);
int		ft_ptrlen(unsigned long long p);
int		ft_print_ptr(unsigned long long p);
int		ft_putnbr(long int nbr);
int		ft_printnbr(int nbr);
int		ft_print_unsigned(unsigned int unbr);
void	ft_putstr_color_fd(char *color, char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
#endif
