/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:06:21 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/06 11:03:50 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
GameEngine::GameEngine( void ) : widthMap( 100 ), heightMap( 50 ), snake( new Snake() ), food( new Food() ), render( new RenderEngine() )
{
	return ;
}

GameEngine::GameEngine( int width, int height ) : widthMap( width ), heightMap( height )
{
	std::string		tmp = "lib/ncurses/NcursesLib.so";
	this->snake = new Snake( 0, 0 );
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
	if ( this->widthMap || this->heightMap )
		return ;
	return ;
}

