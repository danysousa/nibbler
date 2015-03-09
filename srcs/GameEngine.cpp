/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:06:21 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 17:12:16 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
GameEngine::GameEngine( void ) : widthMap( 100 ), heightMap( 50 ), snake( new Snake() ), food( new Food(100, 50) ), render( new RenderEngine() )
{
	return ;
}

GameEngine::GameEngine( int width, int height ) : widthMap( width ), heightMap( height )
{
	std::string		tmp = "lib/ncurses/NcursesLib.so";
	this->snake = new Snake( this->widthMap / 2, this->heightMap / 2, "left" );
	this->food = new Food( this->widthMap, this->heightMap );
	this->render = new RenderEngine( tmp , this->widthMap, this->heightMap );
	return ;
}

GameEngine::GameEngine( GameEngine const & cpy )
{
	*this = cpy;
}

GameEngine::~GameEngine( void )
{
	return ;
}

/*
** OPERATOR
*/
GameEngine		GameEngine::operator=( GameEngine const & cpy )
{
	this->widthMap = cpy.getWidthMap();
	this->heightMap = cpy.getHeightMap();
	this->render = cpy.getRender();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int				GameEngine::getWidthMap( void ) const
{
	return ( this->widthMap );
}

int				GameEngine::getHeightMap( void ) const
{
	return ( this->heightMap );
}

Snake *			GameEngine::getSnake( void ) const
{
	return ( this->snake );
}

Food *			GameEngine::getFood( void ) const
{
	return ( this->food );
}

RenderEngine *	GameEngine::getRender( void ) const
{
	return ( this->render );
}

/*
** METHOD
*/
void			GameEngine::updateAll( void )
{
	this->input = this->render->getLib()->keyPressed();
	if ( this->input == 27 )
		exit( 0 );

	this->snake->update( this->widthMap, this->heightMap );
	return ;
}

void			GameEngine::renderAll( void )
{
	this->snake->render( this->render->getLib() );
	this->food->render( this->render->getLib() );
	return ;
}

void			GameEngine::cleanScreen( IGraphicLib *lib )
{
	for ( int x = 0; x <= this->widthMap; x++)
	{
		for ( int y = 0; y <= this->heightMap; y++ )
		{
			lib->drawEmpty(x, y, 0);
		}
	}
}
