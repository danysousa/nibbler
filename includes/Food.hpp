/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:07:37 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/03 17:49:25 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_HPP
# define FOOD_HPP
# include <AGameObject.hpp>
# include <iostream>

class Food : public AGameObject
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		Food( int x, int y, int color );
		Food( Food const & cpy );
		~Food( void );

		/*
		** OPERATOR
		*/
		Food operator=( Food const & cpy );

		/*
		** GETTER & SETTER
		*/
		int		getX( void ) const;
		int		getY( void ) const;
		int		getColor( void ) const;

		/*
		** METHOD
		*/
		virtual void	update( void );
		virtual void	render( void );

	private:
		Food( void );

		int				x;
		int				y;
		int				color;

};

#endif