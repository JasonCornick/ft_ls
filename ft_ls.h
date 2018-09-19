/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:26:39 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 15:04:34 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "./libft/libft.h"

typedef struct		s_node
{
	char			*name;
	char			permisions[11];
	unsigned int	links;
	char			*user;
	char			*group;
	unsigned int	size;
	int				blocks;
	char			time[13];
	unsigned long	tno;
	int				display;
	int				displaydir;
}					t_node;

typedef struct		s_list
{
	t_node			data;
	struct s_list	*next;
}					t_list;

typedef struct		s_flag
{
	int				a;
	int				l;
	int				t;
	int				r;
	int				count;
	int				print;
}					t_flag;

t_list				*ft_addnew(t_list *head);
void				sort_a(t_list *head);
void				sort_ra(t_list *head);
void				sort_t(t_list *head);
void				sort_rt(t_list *head);
void				print(t_list *head, int blocks, t_flag *flags);
void				get_file_permisions(t_list *head);
void				get_file_permisions_two(t_list *head, char *name);
t_flag				*ft_flags(int argc, char **argv, t_list *head);
void				setdisplay(t_list *head, int set);
int					dirhandle(t_flag *flags, char *name);
void				freelist(t_list *head);

#endif
