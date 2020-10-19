#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *dst;

	dst = malloc(sizeof(t_list));
	if (dst)
	{
		dst->content = content;
		dst->next = NULL;
	}
	else
		return (NULL);
	return (dst);
}
