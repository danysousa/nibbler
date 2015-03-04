/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:02 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/04 14:11:42 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NCURSES_HPP
# define NCURSES_HPP

#include <iostream>
#include <ncurses.h>

class Ncurses
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		Ncurses( int width, int height );
		Ncurses( Ncurses const & );
		virtual ~Ncurses( void );

		/*
		** OPERATOR
		*/
		Ncurses		operator=( Ncurses const & cpy );

		/*
		** GETTER & SETTER
		*/
		int			getWidth( void );
		int			getHeight( void );

		/*
		** METHOD
		*/
		void		drawSquare( int x, int y, int color );
		void		drawCircle( int x, int y, int color );
		void		drawTrangle( int x, int y, int color );

	private:
		Ncurses( void );

		int		width;
		int		height;
		WINDOW	*win;

};

#endif