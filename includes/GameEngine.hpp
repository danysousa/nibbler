/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:05:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/12 16:50:57 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP
# include <iostream>
# include <Snake.hpp>
# include <Food.hpp>
# include <RenderEngine.hpp>
# include <map>

class GameEngine
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		GameEngine( void );
		GameEngine( int width, int height, std::string lib );
		GameEngine( GameEngine const & cpy );
		~GameEngine( void );

		/*
		** OPERATOR
		*/
		GameEngine operator=( GameEngine const & cpy );

		/*
		** GETTER & SETTER
		*/
		int				getWidthMap( void ) const;
		int				getHeightMap( void ) const;
		Snake *			getSnake( void ) const;
		Food *			getFood( void ) const;
		RenderEngine *	getRender( void ) const;
		int				getInput( void ) const;

		/*
		** METHOD
		*/
		void			updateAll( void );
		void			renderAll( void );
		void			cleanScreen( IGraphicLib *lib );
		void			wall( IGraphicLib *lib );

	private:
		int				widthMap;
		int				heightMap;
		int				input;
		Snake			*snake;
		Food			*food;
		RenderEngine	*render;
};

#endif
