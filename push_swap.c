#include "push_swap.h"

int find_smallest(t_list *stack_b)
{
	int smallest;

	if (stack_b != NULL)
		smallest = stack_b->data;
	while (stack_b)
	{
		if (stack_b->data < smallest)
			smallest = stack_b->data;
		stack_b = stack_b->next;
	}
	return smallest;
}


void make_top(t_list **stack, int num)
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


int find_bigest(t_list *stack)
{
	int bigest;

	bigest = 0;
	while (stack)
	{
		if (stack->data > bigest)
			bigest = stack->data;
		stack = stack->next;
	}
	return bigest;
}

int	index_of(t_list *stack_b, int num)
{
	int i;

	i = 1;
	if (stack_b == NULL)
		return -1;
	while (stack_b->data != num && stack_b)
	{
		stack_b = stack_b->next;
		i++;
	}
	return i;
}

#include <stdio.h>
void normal_sort(t_list **stack_b, t_list **stack_a)
{
	int	smallest;

	int top;
	int	index;
	int len;

	smallest = find_smallest(*stack_a);
	while(*stack_a)
	{
		len = list_len(*stack_a);
		smallest = find_smallest(*stack_a);
		index = index_of(*stack_a, smallest);
		if(index <= (len / 2))
		{
			while (smallest != top)
			{	
				rb(stack_a);
				top = (*stack_a)->data;
			}
		}
		else
		{
			while (smallest != top)
			{
				rrb(stack_a);
				top = (*stack_a)->data;
			}
		}
		pb(stack_a, stack_b);
	}
}

void sort_stack(t_list **stack_b, t_list **stack_a)
{
	int bigest;
	int top;
	int	index;
	int len;
	int i = 0;

	while(*stack_b)
	{
		len = list_len(*stack_b);
		bigest = find_bigest(*stack_b);
		index = index_of(*stack_b, bigest);
		if(index <= (len / 2))
		{
			while (bigest != top)
			{	
				rb(stack_b);
				top = (*stack_b)->data;
				i++;
			}
		}
		else
		{
			while (bigest != top)
			{
				//check rrotate function	
				rrb(stack_b);
				top = (*stack_b)->data;
				i++;
			}
		}
		pa(stack_b, stack_a);
	}
}

void sort(t_list **stack_a, t_list **stack_b, int parts)
{
	int len;
	int	iterat;
	int	total;
	int	t;

	len = list_len(*stack_a);
	total = 0;
	t = 0;
	while ((total < len))
	{
		iterat = (len / parts);
		t = iterat;
		while (total <= len && iterat-- > 0)
		{
			pb(stack_a, stack_b);
		}
		iterat = t;
		sort_stack(stack_b, stack_a);
		while (total <= len && iterat-- > 0)
		{
			ra(stack_a);
		}
		total += (len / parts);
	}
}
///// second algo
int	count_total(t_list *stack)
{
	int total;

	total = 0;
	while(stack != NULL)
	{
		total += stack->data;
		stack = stack->next;
	}
	return total;
}

int count_down(t_list *stack, int untile)
{
	int total;
	int	n;

	total = 0;
	n = 0;
	while(stack != NULL)
	{
		if (stack->data <= untile)
		{
			total += stack->data;
			n++;
		}
		stack = stack->next;
	}
	return (total / n);
}

int count_up(t_list *stack, int untile)
{
	int total;
	int	n;

	total = 0;
	n = 0;
	while(stack != NULL)
	{
		if (stack->data >= untile)
		{
			total += stack->data;
			n++;
		}
		stack = stack->next;
	}
	return (total / n);
}

int *helper(t_list *stack)
{
	int total;
	int *arr;
	int average;
	
	total = count_total(stack);
	average = total / list_len(stack);
	arr = (int *)malloc(sizeof(int) * 4);
	arr[0] = count_down(stack, average);
	arr[1] = average;
	arr[2] = count_up(stack, average);
	arr[3] = find_bigest(stack);
	return (arr);
}

// int *helper(t_list *stack)
// {
// 	int total;
// 	int *arr;
// 	int average;
	
// 	total = count_total(stack);
// 	average = total / list_len(stack);
// 	arr = (int *)malloc(sizeof(int) * 5);
// 	arr[0] = count_down(stack, average);
// 	arr[1] = (arr[0] + average) / 2;
// 	arr[2] = average;
// 	arr[4] = find_bigest(stack);
// 	arr[3] = (average + arr[4] / 2);
// 	// arr[2] = count_up(stack, average);
// 	return (arr);
//}
int *helper_big(t_list *stack)
{
	int total;
	int *arr;
	int i = 0;
	int *new_arr, *final_arr, *final1_arr;
	int count = 0;
	int average;
	
	total = count_total(stack);
	average = total / list_len(stack);
	new_arr = (int *)malloc(sizeof(int) * 8);
	final_arr = (int *)malloc(sizeof(int) * 16);
	final1_arr = (int *)malloc(sizeof(int) * 32);
	arr = helper(stack);
	new_arr[count++] = (arr[i] / 2);
	while(count < 8)
	{
		new_arr[count] = arr[i];
		i++;
		count += 2;
	}
	count = 2;
	i = 0;
	while(i < 3)
	{
		new_arr[count] = (arr[i] + arr[i + 1]) / 2;
		count += 2;
		i++;
	}
	count = 0;
	i = 0;
	final_arr[count++] = (new_arr[i] / 2);
	while(count < 16)
	{
		final_arr[count] = new_arr[i];
		i++;
		count += 2;
	}
	count = 2;
	i = 0;
	while(i < 8)
	{
		final_arr[count] = (new_arr[i] + new_arr[i + 1]) / 2;
		count += 2;
		i++;
	}
	
	return (final_arr);
}


int has_smaller(t_list *stack, int num)
{
	int	index;

	index = 1;
	while(stack != NULL)
	{
		if (stack->data <= num)
			return 1;
		// index++;
		stack = stack->next;
	}
	return 0;
}
int get_smaller(t_list *stack, int num)
{
	int	index;
	t_list *start_top;
	t_list *start_bottom;

	start_bottom = stack;
	start_top = stack;
	while (start_bottom->next != NULL)
		start_bottom = start_bottom->next;
	while(start_top != NULL && start_bottom != NULL)
	{
		if (start_top->data <= num)
			return start_top->data;
		else if(start_bottom->data <= num)
			return start_bottom->data;
		start_top = start_top->next;
		start_bottom = start_bottom->prev;
	}
	return 0;
}

void sort_using_helper(t_list **stack_a, t_list **stack_b)
{
	int count;
	// int arr[] = {20, 40, 60, 80, 100};
	int *arr;
	int	index;
	int	len;
	int	smaller;
	int top;
	int smalest;

	count = -1;
	arr = helper_big(*stack_a);
	
	while (++count < 15)
	{
		while(has_smaller(*stack_a, arr[count]))
		{
			len = list_len(*stack_a);
			smaller = get_smaller(*stack_a, arr[count]);
			index = index_of(*stack_a, smaller);
			while(top != smaller)
			{
				if (index <= (len / 2))
					ra(stack_a);
				else
					rra(stack_a);
				top = (*stack_a)->data;
				if (top <= arr[count])
				{
					// printf("smallest is not working");
						// smalest = find_smallest(*stack_b);
						// make_top(stack_b, smalest);
					pb(stack_a, stack_b);
				}
			}
		}
	}
}
// void sort_using_helper(t_list **stack_a, t_list **stack_b)
// {
// 	int count;
// 	int *arr;
// 	int	index;
// 	int	len;
// 	int	smaller;
// 	int top;
// 	int smalest;

// 	count = -1;
// 	arr = helper(*stack_a);
	
// 	while (++count < 2)
// 	{
// 		while(has_smaller(*stack_a, arr[count]))
// 		{
// 			len = list_len(*stack_a);
// 			smaller = get_smaller(*stack_a, arr[count]);
// 			index = index_of(*stack_a, smaller);
// 			while(top != smaller)
// 			{
// 				if (index <= (len / 2))
// 					ra(stack_a);
// 				else
// 					rra(stack_a);
// 				top = (*stack_a)->data;
// 				if (top <= arr[count])
// 				{
// 					// printf("smallest is not working");
// 						smalest = find_smallest(*stack_b);
// 						make_top(stack_b, smalest);
// 					pb(stack_a, stack_b);
// 				}
// 			}
// 		}
// 	}
// }
void sort_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	smallest;

	int top;
	int	index;
	int len;

	smallest = find_smallest(*stack_a);
	while(*stack_a)
	{
		len = list_len(*stack_a);
		smallest = find_smallest(*stack_a);
		index = index_of(*stack_a, smallest);
		if(index <= (len / 2))
		{
			while (smallest != top)
			{	
				ra(stack_a);
				top = (*stack_a)->data;
			}
		}
		else
		{
			while (smallest != top)
			{
				rra(stack_a);
				top = (*stack_a)->data;
			}
		}
		pb(stack_a, stack_b);
	}
}

void sor_last_chunk(t_list **stack_a, t_list **stack_b)
{
	int	smallest;
	while(*stack_a)
	{
		smallest = find_smallest(*stack_a);
		make_top(stack_a, smallest);
		pb(stack_a, stack_b);
	}
}

void sor_full_stack(t_list **stack_a, t_list **stack_b)
{
	int	smallest;
	while(*stack_b)
	{
		smallest = find_bigest(*stack_b);
		make_top(stack_b, smallest);
		pa(stack_b, stack_a);
	}	

}

void sort_parts(t_list **stack_a, t_list **stack_b)
{
	int i;
	int *arr;

	i = 0;
	arr = helper(*stack_a);
	while (i < sizeof(arr))
	{
		while((*stack_b)->data >= arr[i])
			pa(stack_b, stack_a);
		// a function that sort until a sertan number
		printf("i entered here");
		sort_stack_a(stack_a, stack_b);
	}
}



// use the binary to chose the biger number;
int has_bite(t_list *stack, int b_num)
{
	int	index;

	index = 1;
	while(stack != NULL)
	{
		if (stack->data & b_num)
			return 1;
		stack = stack->next;
	}
	return 0;
}

int bite_num(t_list *stack, int b_num)
{
	int	index;
	t_list *start_top;
	t_list *start_bottom;

	start_bottom = stack;
	start_top = stack;
	while (start_bottom->next != NULL)
		start_bottom = start_bottom->next;
	while(start_top != NULL && start_bottom != NULL)
	{
		if (start_top->data & b_num)
			return start_top->data;
		else if(start_bottom->data & b_num)
			return start_bottom->data;
		start_top = start_top->next;
		start_bottom = start_bottom->prev;
	}
	return 0;
}

void radix_sort(stack_t **stack_a, stack_t **stack_b, int b_num)
{
	
}

void sort_using_helper(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	len;
	int	bite;
	int	smaller;
	int top;
	int smalest;

	//loop over every bite.
	//find where to stop.
	while(has_bite(*stack_a, bite))
	{
		len = list_len(*stack_a);
		smaller = bite_num(*stack_a, bite);
		index = index_of(*stack_a, smaller);
		while(top != smaller)
		{
			if (index <= (len / 2))
				ra(stack_a);
			else
				rra(stack_a);
			top = (*stack_a)->data;
			if (top == smaller)
			{
				pb(stack_a, stack_b);
			}
		}
	}
}







