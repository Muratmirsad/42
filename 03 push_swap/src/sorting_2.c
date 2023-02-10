#include "../include/push_swap.h"

static int	sort_control(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_number(int key, int input1, int input2)
{
	static int	a = 9999;
	static int	b = -10001;
	static int	size_a;
	static int	size_b;

	if (a == 9999 && b == -10001)
	{
		a = (input1 * -1) + 1;
		b = (input2 * -1) + 1;
		size_a = input1;
		size_b = input2;
	}
	if (a == size_a - 2)
		a = (size_a * -1) + 1;
	if (b == size_b - 2)
		b = (size_b * -1) + 1;
	//printf("size_a: %d\nsize_b: %d\n", size_a, size_b);
	if (key == 97)
		return (a++);
	if (key == 98)
		return (b++);
	return (0);
}

static void	handle_req_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	a;
	int	b;

	a = ft_number(97, 0, 0);
	b = ft_number(98, 0, 0);
	if (a < 0 && b < 0)
		ft_rr(stack_a, stack_b, size_a, size_b);
	else if (a >= 0 && b >= 0)
		ft_rrr(stack_a, stack_b, size_a, size_b);
	else
	{
		if (a < 0)
			ft_ra(stack_a, size_a);
		else if (a >= 0)
			ft_rra(stack_a, size_a);
		if (b < 0)
			ft_rb(stack_b, size_b);
		else if (b >= 0)
			ft_rrb(stack_b, size_b);
	}
}

static void	handle_req(int *stack, int size, int key)
{
	int	a;
	int	b;

	if (key == 2)
	{
		a = ft_number(97, 0, 0);
		if (a < 0)
			ft_ra(stack, size);
		else if (a >= 0)
			ft_rra(stack, size);
	}
	else if (key == 1)
	{
		b = ft_number(98, 0, 0);
		if (b < 0)
			ft_rb(stack, size);
		else if (b >= 0)
			ft_rrb(stack, size);
	}	
}

void	sorting_2(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	j = 0;
	int	key;

	i = 0;
	(void)ft_number(0, size_a, size_b);
	while (1)
	{
		key = 0;
		if (stack_a[0] > stack_a[1] && stack_b[0] > stack_b[1])
			ft_ss(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1])
			ft_sa(stack_a);
		else if (stack_b[0] > stack_b[1])
			ft_sb(stack_b);
		if (sort_control(stack_a, size_a) || size_a < 2)
			key += 1;
		if (sort_control(stack_b, size_b) || size_b < 2)
			key += 2;
		if (key == 3)
			break ;
		if (!key)
			handle_req_both(stack_a, stack_b, size_a, size_b);
		else if (key == 2)
			handle_req(stack_a, size_a, key);
		else if (key == 1)
			handle_req(stack_b, size_b, key);
	}
}


/*
static void	handle_req_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
	static int	a = 999;
	static int	b = 1001;

	if (a == 999 && b == 1001)
	{
		a = size_a * -1;
		b = size_b * -1;
	}
	if (a == size_a - 1)
		a = size_a * -1;
	if (b == size_b - 1)
		b = size_b * -1;
	if (a < 0 && b < 0)
		ft_rr(stack_a, stack_b, a, b);
	else if (a >= 0 && b >= 0)
		ft_rrr(stack_a, stack_b, size_a, size_b);
	else
	{
		if (a < 0)
			ft_ra(stack_a, size_a);
		else
			ft_rra(stack_a, size_a);
		if (b < 0)
			ft_rb(stack_b, size_b);
		else
			ft_rrb(stack_b, size_b);
	}
}
*/