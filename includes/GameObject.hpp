/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:59:01 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 15:01:59 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

class AGameObject
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		GameObject( void );
		GameObject( GameObject const & cpy );
		~GameObject( void );

		/*
		** OPERATOR
		*/
		GameObject operator=( GameObject const & cpy );

		/*
		** METHOD
		*/
		virtual void	update( void ) = 0;
		virtual void	render( void ) = 0;

};

#endif
