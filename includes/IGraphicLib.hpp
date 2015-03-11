/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicLib.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:24:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/11 18:38:55 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHICLIB
# define IGRAPHICLIB

class IGraphicLib
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		virtual ~IGraphicLib( void ) = 0;

		/*
		** METHOD
		*/
		virtual void		drawCircle( int x, int y, int color ) = 0;
		virtual void		drawSquare( int x, int y, int color ) = 0;
		virtual void		drawTriangle( int x, int y, int color ) = 0;
		virtual void		drawBlock( int x, int y, int color ) = 0;
		virtual void		drawEmpty( void ) = 0;
		virtual int			keyPressed( void ) = 0;
		virtual void		refresh( void ) = 0;

};

#endif
