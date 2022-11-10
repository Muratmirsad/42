#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *p;

    while (lst->next)
        p = lst->next;
	return (p);
}