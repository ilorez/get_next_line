/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:00:19 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/11 16:12:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// join two strings
static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
  size_t i = 0;
	size_t	size;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
  {
    // print s2
    //printf("===STRJOIN s2: %s\n", s2);
		return (ft_strdup(s2));
  }
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
  dst[i] = '\0';
  // print s1 and s2 and dst
  //printf("s1: %s\n", s1);
  //printf("s2: %s\n", s2);
  //printf("dst: %s\n", dst);
	return (dst);
}

static char	*ft_sublen(char const *s,size_t len)
{
	size_t	size;
	char	*ss;

	ss = (char *)malloc(len * sizeof(char) + 1);
	if (!ss)
		return (NULL);
  ss[len] = '\0';
  while (len--)
    ss[len] = s[len];
	return (ss);
}

static void _cut_line(char **c_point, char **line)
{
  size_t  i;
  char *tmp;


  //printf("###_cut_line POS 1\n");
  if (!**c_point)
  {
    free(*c_point);
    *c_point = NULL;
    *line = NULL;
    return;
  }
  i = 0;
  while ((*c_point)[i] && (*c_point)[i] != '\n')
    i++;
  //printf("###_cut_line POS 2\n");

  if (!(*c_point)[i])
  {

    //printf("###_cut_line POS 3\n");
    *line = ft_strdup(*c_point);
    //printf("###_cut_line POS 3.1\n");
    free((*c_point));
    //printf("###_cut_line POS 3.2\n");
    *c_point = NULL;
    //printf("###_cut_line POS 4\n");
    return;
  }

  //printf("###_cut_line POS 5\n");
  //printf("i is: %zu\n", i);
  //printf("c_point is: %s\n", *c_point);
  //printf("line address is: %p\n", *line);
  *line = (ft_sublen(*c_point, i+1));
  // print address of line
  //printf("line address is: %p\n", *line);
  //printf("line is: %s\n", *line);
  //printf("###_cut_line POS 6\n");
  tmp = *c_point;
  *c_point = ft_strdup(&(*c_point)[i+1]);
  //printf("###_cut_line POS 7\n");
  free(tmp);
  //printf("###_cut_line POS 8\n");
}

// search in string to find \n
static char	*ft_strchr(const char *s, int c)
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

  //printf("###_search_for_line POS 1\n");
  while (!found_line)
  {
    
    readed = read(fd, buffer, BUFFER_SIZE);
    // preint buffer
    //printf("###_search_for_line POS 2\n");
    // end of file
    if (readed == 0)
      break;
    // error
    if (readed <  0)
      return (NULL);

    //printf("###_search_for_line POS 3\n");
    buffer[readed] = '\0';
    //printf("buffer is: %s\n", buffer);
    found_line = ft_strchr(buffer, '\n');
    //printf("found line result is: %s\n", found_line);
    //printf("###_search_for_line POS 4\n");
    tmp = c_point;
    c_point = ft_strjoin(c_point, buffer);
    //printf("c_point after join  is: %s\n", c_point);
    //printf("###_search_for_line POS 5\n");
    free(tmp);
  }

  //printf("###_search_for_line POS 6\n");
  return (c_point);
}

char *get_next_line(int fd)
{
  static char *c_point;
  char *line;
  char *buffer;

  buffer = NULL;
  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);

  if (!ft_strchr(c_point, '\n'))
  {
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
      return (NULL);
    // this function read from fd file untel found "\n" or EOF
    c_point = _search_for_line(fd, c_point, buffer);
    if (!c_point)
    {
      free(buffer);
      return NULL;
    }
  }
  // this fucntion extract the line from the readed value
  // and update update c_point by removing the line that we read
  // so best for funciton is get_line_update_c_point
  // and for make it short we call it _cut_line
  _cut_line(&c_point, &line);
  free(buffer);
  return (line);
}


