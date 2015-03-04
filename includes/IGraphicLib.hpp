/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicLib.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:24:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 14:04:55 by dsousa           ###   ########.fr       */
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
		virtual IGraphicLib( void ) = 0;
		virtual IGraphicLib( int width, int height ) = 0;
		virtual IGraphicLib( IGraphicLib const & cpy ) = 0;
		virtual ~IGraphicLib( void ) = 0;

		/*
		** OPERATOR
		*/
		IGraphicLib operator=( IGraphicLib const & cpy ) = 0;

		/*
		** METHOD
		*/
		virtual void		drawCircle( int x, int y, int color ) = 0;
		virtual void		drawSquare( int x, int y, int color ) = 0;
		virtual void		drawTriangle( int x, int y, int color ) = 0;

	private:
		int		widthMap;
		int		heightMap;
};

#endif
