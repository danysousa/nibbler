/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:22:59 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 11:06:31 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Snake.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Snake::Snake( void ) : size( 4 )
{
	this->body.push_back( new BodyBlock( 3, 0, 0 ) );
	this->body.push_back( new BodyBlock( 2, 0, 0 ) );
	this->body.push_back( new BodyBlock( 1, 0, 0 ) );
	this->body.push_back( new BodyBlock( 0, 0, 0 ) );

	return ;
}

Snake::Snake( int x, int y ) : size( 4 )
{
	this->body.push_back( new BodyBlock( x, y, 0 ) );
	this->body.push_back( new BodyBlock( x + 1, y, 0 ) );
	this->body.push_back( new BodyBlock( x + 2, y, 0 ) );
	this->body.push_back( new BodyBlock( x + 3, y, 0 ) );

	return ;
}

Snake::Snake( Snake const & cpy )
{
	*this = cpy;
}

Snake::~Snake( void )
{
	return ;
}

/*
** OPERATOR
*/
Snake Snake::operator=( Snake const & cpy )
{
	this->body = cpy.getBody();
	this->size = cpy.getSize();
	return ( *this );
}

/*
** GETTER & SETTER
*/
std::vector<BodyBlock *>	Snake::getBody( void ) const
{
	return ( this->body );
}

int		Snake::getSize( void ) const
{
	return ( this->size );
}

int		Snake::getDirection( void ) const
{
	return ( this->direction );
}
/*
** METHOD
*/
void	Snake::update( int width, int height )
{
	(void)height;
	std::vector<BodyBlock *>::iterator ite = this->body.end();

	for ( std::vector<BodyBlock *>::iterator it = this->body.begin(); it != ite; ++it )
	{
		if ( (*it)->getX() != width )
			(*it)->setX( 1 );
		else
			(*it)->setX( 0 );
	}
	return ;
}

void	Snake::render( IGraphicLib *lib )
{
	std::vector<BodyBlock *>::iterator ite = this->body.end();

	for ( std::vector<BodyBlock *>::iterator it = this->body.begin(); it != ite; ++it )
	{
		lib->drawSquare( (*it)->getX(), (*it)->getY(), 0 );
	}
	return ;
}
