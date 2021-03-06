/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:07:15 by erobert           #+#    #+#             */
/*   Updated: 2016/02/09 11:31:42 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			or(t_process *self, void *memory, t_player *players, t_process **p)
{
	int		rindex;

	(void)players;
	(void)p;
	rindex = self->params[2] - 1;
	self->carry = 0;
	if (rindex < 0 || rindex >= REG_NUMBER)
		return (self->size_params);
	if (!get_binary_op_value(self, memory, 0))
		return (self->size_params);
	if (!get_binary_op_value(self, memory, 1))
		return (self->size_params);
	self->registers[rindex] = self->params[0] | self->params[1];
	self->carry = EVAL_CARRY(self->registers[rindex]);
	return (self->size_params);
}
