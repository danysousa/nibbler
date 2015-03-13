/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SdlLib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/13 11:00:55 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SdlLib.hpp>

int		SdlLib::key = 0;

SdlLib::SdlLib( int width, int height ) : width(width * ZOOM), height(height * ZOOM)
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();

		exit( 0 );
	}

	this->win = SDL_CreateWindow( "SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN );
	this->renderer =  SDL_CreateRenderer( this->win, 0, SDL_RENDERER_ACCELERATED );
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

	SDL_Rect fillRect = { x * ZOOM, y * ZOOM, ZOOM, ZOOM };
	SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderFillRect( this->renderer, &fillRect );
}

void		SdlLib::drawCircle( int x, int y , int color )
{
	(void)color;
	double	tmp_x;
	double	tmp_y;
	double	angle;

	SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	for( int i = 0; i < ZOOM / 2; ++i )
	{
		for (int j = 0; j < 360; ++j)
		{
			angle = 2 * 3.14 * static_cast<double>( j ) / 360;
			tmp_x = cos(angle) * static_cast<double>( i );
			tmp_y = sin(angle) * static_cast<double>( i );
			SDL_RenderDrawPoint( this->renderer, static_cast<double>( x * ZOOM ) + tmp_x + (ZOOM / 2), static_cast<double>( y * ZOOM ) + tmp_y + (ZOOM / 2) );
		}
	}
}

void		SdlLib::drawTriangle( int x, int y , int color )
{
	(void)color;
	double	tmp_x;
	double	tmp_y;
	double	angle;

	SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	for( int i = 0; i < ZOOM / 2; ++i )
	{
		for (int j = 0; j < 360; ++j)
		{
			angle = 2 * 3.14 * static_cast<double>( j ) / 360;
			tmp_x = cos(angle) * static_cast<double>( i );
			tmp_y = sin(angle) * static_cast<double>( i );
			SDL_RenderDrawPoint( this->renderer, static_cast<double>( x * ZOOM ) + tmp_x + (ZOOM / 2), static_cast<double>( y * ZOOM ) + tmp_y + (ZOOM / 2) );
		}
	}
}

void		SdlLib::drawBlock( int x, int y , int color )
{
	(void)color;

	SDL_Rect fillRect = { x * ZOOM, y * ZOOM, ZOOM, ZOOM };
	SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderFillRect( this->renderer, &fillRect );
}

void		SdlLib::drawEmpty( void )
{
	SDL_SetRenderDrawColor( this->renderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_RenderClear( this->renderer );
}

int		SdlLib::keyPressed( void )
{
	if( this->key == SDL_QUIT || this->key == SDL_WINDOWEVENT_CLOSE || this->key == SDL_SCANCODE_ESCAPE)
	{
		this->end();
		return ( -1 );
	}
	if ( this->key == SDL_SCANCODE_LEFT )
		return ( 20 );
	if ( this->key == SDL_SCANCODE_RIGHT )
		return ( 40 );
	if ( this->key == SDL_SCANCODE_UP )
		return ( 60 );
	if ( this->key == SDL_SCANCODE_DOWN )
		return (80);
	if ( this->key == SDL_SCANCODE_KP_1 || this->key == SDL_SCANCODE_1 )
		return ( 1 );
	if ( this->key == SDL_SCANCODE_KP_2 || this->key == SDL_SCANCODE_2 )
		return ( 2 );
	if ( this->key == SDL_SCANCODE_KP_3 || this->key == SDL_SCANCODE_3 )
		return ( 3 );
	return (0);
}

void		SdlLib::score( int score )
{
	(void)score;
	 // mvprintw( this->height + 4, 0, "Score: %d ", score );
}

void		SdlLib::end( void )
{
	SDL_DestroyWindow( this->win );
	SDL_Quit();
}

void		SdlLib::refresh( void )
{

	while ( SDL_PollEvent( &(this->event) ) != 0 )
	{
		//User requests quit
		this->key = this->event.key.keysym.scancode;
	}

	SDL_RenderPresent( this->renderer );
}
