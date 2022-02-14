#include "push_swap.h"

t_list *creat_stack(int argc, char **argv)
{
	t_list	*head;
	t_list	*last;
	int		i;

	i = 1;
	if (argc >= 2)
	{
		last = creat_node(ft_atoi(argv[i++]));
		head = last;
		while (i < argc)
		{
			last->next = creat_node(ft_atoi(argv[i++]));
			last->next->prev = last;
			last = last->next;
		}
		return head;
	}
	return NULL;
}
#include <stdio.h>
void print_stack(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}
void print_strack_rev(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->prev;
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	int *arr;
	int *new_arr;
	int i = 0;

	
	stack_a = creat_stack(argc, argv);
	arr = helper(stack_a);
	new_arr = helper_big(stack_a);

	//sort(&stack_a, &stack_b, 11);
	sort_using_helper(&stack_a, &stack_b);
	sor_last_chunk(&stack_a, &stack_b);
	sor_full_stack(&stack_a, &stack_b);
	// sort_using_helper2(&stack_b, &stack_a);
	// sort_stack(&stack_b, &stack_a);
	// repeat(&stack_a, &stack_b);
	// printf("the smallest : %d \n", get_smaller((stack_a), 100));
	// printf("the index : %d ", index_of(stack_a, get_smaller(stack_a, 100)));
	// sort_parts(&stack_a, &stack_b);
	// //sort_stack(&stack_a, &stack_b);
	// printf("+++++++++\n");
	// print_stack(stack_a);
	// printf("\nhere we print the helpers: \n");
	// while(i < 16)
	// {
	// 	printf("%d : %d\n", i+1, new_arr[i]);
	// 	i++;
	// }
	// printf("1: %d\n", arr[0]);
	// printf("2: %d\n", arr[1]);
	// printf("3: %d\n", arr[2]);
	// printf("4: %d\n", arr[3]);;
	// printf("+++++++++\n");
	// // print_stack(stack_b);
}