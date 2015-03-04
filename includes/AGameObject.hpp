/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameObject.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:59:01 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 16:50:56 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAMEOBJECT_HPP
# define AGAMEOBJECT_HPP

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
		virtual void	update( void ) = 0;
		virtual void	render( void ) = 0;

};

#endif
