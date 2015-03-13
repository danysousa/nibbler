/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:18:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 16:12:08 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenglLib.hpp>
#include <iostream>

extern "C" OpenglLib		*maker( int width, int height )
{
	OpenglLib *n = new OpenglLib(width, height);

	return ( n );
}
