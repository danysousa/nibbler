/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:06:21 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 16:40:26 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
GameEngine::GameEngine( void ) : widthMap(100), heightMap(50), snake( new Snake() )
{
	std::cout << "coucou" << std::endl;
	return ;
}

GameEngine::GameEngine( int width, int height ) : widthMap(width), heightMap(height)
{
	this->snake = new Snake( 0, 0 );
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
	return ( cpy );
}

/*
** METHOD
*/
void		GameEngine::updateAll( void )
{
	if (this->widthMap || this->heightMap)
		return ;
	return ;
}
