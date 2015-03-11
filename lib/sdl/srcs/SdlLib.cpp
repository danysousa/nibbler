/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SdlLib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 18:38:38 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SdlLib.hpp>

int		SdlLib::key = 0;

SdlLib::SdlLib( int width, int height ) : width(width), height(height)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();

		exit( 0 );
	}


	// Création de la fenêtre

	this->win = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);


	// On quitte la SDL

	// SDL_DestroyWindow(this->win);
	// SDL_Quit();
}


SdlLib::SdlLib( SdlLib const & cpy )
{
	*this = cpy;
}

SdlLib::~SdlLib( void )
{
	return ;
}

/*
** OPERATOR
*/
SdlLib		SdlLib::operator=( SdlLib const & cpy )
{
	this->width = cpy.getWidth();
	this->height = cpy.getHeight();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int			SdlLib::getWidth( void ) const
{
	return ( this->width );
}
int			SdlLib::getHeight( void ) const
{
	return ( this->height );
}

/*
** METHOD
*/



void		SdlLib::drawSquare( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
}

void		SdlLib::drawCircle( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
}

void		SdlLib::drawTriangle( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;

}

void		SdlLib::drawBlock( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
}

void		SdlLib::drawEmpty( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
}

int		SdlLib::keyPressed( void )
{
	if ( this->evenements.window.event == SDL_WINDOWEVENT_CLOSE || this->evenements.window.event == SDLK_ESCAPE )
	{
		SDL_DestroyWindow( this->win );
    	SDL_Quit();
		exit( 0 );
	}
	if ( this->evenements.window.event == SDL_SCANCODE_LEFT )
		return ( 20 );
	if ( this->evenements.window.event == SDL_SCANCODE_RIGHT )
		return ( 40 );
	if ( this->evenements.window.event == SDL_SCANCODE_UP )
		return ( 60 );
	if ( this->evenements.window.event == SDL_SCANCODE_DOWN )
		return (80);
	return (0);
}

void		SdlLib::refresh( void )
{
	SDL_WaitEvent( &(this->evenements ));
}
