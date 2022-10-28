#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *p;

    p = *lst;
    while (p->next)
        p = p->next;
    p->next = new;
}