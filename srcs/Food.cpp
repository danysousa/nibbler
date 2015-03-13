/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:15:44 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/12 16:26:13 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Food.hpp>

Food::Food( void )
{
	this->x = 10;
	this->y = 10;
	this->color = 0;
}

Food::Food( int width, int height )
{
	this->x = (rand() % (width - 2)) + 1;
	this->y = (rand() % (height - 2)) + 1;
	this->color = 0;
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
Food	Food::operator=( Food const & cpy )
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
void	Food::render( IGraphicLib *lib )
{
	lib->drawSquare( this->x, this->y, 0 );
	return ;
}

void	Food::changePos( Snake *snake, int width, int height )
{
	this->x = (rand() % (width - 2)) + 1;
	this->y = (rand() % (height - 2)) + 1;

	for (int i = snake->getSize(); i >= 0; --i)
	{
		if ( snake->getBody()[0]->getX() == this->x || snake->getBody()[0]->getY() == this->y )
		{
			this->changePos( snake, width, height );
			return ;
		}
	}
}
