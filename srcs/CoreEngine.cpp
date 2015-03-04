/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:45:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 15:21:59 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CoreEngine.hpp>
#include <iostream>

/*
** CONSTRUCT & DESTRUCT
*/
CoreEngine::CoreEngine( void ) : gameEngine( new GameEngine )
{
	return ;
}

CoreEngine::CoreEngine( CoreEngine const & cpy ) : gameEngine( new GameEngine )
{
	*this = cpy;
}

CoreEngine::~CoreEngine( void )
{
	delete this->gameEngine;
	return ;
}

/*
** OPERATOR
*/
CoreEngine		CoreEngine::operator=( CoreEngine const & cpy )
{
	return cpy;
}

/*
** METHOD
*/
