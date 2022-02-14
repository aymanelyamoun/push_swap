#include "push_swap.h"

t_list *creat_node(int n)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	new->data = n;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

int	list_len(t_list *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return i;
}
void one_elm(t_list **from, t_list **to)
{
	t_list *tmp;

	tmp = *from;
	*from = NULL;
	if (list_len(*to) == 0)
	{
		*to = tmp;
		(*to)->next = NULL;
	}
	else
	{
		(*to)->prev = tmp;
		tmp->next = *to;
		*to = tmp;
	}
}

void	list_is_safe(t_list **from, t_list **to)
{
	t_list *tmp;

	tmp = *from;
	*from = (*from)->next;
	(*from)->prev = NULL;
	if (list_len(*to) == 0)
	{
		*to = tmp;
		(*to)->next = NULL;
	}
	else
	{
		(*to)->prev = tmp;
		tmp->next = *to;
		*to = tmp;
	}
}
//++++++++++++++++++++++++++++++++++//push


int	push(t_list **from, t_list **to)
{
	t_list	*tmp;
	int		len;

	len = list_len(*from);
	if (len < 1)
		return 0;
	else if (len == 1)
		one_elm(from, to);
	else
	{
		list_is_safe(from, to);
	}
	return 1;
}

void	pa(t_list **from, t_list **to)
{
	if (push(from, to))
		write(1, "pa\n", 3);
}

void	pb(t_list **from, t_list **to)
{
	if (push(from, to))
		write(1, "pb\n", 3);
}


//+++++++++++++++++++++++++++++++++++//swap first two


int	swap_first_two(t_list **stack)
{
	int	tmp;

	if (list_len(*stack) <= 2)
		return 0;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	return 1;
}

void sa(t_list **stack)
{
	if (swap_first_two(stack))
		write(1, "sa\n", 3);
}

void sb(t_list **stack)
{
	if (swap_first_two(stack))
		write(1, "sb\n", 3);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	int check1;
	int check2;

	check1 = swap_first_two(stack_a);
	check2 = swap_first_two(stack_b);
	if (check1 && check2)
		write(1, "ss\n", 3);
	else if (check1)
		write(1, "sa\n", 3);
	else if (check2)
		write(1, "sb\n", 3);
}


//++++++++++++++++++++++++++++//rotate


int	rotate(t_list **stack)
{
	t_list *tmp;
	t_list *elm;

	tmp = *stack;
	elm = *stack;
	if (list_len(*stack) <= 1)
		return 0;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elm;
	elm->next = NULL;
	elm->prev = tmp;
	return 1;
}

void ra(t_list **stack_a)
{
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void rb(t_list **stack_b)
{
	if (rotate(stack_b))
		write(1, "rb\n", 3);
}

void rr(t_list **stack_a, t_list **stack_b)
{
	int	check1;
	int	check2;

	check1 = rotate(stack_a);
	check2 = rotate(stack_b);
	if (check1 && check2)
		write(1, "rr\n", 3);
	else if (check1)
		write(1, "ra\n", 3);
	else if (check2)
		write(1, "rb\n", 3);
}


//+++++++++++++++++++++++++++++//rrotate


int	rrotate(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	if (list_len(*stack) <= 1)
		return 0;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
	return 1;
}

void rra(t_list **stack_a)
{
	if (rrotate(stack_a))
		write(1, "rra\n", 4);
}

void rrb(t_list **stack_b)
{
	if (rrotate(stack_b))
		write(1, "rrb\n", 4);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	int	check1;
	int	check2;

	check1 = rrotate(stack_a);
	check2 = rrotate(stack_b);
	if (check1 && check2)
		write(1, "rrr\n", 4);
	else if (check1)
		write(1, "rra\n", 4);
	else if (check2)
		write(1, "rrb\n", 4);
}















