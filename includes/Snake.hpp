/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:23:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 18:04:12 by dsousa           ###   ########.fr       */
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
		std::string					getDirection( void ) const;
		void						setSize( int size );
		void						setDirection( std::string direction );

		/*
		** METHOD
		*/
		virtual void	update( int width, int height );
		virtual void	render( IGraphicLib *lib );
		void			left( std::vector<BodyBlock *>::iterator it, int width );
		void			right( std::vector<BodyBlock *>::iterator it, int width );
		void			up( std::vector<BodyBlock *>::iterator it, int height );
		void			down( std::vector<BodyBlock *>::iterator it, int height );
		void			addBodyBlock( void );

	private:
		int								size;
		std::string						direction;
		std::vector<BodyBlock *>		body;
		bool							addBody;
};

#endif
