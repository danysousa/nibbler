/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:07:37 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/06 10:59:30 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_HPP
# define FOOD_HPP
# include <AGameObject.hpp>
# include <IGraphicLib.hpp>
# include <iostream>

class Food : public AGameObject
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		Food( void );
		Food( int width, int height );
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
		virtual void	render( IGraphicLib *lib );

	private:
		int				x;
		int				y;
		int				color;

};

#endif