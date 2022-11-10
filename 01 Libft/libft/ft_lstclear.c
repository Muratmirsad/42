#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *p;

    p = *lst;
    if (!p->content)
        return;
    del(p->content);
    free(p);
    while (p->next)
    {
        p = p->next;
        del(p->content);
        free(p);
    }
}