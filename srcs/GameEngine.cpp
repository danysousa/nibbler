/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:06:21 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 16:09:40 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
GameEngine::GameEngine( void ) : widthMap( 100 ), heightMap( 50 ), snake( new Snake() ), food( new Food() )
{
	return ;
}

GameEngine::GameEngine( int width, int height ) : widthMap( width ), heightMap( height )
{
	this->snake = new Snake( 0, 0 );
	this->food = new Food( this->widthMap, this->heightMap );
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
	this->widthMap = cpy.getHeightMap();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int		GameEngine::getWidthMap( void ) const
{
	return ( this->widthMap );
}

int		GameEngine::getHeightMap( void ) const
{
	return ( this->heightMap );
}


/*
** METHOD
*/
void		GameEngine::updateAll( void )
{
	if ( this->widthMap || this->heightMap )
		return ;
	return ;
}

