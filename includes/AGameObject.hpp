/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameObject.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:59:01 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/06 13:54:34 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAMEOBJECT_HPP
# define AGAMEOBJECT_HPP

# include <IGraphicLib.hpp>

class AGameObject
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		AGameObject( void );
		AGameObject( AGameObject const & );
		virtual ~AGameObject( void );

		/*
		** METHOD
		*/
		virtual void	update( int width, int height ) = 0;
		virtual void	render( IGraphicLib *lib ) = 0;

};

#endif
