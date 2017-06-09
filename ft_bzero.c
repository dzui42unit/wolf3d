#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned int	i;
	char			*temp;

	temp = str;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
