/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:45:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 16:41:23 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <IGraphicLib.hpp>
#include <dlfcn.h>



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
	IGraphicLib		*(*f)(int, int);
	IGraphicLib		*lib;
	void			*hndl = dlopen("lib/ncurses/NcursesLib.so", RTLD_LAZY);

	if ( hndl == NULL )
	{
		std::cout << dlerror() << std::endl;
		std::cout << "ERRRRRRROOOOOR" << std::endl;
	}

	f = ( IGraphicLib *(*)(int, int) )(dlsym(hndl, "maker"));
	if ( f == NULL )
	{
		std::cout << dlerror() << std::endl;
		std::cout << "ERRRRRRROOOOOR" << std::endl;
	}
	lib = f( 100, 100 );


	while ( this->start )
	{
		this->timeStart = clock();

		this->gameEngine->updateAll();
	lib->drawSquare(0, 0, 0);

		this->timeEnd = clock();
		tmp = (static_cast<long double>(this->timeEnd) - static_cast<long double>(this->timeStart)) / CLOCKS_PER_SEC;
		if ( tmp < 0.04 )
			usleep( (0.4 - tmp ) * 100000 );
	}

	return ;
}
