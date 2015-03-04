/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/04 16:42:10 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NcursesLib.hpp>

NcursesLib::NcursesLib( int width, int height ) : width(width), height(height)
{
	initscr( );
	nodelay(stdscr, true);
	start_color( );
	this->win = newwin(this->height, this->width, 0, 0);
	wrefresh( win );
	keypad( stdscr, true );
	noecho( );
	curs_set( 0 );
}

NcursesLib::NcursesLib( NcursesLib const & cpy )
{
	*this = cpy;
}

NcursesLib::~NcursesLib( void )
{
	return ;
}

/*
** OPERATOR
*/
NcursesLib		NcursesLib::operator=( NcursesLib const & cpy )
{
	this->width = cpy.getWidth();
	this->height = cpy.getHeight();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int			NcursesLib::getWidth( void ) const
{
	return ( this->width );
}
int			NcursesLib::getHeight( void ) const
{
	return ( this->height );
}

/*
** METHOD
*/
void		NcursesLib::drawSquare( int x, int y , int color)
{
	move(y, x);

	(void)color;

	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	addstr( "=" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawCircle( int x, int y , int color)
{
	move(y, x);

	(void)color;

	init_pair(1, COLOR_RED, COLOR_RED );
	attron( COLOR_PAIR(1) );
	addstr( "o" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawTriangle( int x, int y , int color)
{
	move(y, x);

	(void)color;

	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	addstr( "<" );
	attroff( COLOR_PAIR(1) );
}
