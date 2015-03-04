/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:25:13 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 11:35:21 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP
# include <iostream>
# include <string>

class RenderEngine
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		RenderEngine( void );
		RenderEngine( std::string & libName );
		RenderEngine( RenderEngine const & cpy );
		~RenderEngine( void );

		/*
		** OPERATOR
		*/
		RenderEngine operator=( RenderEngine const & cpy );

		/*
		** GETTER & SETTER
		*/
		std::string		getLibName( void ) const;
		void			setLibName( std::string const & lib );

		/*
		** METHOD
		*/

	private:
		// void			*loadLib();
		std::string		libName;
};

#endif
