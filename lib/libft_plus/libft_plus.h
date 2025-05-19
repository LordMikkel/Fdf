/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_plus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:10:39 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/13 13:47:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PLUS_H
# define LIBFT_PLUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>

// LIBFT

// ----------- Obligatorios (Prototipos) ------------
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t cat_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t cpy_size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

// ------------ Bonus (Listas enlazadas) ------------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// PRINTF

// ------------ Bonus (estructura flags) ------------
typedef struct s_format
{
	int		width;			// Flags '0' y '-' Ancho mínimo (ej: %-10s)
	int		precision;		// Flag '.' Precisión (ej: %.5d)
	int		zero_pad;		// Flag '0' (ej: %05d)
	int		left_align;		// Flag '-' (ej: %-10s)
	int		hash;			// Flag '#' (ej: %#x)
	int		space;			// Flag ' ' (ej: % d)
	int		plus;			// Flag '+' (ej: %+d)
	char	specifier;		// Carácter de conversión (c, s, d, etc.)
}	t_format;

// ------------- Funtion (Principal) ----------------
int		ft_printf(char const *str, ...);

// ----------- Aux. Funtion (flags bonus) ------------
void	ft_apply_flags(char **str, t_format *fmt);
void	ft_apply_hash(char **str, t_format *fmt);
void	ft_apply_left_align(char **str, t_format *fmt);
void	ft_apply_plus(char **str, t_format *fmt);
void	ft_apply_precision(char **str, t_format *fmt);
void	ft_apply_space(char **str, t_format *fmt);
void	ft_apply_zero_pad(char **str, t_format *fmt);
void	ft_apply_min_width(char **str, t_format *fmt);

// ------------ Print Funtion (Utils) ----------------
int		ft_print_char(char c, t_format *fmt);
int		ft_print_str(char *str, t_format *fmt);
int		ft_print_ptr(void *ptr, t_format *fmt);
int		ft_print_num(int n, t_format *fmt);
int		ft_print_unsigned(unsigned int n, t_format *fmt);
int		ft_print_hex(unsigned int n, t_format *fmt, int uppercase);

// ------------ Aux. Funtion (Utils) --------------
char	*ft_itoa_base(long n, char *base);
char	*ft_utoa_base(unsigned long n);

// GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// ------------- Funtion (Principal) --------------
char	*get_next_line(int fd);

#endif
