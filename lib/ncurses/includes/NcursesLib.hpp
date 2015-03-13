/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:02 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/13 14:45:12 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include <iostream>
# include <ncurses.h>
# include <IGraphicLib.hpp>

# define SET_COLOR(COLOR) (attron(COLOR_PAIR(COLOR)))
# define COLOR_RED_2 (COLOR_WHITE + 1)
# define COLOR_BLUE_2 (COLOR_WHITE + 2)

class NcursesLib : public IGraphicLib
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		NcursesLib( int width, int height );
		NcursesLib( NcursesLib const & );
		virtual ~NcursesLib( void );

		/*
		** OPERATOR
		*/
		NcursesLib		operator=( NcursesLib const & cpy );

		/*
		** GETTER & SETTER
		*/
		int				getWidth( void ) const;
		int				getHeight( void ) const;

		/*
		** METHOD
		*/
		virtual void	drawSquare( int x, int y, int color );
		virtual void	drawCircle( int x, int y, int color );
		virtual void	drawTriangle( int x, int y, int color );
		virtual void	drawBlock( int x, int y, int color );
		virtual void	drawEmpty( void );
		virtual void	score( int score );
		virtual int		keyPressed( void );
		virtual void	end( void );
		virtual void	refresh( void );

	private:
		NcursesLib( void );

		int		width;
		int		height;
		WINDOW	*win;
		int		key;
};

#endif
