/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:05:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/11 17:00:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP
# include <iostream>
# include <Snake.hpp>
# include <Food.hpp>
# include <RenderEngine.hpp>

class GameEngine
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		GameEngine( void );
		GameEngine( int width, int height);
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
