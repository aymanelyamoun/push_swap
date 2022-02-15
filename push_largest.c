#include "push_swap.h"
//////////////////////////////////////////////////////////////////

/////////////////////////// NEW ALGO /////////////////////////////

//////////////////////////////////////////////////////////////////

int has_biger(t_list *stack, int num)
{
	while(stack != NULL)
	{
		if (stack->data >= num)
			return 1;
		stack = stack->next;
	}
	return 0;
}

int get_biger(t_list *stack, int num)
{
	t_list *start_top;
	t_list *start_bottom;

	start_bottom = stack;
	start_top = stack;
	while (start_bottom->next != NULL)
		start_bottom = start_bottom->next;
	while(start_top != NULL && start_bottom != NULL)
	{
		if (start_top->data >= num)
			return start_top->data;
		else if(start_bottom->data >= num)
			return start_bottom->data;
		start_top = start_top->next;
		start_bottom = start_bottom->prev;
	}
	return 0;
}


void make_at_top(t_list **stack, int num)
{
	int index;
	int len;
	int	top;
	
	if (*stack != NULL)
	{
		index = index_of(*stack, num);
		len = list_len(*stack);
		top = (*stack)->data;
		if(index <= (len / 2))
		{
			while (num != top)
			{	
				rb(stack);
				top = (*stack)->data;
			}
		}
		else
		{
			while (num != top)
			{
				rrb(stack);
				top = (*stack)->data;
			}
		}
	}
}

void send_chunck(t_list **stack, t_list **stack_to_push, int more_than)
{
	int	biger;
	int	index;
	int	len;
	int	top;

	while (has_biger(*stack, more_than))
	{
		biger = get_biger(*stack, more_than);
		index = index_of(*stack, biger);
		if (index < len/2)
		{
			while(top != biger)
			{
				ra(stack);
				top = (*stack)->data;
			}
		}
		else
		{
			while(top != biger)
			{
				rra(stack);
				top = (*stack)->data;
			}
		}
		pb(stack, stack_to_push);
	}
}

void sort_sending_biger(t_list **stack_b, t_list **stack_a)
{
	int bigest;

	while((*stack_b) != NULL)
	{
		bigest = find_bigest(*stack_b);
		make_at_top(stack_b, bigest);
		pa(stack_b, stack_a);
		ra(stack_a);
	}
}

void repeat(t_list **stack_a, t_list **stack_b)
{
	int *arr;
	int i = 3;

	arr = helper(*stack_a);
	while(i >= 0)
	{
		send_chunck(stack_a, stack_b, arr[i]);
		sort_sending_biger(stack_b, stack_a);
	}

}

