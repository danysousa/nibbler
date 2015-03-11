/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:02 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 18:38:13 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_HPP
# define OPENGL_HPP

# include <iostream>
# include <GLFW/glfw3.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <IGraphicLib.hpp>
# include <math.h>

class OpenglLib : public IGraphicLib
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		OpenglLib( int width, int height );
		OpenglLib( OpenglLib const & );
		virtual ~OpenglLib( void );

		/*
		** OPERATOR
		*/
		OpenglLib		operator=( OpenglLib const & cpy );

		/*
		** GETTER & SETTER
		*/
		int				getWidth( void ) const;
		int				getHeight( void ) const;

		/*
		** METHOD
		*/
		virtual void	drawSquare( int x, int y, int color );
		double			adaptX( double x );
		double			adaptY( double y );
		virtual void	drawCircle( int x, int y, int color );
		virtual void	drawTriangle( int x, int y, int color );
		virtual void	drawBlock( int x, int y, int color );
		virtual void	drawEmpty( void );
		virtual int		keyPressed( void );
		virtual void	refresh( void );

		static int		key;

	private:
		OpenglLib( void );

		int			width;
		int			height;
		GLFWwindow	*win;
};

#endif
