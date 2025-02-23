/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:18:18 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 18:00:10 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	manage_error(void *data, int error_code, char *message, void *to_free)
{
	if (to_free != NULL)
		free(to_free);
	if (error_code == 1)
		ft_printf("%s\n", message);
	if (error_code == 2)
		perror(message);
	if (error_code == 4)
	{
		ft_printf("%s\n", message);
		free_resources(data);
	}
	if (data != NULL)
	{
		mlx_destroy_display(((t_data *)data)->mlx);
		free(((t_data *)data)->mlx);
	}
	exit(1);
}
