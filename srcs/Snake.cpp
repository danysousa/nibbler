/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:22:59 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/10 13:49:56 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Snake.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
Snake::Snake( void ) : size( 4 ), direction( "left" ), addBody( false )
{
	this->body.push_back( new BodyBlock( 4, 0, 0 ) );
	this->body.push_back( new BodyBlock( 3, 0, 0 ) );
	this->body.push_back( new BodyBlock( 2, 0, 0 ) );
	this->body.push_back( new BodyBlock( 1, 0, 0 ) );

	return ;
}

Snake::Snake( int x, int y, std::string direction ) : size( 4 ), direction( direction ), addBody( false )
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
void						Snake::update( int width, int height )
{
	if ( this->addBody )
	{
		this->body.push_back( new BodyBlock(0, 0, 0) );
		this->addBody = false;
		this->size++;
	}

	for ( int i = this->size - 1; i != 0; --i )
	{
		this->body[i]->setX( this->body[i - 1]->getX() );
		this->body[i]->setY( this->body[i - 1]->getY() );
	}

	if ( this->direction.compare( "left" ) == 0 )
		left( width );
	else if ( this->direction.compare( "right" ) == 0 )
		right( width );
	else if ( this->direction.compare( "up" ) == 0 )
		up( height );
	else if ( this->direction.compare( "down" ) == 0 )
		down( height );
	if ( this->isDead( width, height ) )
		while( 1 );
	return ;
}

bool						Snake::isDead( int width, int height ) const
{
	if ( this->body[0]->getX() == 0 ||  this->body[0]->getX() == width - 1
		|| this->body[0]->getY() == 0 ||  this->body[0]->getY() == height - 1 )
		return ( true );

	for (int i = 1; i < this->size; ++i)
	{
		if ( this->body[0]->getX() == this->body[i]->getX() && this->body[0]->getY() == this->body[i]->getY() )
			return ( true );
	}
	return ( false );
}

void						Snake::left( int width )
{
	if ( this->body[0]->getX() != 0 )
		this->body[0]->mooveX( -1 );
	else
		this->body[0]->setX( width );

}

void						Snake::right( int width )
{
	if ( this->body[0]->getX() != width )
		this->body[0]->mooveX( 1 );
	else
		this->body[0]->setX( 0 );

}

void						Snake::up( int height )
{
	if ( this->body[0]->getY() != 0 )
		this->body[0]->mooveY( -1 );
	else
		this->body[0]->setY( height );

}

void						Snake::down( int height )
{
	if ( this->body[0]->getY() != height )
		this->body[0]->mooveY( 1 );
	else
		this->body[0]->setY( 0 );

}

void						Snake::render( IGraphicLib *lib )
{
	std::vector<BodyBlock *>::iterator ite = this->body.end();

	for ( std::vector<BodyBlock *>::iterator it = this->body.begin(); it != ite; ++it )
	{
		if ( it != this->body.begin() )
			lib->drawCircle( (*it)->getX(), (*it)->getY(), 0 );
		else
			lib->drawTriangle( (*it)->getX(), (*it)->getY(), 0 );

	}
	return ;
}

void						Snake::addBodyBlock( void )
{
	this->addBody = true;
}
