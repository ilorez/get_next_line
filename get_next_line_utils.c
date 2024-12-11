/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:00:38 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/11 14:55:00 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
  size_t  i;

	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);

  i = 0;
  while (s1[i])
  {
    dst[i] = s1[i];
    i++;
  }

  dst[i] = '\0';
  //printf("=== STRDUP: returned string: %s\n", dst);
  //printf("=== STRDUP: what should return : %s\n", s1);
	return (dst);
}
