/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:22:59 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 17:06:25 by nschilli         ###   ########.fr       */
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
	std::vector<BodyBlock *>::iterator it = this->body.begin();

	for (int i = this->size; i != 0; --i)
	{
		this->body[i]->setX( this->body[i - 1]->getX() );
		this->body[i]->setY( this->body[i - 1]->getY() );
	}

	if ( this->direction.compare( "left" ) == 0 )
		left( it, width );
	if ( this->direction.compare( "right" ) == 0 )
		right( it, width );
	if ( this->direction.compare( "up" ) == 0 )
		up( it, height );
	if ( this->direction.compare( "down" ) == 0 )
		down( it, height );
	return ;
}

void			Snake::left( std::vector<BodyBlock *>::iterator it, int width )
{
	if ( it == this->body.begin() )
	{
		if ( (*it)->getX() != 0 )
			(*it)->mooveX( -1 );
		else 
			(*it)->setX( width );
	}
}

void			Snake::right( std::vector<BodyBlock *>::iterator it, int width )
{
	if ( it == this->body.begin() )
	{
		if ( (*it)->getX() != width )
			(*it)->mooveX( 1 );
		else 
			(*it)->setX( 0 );
	}
}

void			Snake::up( std::vector<BodyBlock *>::iterator it, int height )
{
	if ( it == this->body.begin() )
	{
		if ( (*it)->getY() != 0 )
			(*it)->mooveY( -1 );
		else 
			(*it)->setY( height );
	}
}

void			Snake::down( std::vector<BodyBlock *>::iterator it, int height )
{
	if ( it == this->body.begin() )
	{
		if ( (*it)->getY() != height )
			(*it)->mooveY( 1 );
		else 
			(*it)->setY( 0 );
	}
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
