#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!lst)
        return (0);
    f(lst->content);
    while (lst->next)
    {
        lst = lst->next;
        f(lst->content);
    }
}