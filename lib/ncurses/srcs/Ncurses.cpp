/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/04 14:11:54 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.hpp"

Ncurses::Ncurses( int width, int height ) : width(width), height(height)
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

Ncurses::Ncurses( Ncurses const & cpy )
{
	*this = cpy;
}

Ncurses::~Ncurses( void )
{
	return ;
}

/*
** OPERATOR
*/
Ncurses		Ncurses::operator=( Ncurses const & cpy )
{
	this->width = this->getWidth();
	this->height = this->getHeight();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int		getWidth( void )
{
	return ( this->width );
}
int		getHeight( void )
{
	return ( this->height );
}

/*
** METHOD
*/
void		Ncurses::drawSquare( int x, int y , int color)
{
	move(y, x);

	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	addstr( "=" );
	attroff( COLOR_PAIR(1) );
}

void		Ncurses::drawCircle( int x, int y , int color)
{
	move(y, x);

	init_pair(1, COLOR_RED, COLOR_RED );
	attron( COLOR_PAIR(1) );
	addstr( "o" );
	attroff( COLOR_PAIR(1) );
}

void		Ncurses::drawTriangle( int x, int y , int color)
{
	move(y, x);

	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	addstr( "<" );
	attroff( COLOR_PAIR(1) );
}