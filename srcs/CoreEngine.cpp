/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:45:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/11 16:02:21 by dsousa           ###   ########.fr       */
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

CoreEngine::CoreEngine( int width, int height ) : gameEngine( new GameEngine( width, height ) ), start( 1 )
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


	// this->gameEngine->wall( this->gameEngine->getRender()->getLib() );

	// this->gameEngine->getSnake()->render( this->gameEngine->getRender()->getLib() );
	while ( this->start )
	{
		this->gameEngine->getRender()->getLib()->keyPressed();
		this->timeStart = clock();
		this->gameEngine->cleanScreen( this->gameEngine->getRender()->getLib() );
		std::cout << "main fucking loop 1 " << std::endl;
		this->gameEngine->getRender()->getLib()->drawSquare(1, 1, 1);

		// this->gameEngine->updateAll();
		// this->gameEngine->renderAll();
		std::cout << "main fucking loop 2" << std::endl;
		this->timeEnd = clock();
		tmp = (static_cast<long double>(this->timeEnd) - static_cast<long double>(this->timeStart)) / CLOCKS_PER_SEC;
		if ( tmp < 0.04 )
			usleep( (0.4 - tmp ) * 100000 );

		this->gameEngine->getRender()->getLib()->refresh();
	}

	return ;
}
