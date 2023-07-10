/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:34:42 by jperinch          #+#    #+#             */
/*   Updated: 2023/07/10 09:58:55 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0') && i < (n - 1))
	{
		i++;
	}
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
// int	main(void)
// {
// 	char str[] = "hellowt";
// 	char str1[] = "hellow";
// 	printf("%d\n", strncmp(str, str1, 7));
// 	printf("%d\n", ft_strncmp(str, str1, 7));
// 	//printf("%s:", str);
// 	//printf("\n%d",ft_memset('s'));
// }