#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list *rcontent;
    
    rcontent = (t_list *)malloc(sizeof(t_list*));
    if (!rcontent)
        return (0);
    rcontent->content = content;
    rcontent->next = 0;
    return(rcontent);
}