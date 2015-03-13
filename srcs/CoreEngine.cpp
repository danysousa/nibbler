/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:45:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/13 10:24:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CoreEngine.hpp>
#include <iostream>
#include <ctime>
#include <unistd.h>

/*
** CONSTRUCT & DESTRUCT
*/
CoreEngine::CoreEngine( void ) : gameEngine( new GameEngine ), start( 1 )
{
	return ;
}

CoreEngine::CoreEngine( int width, int height, std::string lib ) : gameEngine( new GameEngine( width, height, lib ) ), start( 1 )
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
	return ( cpy );
}

/*
** METHOD
*/
void			CoreEngine::loop( void )
{
	long double		tmp;

	this->gameEngine->wall( this->gameEngine->getRender()->getLib() );
	this->gameEngine->getSnake()->render( this->gameEngine->getRender()->getLib() );
	while ( this->start )
	{
		this->timeStart = clock();
		this->gameEngine->cleanScreen( this->gameEngine->getRender()->getLib() );
		this->gameEngine->updateAll();
		this->gameEngine->renderAll();

		if ( this->gameEngine->getInput() == -1
			|| this->gameEngine->getSnake()->isDead( this->gameEngine->getWidthMap(), this->gameEngine->getHeightMap() ) )
		{
			this->start = 0;
			this->gameEngine->getRender()->getLib()->end();
			break ;
		}

		this->checkChangeLib();
		this->timeEnd = clock();
		tmp = (static_cast<long double>(this->timeEnd) - static_cast<long double>(this->timeStart)) / CLOCKS_PER_SEC;
		if ( tmp < 0.04 )
			usleep( (0.4 - tmp ) * 150000 );

		this->gameEngine->getRender()->getLib()->refresh();
	}
	return ;
}

void			CoreEngine::checkChangeLib( void )
{
	if ( this->gameEngine->getInput() > 3 || this->gameEngine->getInput() == 0 )
		return ;

	this->gameEngine->getRender()->changeLib( this->gameEngine->getInput() );
}
