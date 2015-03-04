/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:18:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/04 14:26:04 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Ncurses.hpp>

Ncurses		*maker( int width, int height )
{
	Ncurses *n = new Ncurses(width, height);

	return ( n );
}
