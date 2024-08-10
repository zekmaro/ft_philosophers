/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:13:39 by anarama           #+#    #+#             */
/*   Updated: 2024/08/10 18:17:41 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(void *ptr)
{

	free(*(void **)ptr);
	*(void **)ptr = NULL;
}

t_clean	*lst_node_new(void *content, void (*del)(void *))
{
	t_clean	*new;

	if (!content || !del)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->clean = del;
	new->next = NULL;
	return (new);
}

void	lst_node_del(t_clean **lst)
{
	(*lst)->clean((*lst)->content);
	ft_free(&*lst);
}

void	lst_node_del_clean(t_clean **lst, void *mem)
{
	t_clean	*tmp;
	t_clean	*head;

	if (!lst || !*lst)
		return ;
	head = *lst;
	tmp = *lst;
	while ((*lst) && (*lst)->next->content != mem)
		(*lst) = (*lst)->next;
	if (!*lst)
		return ;
	tmp = *lst;
	if ((*lst)->next && (*lst)->next->next)
	{
		tmp = (*lst)->next->next;
		lst_node_del(&(*lst)->next);
		(*lst)->next = tmp;
	}
	else if ((*lst)->next)
		lst_node_del(&(*lst)->next);
	else
		lst_node_del(lst);
	*lst = head;
}

void	lst_list_clean(t_clean **head)
{
	t_clean	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		lst_node_del(head);
		*head = tmp;
	}
	free(*head);
}

int	lst_add_back(t_clean **node, t_clean *new)
{
	t_clean	*tmp;

	if (!new)
	{
		perror("malloc");
		return (0);
	}
	if (*node)
	{
		tmp = *node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*node = new;
	return (1);
}

void	lst_memory(void *mem, void (*del)(void *c), int mode)
{
	static t_clean	*list;
	t_clean			*new;

	if (mode == CLEAN)
		return (lst_list_clean(&list), exit(EXIT_FAILURE));
	if (mode == END)
		return (lst_list_clean(&list));
	if (mode == FREE)
		return (lst_node_del_clean(&list, mem));
	if (!mem)
		return (lst_list_clean(&list), perror("malloc"), exit(EXIT_FAILURE));
	new = lst_node_new(mem, del);
	if (!new)
		return (del(mem), lst_list_clean(&list), \
				print_error("philos: lst_node_malloc"), \
				exit(EXIT_FAILURE));
	lst_add_back(&list, new);
}
