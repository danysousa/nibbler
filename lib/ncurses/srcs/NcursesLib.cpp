/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/13 13:53:51 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NcursesLib.hpp>

NcursesLib::NcursesLib( int width, int height ) : width( width ), height( height ), key( 0 )
{
	initscr();
	cbreak();
	this->win = newwin(this->height + 5, this->width, 0, 0);
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
void		NcursesLib::drawSquare( int x, int y , int  )
{
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "+" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawCircle( int x, int y , int )
{
	init_pair(1, COLOR_RED, COLOR_RED );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "o" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawTriangle( int x, int y , int )
{
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "@" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawBlock( int x, int y , int )
{
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW );
	attron( COLOR_PAIR(1) );
	mvwprintw( this->win, y, x, "*" );
	attroff( COLOR_PAIR(1) );
}

void		NcursesLib::drawEmpty( void )
{
	wclear( this->win );
}

int		NcursesLib::keyPressed( void )
{
	if ( this->key == 27 )
		return ( -1 );
	if ( this->key >= 49 && this->key <= 52 )
		return ( this->key - 48 );
	if ( this->key == 32 )
		return ( 42 );
	if ( this->key == KEY_LEFT )
		return ( 20 );
	if ( this->key == KEY_RIGHT )
		return ( 40 );
	if ( this->key == KEY_UP )
		return ( 60 );
	if ( this->key == KEY_DOWN )
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
	this->key = getch();
}
