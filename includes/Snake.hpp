/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:23:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 11:01:47 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP
# include <AGameObject.hpp>
# include <BodyBlock.hpp>
# include <iostream>
# include <vector>

class Snake : public AGameObject
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		Snake( void );
		Snake( int x, int y );
		Snake( Snake const & cpy );
		~Snake( void );

		/*
		** OPERATOR
		*/
		Snake operator=( Snake const & cpy );

		/*
		** GETTER & SETTER
		*/
		std::vector<BodyBlock *>	getBody( void ) const;
		int							getSize( void ) const;
		int							getDirection( void ) const;

		/*
		** METHOD
		*/
		virtual void	update( int width, int height );
		virtual void	render( IGraphicLib *lib );

	private:
		int								size;
		int								direction;
		std::vector<BodyBlock *>		body;
};

#endif
