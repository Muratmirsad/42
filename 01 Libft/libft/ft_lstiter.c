#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!lst)
        return;
    f(lst->content);
    while (lst->next)
    {
        lst = lst->next;
        f(lst->content);
    }
}