#include "libft.h"

int	main()
{
	t_list *test1;
	t_list *test2;

	

	test1->content = ft_strdup("murat");
	test2->content = ft_strdup("deneme");
	

	t_list **p;
	*p = test1;

	ft_lstadd_front(p, test2);

	printf("%s", *p);

	return (0);
}