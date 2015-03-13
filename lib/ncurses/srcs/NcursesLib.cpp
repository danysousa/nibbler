/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/13 14:40:54 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NcursesLib.hpp>

NcursesLib::NcursesLib( int width, int height ) : width(width), height(height)
{
	initscr();
	cbreak();
	this->win = newwin(this->height + 5, this->width, 0, 0);
	nodelay( stdscr, true );
	keypad( stdscr, true );
	noecho();
	curs_set( false );
	wrefresh( this->win );
	start_color();

	init_color( COLOR_RED_2, 930, 78, 450 );
	init_pair( 1, COLOR_RED_2, COLOR_BLACK );
	init_color( COLOR_BLUE_2, 200, 750, 1000);
	init_pair( 2, COLOR_BLUE_2, COLOR_BLACK );
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
void		NcursesLib::drawSquare( int x, int y , int  )
{
	init_pair(1, COLOR_RED_2, COLOR_BLACK );
	wattron( this->win, COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "+", 31 );
	wattroff( this->win, COLOR_PAIR(1) );
}

void		NcursesLib::drawCircle( int x, int y , int )
{
	init_pair(2, COLOR_BLUE_2, COLOR_BLACK );
	wattron( this->win, COLOR_PAIR(2) );
	mvwprintw( this->win, y, x, "o", 31 );
	wattroff( this->win, COLOR_PAIR(2) );
}

void		NcursesLib::drawTriangle( int x, int y , int )
{
	init_pair(3, COLOR_CYAN, COLOR_BLACK );
	wattron( this->win, COLOR_PAIR(3) );
	mvwprintw( this->win, y, x, "@", 31 );
	wattroff( this->win, COLOR_PAIR(3) );
}

void		NcursesLib::drawBlock( int x, int y , int )
{
	init_pair(4, COLOR_WHITE, COLOR_BLACK );
	wattron( this->win, COLOR_PAIR(4) );
	mvwprintw( this->win, y, x, "*", 31 );
	wattroff( this->win, COLOR_PAIR(4) );
}

void		NcursesLib::drawEmpty( void )
{
	wclear( this->win );
}

int		NcursesLib::keyPressed( void )
{
	int		key = getch();

	if ( key >= 49 && key <= 52 )
		return ( key - 48 );

	if ( key == 27 )
	{
		this->end();
		return ( -1 );
	}
	if ( key == KEY_LEFT )
		return ( 20 );
	if ( key == KEY_RIGHT )
		return ( 40 );
	if ( key == KEY_UP )
		return ( 60 );
	if ( key == KEY_DOWN )
		return (80);
	return ( 0 );
}
void		NcursesLib::score( int score )
{
	 mvprintw( this->height + 2, 0, "Score: %d ", score );
}

void	NcursesLib::end( void )
{
	endwin();
}

void		NcursesLib::refresh( void )
{
	wrefresh( this->win );
}
