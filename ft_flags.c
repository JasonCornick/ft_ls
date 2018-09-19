/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:50:53 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 17:25:53 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag				*setflags(t_flag *flags)
{
	t_flag			*temp;

	temp = (t_flag*)malloc(sizeof(t_flag));
	temp->a = 0;
	temp->l = 0;
	temp->r = 0;
	temp->t = 0;
	temp->count = 0;
	temp->print = 0;
	flags = temp;
	return (flags);
}

void				norm_flags(int i, int a, char **argv, t_flag *flags)
{
	i++;
	while (argv[a][i] != '\0')
	{
		if (argv[a][i] == 'a')
			flags->a = 1;
		else if (argv[a][i] == 'l')
			flags->l = 1;
		else if (argv[a][i] == 'r')
			flags->r = 1;
		else if (argv[a][i] == 't')
			flags->t = 1;
		i++;
	}
}

int					ab_flags(t_list *temp, int a, char **argv, t_flag *flags)
{
	int				z;

	z = 1;
	while (temp != NULL && z != 2)
	{
		if ((ft_strcmp(argv[a], temp->data.name)) == 0)
		{
			temp->data.display = 1;
			if (temp->data.permisions[0] == 'd')
				temp->data.displaydir = 1;
			flags->count += 1;
			z = 2;
		}
		temp = temp->next;
	}
	return (z);
}

t_flag				*ft_flags(int argc, char **argv, t_list *head)
{
	int				a;
	int				i;
	int				z;
	t_flag			*flags;

	flags = NULL;
	flags = setflags(flags);
	a = 1;
	i = 0;
	z = 0;
	if (argc > 1)
	{
		setdisplay(head, 0);
		while (a < argc)
		{
			if (argv[a][i] == '-' && z == 0)
				norm_flags(i, a, argv, flags);
			else if (argv[a][i] != '-')
				z = ab_flags(head, a, argv, flags);
			a++;
		}
	}
	if (z == 0)
		setdisplay(head, 1);
	return (flags);
}

void				setdisplay(t_list *head, int set)
{
	while (head != NULL)
	{
		head->data.display = set;
		head->data.displaydir = 0;
		head = head->next;
	}
}
