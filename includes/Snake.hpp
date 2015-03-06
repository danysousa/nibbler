/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:23:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/06 10:58:09 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP
# include <AGameObject.hpp>
# include <BodyBlock.hpp>
# include <IGraphicLib.hpp>
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

		/*
		** METHOD
		*/
		virtual void	update( void );
		virtual void	render( IGraphicLib *lib );

	private:
		int								size;
		std::vector<BodyBlock *>		body;
};

#endif
