#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define INT32_MAX 2147483647
# define INT32_MIN (-INT32_MAX-1)

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int				fl (char c, unsigned long d);
void			*ft_calloc(size_t n, size_t s);
int				ft_count (int d);
int				ft_count_argv (char **argv);
int			  	ft_hex (unsigned long n, int registr);
int				ft_hex_length (unsigned long n);
int				ft_hub_int (char c, int d);
int				ft_is_sorted (int *a, int n);
int				ft_isdigit (char *s);
int				ft_nearest (int *a, int middle);
int				ft_minus_first(int *a);
void			ft_move_four(int **stack);
void 			ft_move_to_a(int **stack, int i);
void			ft_move_to_a_and_sort(int **stack, int i);
char			*ft_pa (int **stack);
char			*ft_pb (int **stack);
int				ft_plus_first(int *a, int n);
int				ft_print_p (unsigned long p);
int				ft_print_sign (int n);
int				ft_print_stack(int **stack);
int				ft_printf (const char *input, ...);
int				ft_putchar (int n);
int				ft_putnbr_fd (unsigned int n);
int				ft_putpercent(char c);
int				ft_putstr_fd (char *s, int fd);
char			*ft_ra (int **stack);
char			*ft_rb (int **stack);
int				ft_replace (int **stack);
char			*ft_rr (int **stack);
char			*ft_rra (int **stack);
char			*ft_rrb (int **stack);
char			*ft_rrr (int **stack);
char			*ft_sa (int **stack);
char			*ft_sb (int **stack);
int				ft_sort (int **stack);
void			ft_sort_a(int **stack, int i);
int				ft_sort_four(int **stack);
int				ft_sort_many_add(int **stack);
int             ft_sort_many(int **stack);
void            ft_sort_rem(int **stack, int j);
int				ft_sort_three (int **stack);
int				ft_sort_two (int **stack);
int				ft_split_atoi(int *a, char *str);
char			*ft_ss (int **stack);
char			*ft_strjoin (char *s1, char* s2);
size_t			ft_strlen (const char *str);
void			ft_write_hex (unsigned long d, int registr);

#endif