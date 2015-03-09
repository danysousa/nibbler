/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicLib.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:24:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/06 14:19:19 by nschilli         ###   ########.fr       */
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
		virtual void		drawEmpty( int x, int y, int color ) = 0;
		virtual int			keyPressed( void ) = 0;
		virtual void		refresh( void ) = 0;

};

#endif
