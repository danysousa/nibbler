/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BodyBlock.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:11:36 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 16:43:36 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BODYBLOCK_HPP
# define BODYBLOCK_HPP

class BodyBlock
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		BodyBlock( BodyBlock const & cpy );
		BodyBlock( int x, int y, int color );
		~BodyBlock( void );

		/*
		** OPERATOR
		*/
		BodyBlock operator=( BodyBlock const & cpy );

		/*
		** GETTER & SETTER
		*/
		int		getX( void ) const;
		int		getY( void ) const;
		int		getColor( void ) const;

		/*
		** METHOD
		*/
		virtual void	render( void );

	private:
		BodyBlock( void );

		int				x;
		int				y;
		int				color;

};

#endif
