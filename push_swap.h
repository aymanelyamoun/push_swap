#include <stdlib.h>
#include <unistd.h>
struct s_list
{
	int	data;
	struct s_list	*next;
	struct s_list	*prev;
};

typedef struct s_list t_list;


t_list	*creat_node(int n);
int		list_len(t_list *head);
void	one_elm(t_list **from, t_list **to);
void	list_is_safe(t_list **from, t_list **to);
int		push(t_list **from, t_list **to);
void	pa(t_list **from, t_list **to);
void	pb(t_list **from, t_list **to);
int		swap_first_two(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
int		rrotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		ft_atoi(const char *str);
t_list	*creat_stack(int argc, char **argv);
int find_bigest(t_list *stack_b);
void sort_stack(t_list **stack_b, t_list **stack_a);
void sort(t_list **stack_a, t_list **stack_b, int parts);
void normal_sort(t_list **stack_b, t_list **stack_a);
int find_smallest(t_list *stack_b);
int	count_total(t_list *stack);
int count_down(t_list *stack, int untile);
int count_up(t_list *stack, int untile);
int *helper(t_list *stack);
int has_smaller(t_list *stack, int num);
int get_smaller(t_list *stack, int num);
void sort_using_helper(t_list **stack_a, t_list **stack_b);
void sort_stack_a(t_list **stack_a, t_list **stack_b);
void sort_parts(t_list **stack_a, t_list **stack_b);
int *helper_big(t_list *stack);
void sort_using_helper2(t_list **stack_a, t_list **stack_b);
int	index_of(t_list *stack_b, int num);
///////////// NEW ALGO ////////////
void repeat(t_list **stack_a, t_list **stack_b);
void sort_sending_biger(t_list **stack_b, t_list **stack_a);
void send_chunck(t_list **stack, t_list **stack_to_push, int more_than);
void make_at_top(t_list **stack, int num);
int has_biger(t_list *stack, int num);
int get_biger(t_list *stack, int num);
void sor_last_chunk(t_list **stack_a, t_list **stack_b);
void sor_full_stack(t_list **stack_a, t_list **stack_b);
int has_bite(t_list *stack, int b_num);
int bite_num(t_list *stack, int b_num);
void push_all_to_a(t_list **stack_a,t_list **stack_b);
void sort_using_radix(t_list **stack_a, t_list **stack_b);