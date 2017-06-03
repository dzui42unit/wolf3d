/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:06:38 by dzui              #+#    #+#             */
/*   Updated: 2016/11/21 13:31:06 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *str, size_t n);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *str, const char *to_find);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *str, int n, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
void				ft_putnbr(int n);
void				*ft_memcpy(void *src, const void *dest, size_t n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
char				*ft_strmapi(const char *s,
								char (*f)(unsigned int index, char ch));
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *ch));
void				ft_striteri(char *s,
								void (*f)(unsigned int index, char *ch));
void				ft_memdel(void **app);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strmap(const char *s, char (*f)(char ch));
char				**ft_strsplit(char const *s, char c);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t n);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strclr(char *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list	**alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_strdel(char **as);
int					ft_isspace(int ch);
int					ft_islower(int ch);
int					ft_isupper(int ch);
char				*ft_capitalize(const char *str);
int					ft_isany(const char *s, int (*f)(int));

#endif
