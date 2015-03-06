/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:15:44 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/06 13:55:05 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Food.hpp>

Food::Food( void )
{
	this->x = 0;
	this->y = 0;
	this->color = 0;
}

Food::Food( int width, int height )
{
	this->x = rand() % width;
	this->y = rand() % height;
	this->color = rand() % 255;
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
void	Food::update( int width, int height )
{
	(void)width;
	(void)height;
	return ;
}

void	Food::render( IGraphicLib *lib )
{
	(void)lib;
	return ;
}

