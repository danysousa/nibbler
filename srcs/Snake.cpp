/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:22:59 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 17:14:05 by nschilli         ###   ########.fr       */
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
	this->body.push_back( new BodyBlock( x - 1, y, 0 ) );
	this->body.push_back( new BodyBlock( x - 2, y, 0 ) );
	this->body.push_back( new BodyBlock( x - 3, y, 0 ) );

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

/*
** METHOD
*/
void	Snake::update( void )
{
	return ;
}

void	Snake::render( void )
{
	return ;
}
