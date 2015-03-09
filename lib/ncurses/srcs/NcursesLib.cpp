/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/09 11:37:25 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NcursesLib.hpp>

NcursesLib::NcursesLib( int width, int height ) : width(width), height(height)
{
	initscr();
	cbreak();
	this->win = newwin(this->height, this->width, 0, 0);
	nodelay( stdscr, true );
	keypad( stdscr, true );
	noecho();
	start_color();
	curs_set( false );

	wrefresh( this->win );
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
void		NcursesLib::drawSquare( int x, int y , int color )
{
	(void)color;

	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "o" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawCircle( int x, int y , int color )
{
	(void)color;

	init_pair(1, COLOR_RED, COLOR_RED );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "o" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawTriangle( int x, int y , int color )
{
	(void)color;

	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "<" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawEmpty( int x, int y , int color )
{
	(void)color;

	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, " " );
	attroff( COLOR_PAIR(1) );
}

int		NcursesLib::keyPressed( void )
{
	if ( getch() == 27 )
	{
		endwin();
		exit(0);
	}
	return ( getch() );
}

void		NcursesLib::refresh( void )
{
	wrefresh( this->win );
}
