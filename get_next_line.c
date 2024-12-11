/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:00:19 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/11 11:01:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// join two strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
  size_t i = 0;
	size_t	size;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (ft_strdup(""));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(size);
	if (!dst)
		return (NULL);
  i = 0;
  while (*s1)
    dst[i++] = *s1++;
  while (*s2)
    dst[i++] = *s2++;
  dist[i] = '\0';
  // print s1 and s2 and dst
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  printf("dst: %s\n", dst);
	return (dst);
}

char	*ft_sublen(char const *s,size_t len)
{
	size_t	size;
	char	*ss;

	ss = (char *)malloc(len * sizeof(char) + 1);
	if (!ss)
		return (NULL);
  while (len--)
    *ss++ = *s++;
  *ss = '\0';
	return (ss);
}

static void _cut_line(char **c_point, char **line)
{
  size_t  i;
  char *tmp;

  i = 0;
  while ((*c_point)[i] && (*c_point)[i] != '\n')
    i++;
  if (!(*c_point)[i])
  {
    *line = ft_strdup(*c_point);
    free(*c_point);
    **c_point = NULL;
  }
  *line = (ft_sublen(*c_point, i+1));
  tmp = c_point;
  *c_point = ft_strdup(&(*c_point)[i+1]);
  free(tmp);
}

// search in string to find \n
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

  if(!s)
    return (NULL);
	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] != (char)c)
		return (NULL);
	return ((char *)(&(s[i])));
}

static char* _search_for_line(int fd, char *c_point,char *buffer)
{
  ssize_t readed;
  char *tmp;
  char *found_line;

  found_line = NULL;
  while (!found_line)
  {
    readed = read(fd, buffer, BUFFER_SIZE);
    // end of file
    if (readed == 0)
      break;
    // error
    //if (readed <  0)
    buffer[readed] = '\0';
    found_line = ft_strchr(buffer, '\n'))
    tmp = c_point;
    c_point = ft_strjoin(c_point, buffer);
    free(tmp);
  }
  return (c_point);
}

char *get_next_line(int fd)
{
  static char *c_point;
  char *line;
  char *buffer;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  buffer = malloc(BUFFER_SIZE + 1);
  if (!buffer)
    return (NULL);
  // this function read from fd file untel found "\n" or EOF
  c_point = _search_for_line(fd, c_point, buffer);
  if (c_point == NULL)
  {
    free(buffer);
    return NULL;
  }
  // this fucntion extract the line from the readed value
  // and update update c_point by removing the line that we read
  // so best for funciton is get_line_update_c_point
  // and for make it short we call it _cut_line
  _cut_line(&c_point, &line);
  return (line);
}
