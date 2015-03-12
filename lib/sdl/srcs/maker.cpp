/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:18:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 16:52:24 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SdlLib.hpp>
#include <iostream>

extern "C" SdlLib		*maker( int width, int height )
{
	SdlLib *n = new SdlLib( width, height );

	return ( n );
}
