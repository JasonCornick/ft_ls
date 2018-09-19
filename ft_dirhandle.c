/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirhandle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:37:38 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 17:38:47 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				dir_sort(t_list *head, t_flag *flags, int blk, char *name)
{
	setdisplay(head, 1);
	if (flags->r != 1)
	{
		sort_a(head);
		if (flags->t == 1)
			sort_t(head);
	}
	else if (flags->r == 1)
	{
		sort_ra(head);
		if (flags->t == 1)
			sort_rt(head);
	}
	if (flags->count > 1)
		ft_printf("%s:\n", name);
	flags->print = 1;
	print(head, blk, flags);
}

int					dirhandle(t_flag *flags, char *name)
{
	char			*str;
	t_list			*head;
	DIR				*dir;
	struct dirent	*sd;
	int				blocks;

	str = ft_strjoin("./", name);
	dir = opendir(str);
	head = NULL;
	blocks = 0;
	if (dir != NULL)
	{
		while ((sd = readdir(dir)) != NULL)
		{
			head = ft_addnew(head);
			head->data.name = ft_strdup(sd->d_name);
			get_file_permisions_two(head, str);
			blocks += head->data.blocks;
		}
		dir_sort(head, flags, blocks, name);
	}
	closedir(dir);
	free(str);
	return (0);
}
