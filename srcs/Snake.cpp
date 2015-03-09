/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:22:59 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 17:11:54 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Snake.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Snake::Snake( void ) : size( 4 ), direction( "left" )
{
	this->body.push_back( new BodyBlock( 3, 0, 0 ) );
	this->body.push_back( new BodyBlock( 2, 0, 0 ) );
	this->body.push_back( new BodyBlock( 1, 0, 0 ) );
	this->body.push_back( new BodyBlock( 0, 0, 0 ) );

	return ;
}

Snake::Snake( int x, int y, std::string direction ) : size( 4 ), direction( direction )
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
	this->direction = cpy.getDirection();
	return ( *this );
}

/*
** GETTER & SETTER
*/
std::vector<BodyBlock *>	Snake::getBody( void ) const
{
	return ( this->body );
}

int							Snake::getSize( void ) const
{
	return ( this->size );
}

std::string					Snake::getDirection( void ) const
{
	return ( this->direction );
}

void						Snake::setSize( int size )
{
	this->size = this->size + size;
}

void						Snake::setDirection( std::string direction )
{
	this->direction = direction;
}

/*
** METHOD
*/
void	Snake::update( int width, int height )
{
	(void)height;
	std::vector<BodyBlock *>::iterator ite = this->body.end();
	std::vector<BodyBlock *>::iterator it = this->body.begin();
	std::vector<BodyBlock *>::iterator tmp = it;

	for ( it = this->body.begin(); it != ite; ++it )
	{
		if ( this->direction.compare( "left" ) == 0 )
			left( it, &tmp, width );
	}
	return ;
}

void			Snake::left( std::vector<BodyBlock *>::iterator it, std::vector<BodyBlock *>::iterator *tmp, int width )
{
	if ( it == this->body.begin() )
	{
		if ( (*it)->getX() != 0 )
			(*it)->mooveX( -1 );
		else
			(*it)->setX( width );
	}
	else
	{
		if ( (*(*tmp))->getX() + 1 <= width )
			(*it)->setX( (*(*tmp))->getX() + 1 );
		*tmp = it;
	}
}

void	Snake::render( IGraphicLib *lib )
{
	std::vector<BodyBlock *>::iterator ite = this->body.end();

	for ( std::vector<BodyBlock *>::iterator it = this->body.begin(); it != ite; ++it )
	{
		lib->drawCircle( (*it)->getX(), (*it)->getY(), 0 );
	}
	return ;
}
