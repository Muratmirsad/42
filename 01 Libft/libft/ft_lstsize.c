#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;
    t_list *p;

    i = 1;
    if (!lst)
        return (0);
    while (lst->next)
    {
        i++;
        p = lst->next;
    }
    return (i);
}