/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:46 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 17:46:41 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				flag_sort(t_list *head, t_flag *flags)
{
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
}

int					main(int argc, char **argv)
{
	t_list			*head;
	DIR				*dir;
	struct dirent	*sd;
	int				blocks;
	t_flag			*flags;

	dir = opendir(".");
	head = NULL;
	blocks = 0;
	if (dir != NULL)
	{
		while ((sd = readdir(dir)) != NULL)
		{
			head = ft_addnew(head);
			head->data.name = sd->d_name;
			get_file_permisions(head);
			blocks += head->data.blocks;
		}
		flags = ft_flags(argc, argv, head);
		flag_sort(head, flags);
		print(head, blocks, flags);
		free(flags);
	}
	closedir(dir);
	return (0);
}
