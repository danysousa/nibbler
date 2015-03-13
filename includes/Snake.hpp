/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:23:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/13 11:30:34 by dsousa           ###   ########.fr       */
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
		Snake( int x, int y, std::string direction );
		Snake( Snake const & cpy );
		virtual ~Snake( void );

		/*
		** OPERATOR
		*/
		Snake operator=( Snake const & cpy );

		/*
		** GETTER & SETTER
		*/
		std::vector<BodyBlock *>	getBody( void ) const;
		int							getSize( void ) const;
		std::string					getDirection( void ) const;
		void						setSize( int size );
		void						setDirection( std::string direction );

		/*
		** METHOD
		*/
		void	update( int width, int height, IGraphicLib *lib );
		virtual void	render( IGraphicLib *lib );
		void			left( int width );
		void			right( int width );
		void			up( int height );
		void			down( int height );
		void			addBodyBlock( void );
		bool			isDead( int width, int height ) const;

	private:
		int								size;
		std::string						direction;
		std::vector<BodyBlock *>		body;
		bool							addBody;
};

#endif
