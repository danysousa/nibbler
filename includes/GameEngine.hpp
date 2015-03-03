/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:05:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 15:20:22 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP
# include <iostream>

class GameEngine
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		GameEngine( void );
		GameEngine( int width, int height );
		GameEngine( GameEngine const & cpy );
		~GameEngine( void );

		/*
		** OPERATOR
		*/
		GameEngine operator=( GameEngine const & cpy );

		/*
		** METHOD
		*/
		void	updateAll( void );

	private:
		int		widthMap;
		int		heightMap;
};

#endif
