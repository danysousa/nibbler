/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BodyBlock.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:11:28 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 12:38:18 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BodyBlock.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
BodyBlock::BodyBlock( void ) : x( 0 ), y( 0 )
{
	return ;
}

BodyBlock::BodyBlock( int x, int y, int color ) : x( x ), y( y ), color( color )
{
	return ;
}

BodyBlock::BodyBlock( BodyBlock const & cpy )
{
	*this = cpy;
	return ;
}

BodyBlock::~BodyBlock( void )
{
	return ;
}

/*
** OPERATOR
*/
BodyBlock BodyBlock::operator=( BodyBlock const & cpy )
{
	this->x = cpy.getX();
	this->y = cpy.getY();
	this->color = cpy.getColor();

	return ( *this );
}

/*
** METHOD
*/

void		BodyBlock::render( void )
{
	return ;
}

/*
** GETTER & SETTER
*/
int		BodyBlock::getX( void ) const
{
	return ( this->x );
}

int		BodyBlock::getY( void ) const
{
	return ( this->y );
}

int		BodyBlock::getColor( void ) const
{
	return ( this->color );
}

void	BodyBlock::mooveX( int x )
{
	if ( x != 0)
		this->x = this->x + x;
	else
		this->x = 0;
}

void	BodyBlock::mooveY( int y )
{
		this->y = this->y + y;
}

void	BodyBlock::setX( int x )
{
	if ( x != 0)
		this->x = x;
	else
		this->x = 0;
}

void	BodyBlock::setY( int y )
{
		this->y = y;
}