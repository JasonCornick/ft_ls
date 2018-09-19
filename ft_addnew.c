/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:39:51 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 16:33:43 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_addnew(t_list *head)
{
	t_list	*newtemp;

	newtemp = (t_list*)malloc(sizeof(t_list));
	newtemp->next = head;
	head = newtemp;
	return (head);
}

void	freelist(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	print_long(t_list *head, t_flag *flags)
{
	while (head != NULL)
	{
		if (head->data.name[0] == '.' && flags->a != 1)
			head->data.display = 0;
		else if (head->data.display == 1)
		{
			if (head->data.displaydir == 1)
				dirhandle(flags, head->data.name);
			else
			{
				ft_printf("%s ", head->data.permisions);
				ft_printf("%d\t", head->data.links);
				ft_printf("%s ", head->data.user);
				ft_printf("%s ", head->data.group);
				ft_printf("%d\t", head->data.size);
				ft_printf("%s ", head->data.time);
				ft_printf("%s", head->data.name);
			}
			if (head->next != NULL)
				ft_printf("\n");
		}
		head = head->next;
	}
}

void	print_norm(t_list *head, t_flag *flags)
{
	while (head != NULL)
	{
		if (head->data.name[0] == '.' && flags->a != 1)
			head->data.display = 0;
		else if (head->data.display == 1)
		{
			if (head->data.displaydir == 1)
				dirhandle(flags, head->data.name);
			else
				ft_printf("%s", head->data.name);
			if (head->next != NULL)
				ft_printf("    ");
		}
		head = head->next;
	}
}

void	print(t_list *head, int blocks, t_flag *flags)
{
	if (flags->l == 1)
	{
		if (flags->count == 0 || flags->print == 1)
			ft_printf("total %d\n", blocks);
		print_long(head, flags);
	}
	else if (flags->l != 1)
	{
		print_norm(head, flags);
	}
	freelist(head);
	ft_printf("\n");
}
