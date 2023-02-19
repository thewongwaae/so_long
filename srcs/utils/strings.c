/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:55:14 by hwong             #+#    #+#             */
/*   Updated: 2023/02/19 23:10:20 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	dst = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*out;
	int		i;

	i = -1;
	out = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	while (s[++i])
		out[i] = s[i];
	out[i] = '\0';
	return (out);
}

char	*check_ch(char *str, int sep)
{
	int		i;

	i = 0;
	while (str[i] != sep && str[i] != '\0')
		i++;
	if (str[i] == sep)
		return (&str[i]);
	else
		return (NULL);
}
