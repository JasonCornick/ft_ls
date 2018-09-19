/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:35:45 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 16:46:13 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_a(t_list *head)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

	temp = head;
	temp2 = head;
	while (temp2 != NULL)
	{
		while (temp != NULL)
		{
			if (temp->next &&
					(ft_strcmp(temp->data.name, temp->next->data.name) > 0))
			{
				temp3 = (t_list*)malloc(sizeof(t_list));
				temp3->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp3->data;
				free(temp3);
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
		temp = head;
	}
}

void		sort_ra(t_list *head)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

	temp = head;
	temp2 = head;
	while (temp2 != NULL)
	{
		while (temp != NULL)
		{
			if (temp->next &&
					(ft_strcmp(temp->data.name, temp->next->data.name) < 0))
			{
				temp3 = (t_list*)malloc(sizeof(t_list));
				temp3->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp3->data;
				free(temp3);
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
		temp = head;
	}
}

void		sort_t(t_list *head)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

	temp = head;
	temp2 = head;
	while (temp2 != NULL)
	{
		while (temp != NULL)
		{
			if (temp->next && (temp->data.tno < temp->next->data.tno))
			{
				temp3 = (t_list*)malloc(sizeof(t_list));
				temp3->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp3->data;
				free(temp3);
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
		temp = head;
	}
}

void		sort_rt(t_list *head)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

	temp = head;
	temp2 = head;
	while (temp2 != NULL)
	{
		while (temp != NULL)
		{
			if (temp->next && (temp->data.tno > temp->next->data.tno))
			{
				temp3 = (t_list*)malloc(sizeof(t_list));
				temp3->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp3->data;
				free(temp3);
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
		temp = head;
	}
}
