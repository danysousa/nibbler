/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:15:44 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/03 17:48:51 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Food.hpp>

Food::Food( int x, int y, int color ) : x( x ), y( y ), color( color )
{

}

Food::Food( Food const & cpy )
{
	*this = cpy;
}

Food::~Food( void )
{
	return ;
}

/*
** OPERATOR
*/
Food Food::operator=( Food const & cpy )
{
	this->x = cpy.getX();
	this->y = cpy.getY();
	this->y = cpy.getColor();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int		Food::getX( void ) const
{
	return ( this->x );
}

int		Food::getY( void ) const
{
	return ( this->y );
}

int		Food::getColor( void ) const
{
	return ( this->color );
}

/*
** METHOD
*/
void	Food::update( void )
{
	return ;
}

void	Food::render( void )
{
	return ;
}

