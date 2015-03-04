/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:18:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/04 16:27:18 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NcursesLib.hpp>
#include <iostream>

extern "C" NcursesLib		*maker( int width, int height )
{
	NcursesLib *n = new NcursesLib(width, height);

	return ( n );
}
