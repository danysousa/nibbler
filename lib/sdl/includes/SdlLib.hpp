/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SdlLib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:02 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/12 16:14:44 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_HPP
# define OPENGL_HPP

# include <iostream>
# include <SDL.h>
# include <IGraphicLib.hpp>
# define ZOOM 5.0

class SdlLib : public IGraphicLib
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		SdlLib( int width, int height );
		SdlLib( SdlLib const & );
		virtual ~SdlLib( void );

		/*
		** OPERATOR
		*/
		SdlLib		operator=( SdlLib const & cpy );

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
		virtual void	drawEmpty(  void );
		virtual void	score( int score );
		virtual int		keyPressed( void );
		virtual void	end( void );
		virtual void	refresh( void );

		static int		key;
	private:
		SdlLib( void );

		int				width;
		int				height;
		SDL_Window 		*win;
		SDL_Event		event;
		SDL_Renderer	*renderer;
};

#endif
