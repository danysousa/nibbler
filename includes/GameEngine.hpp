/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:05:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 16:09:50 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP
# include <iostream>
# include <Snake.hpp>
# include <Food.hpp>

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
		int		getWidthMap( void ) const;
		int		getHeightMap( void ) const;
		/*
		** METHOD
		*/
		void	updateAll( void );
		void	renderAll( void );

	private:
		int		widthMap;
		int		heightMap;
		Snake	*snake;
		Food	*food;
};

#endif
