/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:18:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/10 15:34:40 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenglLib.hpp>
#include <iostream>

extern "C" OpenglLib		*maker( int width, int height )
{
	OpenglLib *n = new OpenglLib(width, height);

	return ( n );
}
