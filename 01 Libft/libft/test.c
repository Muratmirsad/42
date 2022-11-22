#include "libft.h"

int	main()
{
	t_list *lst;
	t_list *lp;

	char *str;
	char *str2;


	lst = malloc(sizeof(t_list));
	lp = malloc(sizeof(t_list));

	str = ft_strdup("deneme");
	str2 = ft_strdup("den2243");

	lst = ft_lstnew(str);
	lp = ft_lstnew(str2);
	ft_lstadd_front(&lst, lp);
	
	printf("%s", lst->content);
	return (0);
}