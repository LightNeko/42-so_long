/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:18:18 by znicola           #+#    #+#             */
/*   Updated: 2025/02/05 08:43:58 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_error(int error_code, char *message)
{
	if (error_code == 1)
	{
		ft_printf("%s\n", message);
		exit(1);
	}
	if (error_code == 2)
	{
		perror(message);
		exit(1);
	}
}
