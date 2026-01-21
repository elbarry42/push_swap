/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:04:56 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/21 13:39:43 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_isdigit(int c);
int		ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *ptr);
int		ft_atoi_check(const char *ptr);
int	    count_words(char const *s, char c);
int		call_free(char **array);
int		check_number(char *array);
int		check_data(int argc, char **argv);
int		check_duplicate_number(int *array, char **array_alpha, int *i_array);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*if_and_which_flags(char *str);
char	*check_flags(char **argv, int argc, int *bench);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
//printf
size_t	ft_put_unsigned_int(unsigned int nb);
size_t	ft_print_hexa_low(unsigned long nb);
size_t	ft_print_hexa_up(unsigned int nb);
size_t	ft_print_void_pointer(void *ptr);
size_t	ft_write_a_valor(va_list arguments, int c);
int		ft_is_charset(char c);
int		ft_printf(const char *str, ...);
#endif
