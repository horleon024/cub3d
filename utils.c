/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:35:52 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/13 12:43:17 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_convert_rgb(char	*rgb)
{
	int	res;
	int	tmp;
	int	i;

	i = 0;
	while (rgb[i])
	{
		tmp = 0;
		while (rgb[i] != ',' && rgb[i])
		{
			if (ft_isdigit(rgb[i]))
				tmp = tmp * 10 + rgb[i] - '0';
			i++;
		}
		res = (res << 8) + tmp;
		if (rgb[i])
			i++;
	}
	return (res);
}
