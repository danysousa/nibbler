/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:25:13 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/06 13:35:55 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP
# include <iostream>
# include <string>
# include <IGraphicLib.hpp>
# include <dlfcn.h>

class RenderEngine
{
	public:
		/*
		** CONSTRUCT & DESTRUCT
		*/
		RenderEngine( void );
		RenderEngine( std::string & libName, int width, int height);
		RenderEngine( RenderEngine const & cpy );
		~RenderEngine( void );

		/*
		** OPERATOR
		*/
		RenderEngine operator=( RenderEngine const & cpy );

		/*
		** GETTER & SETTER
		*/
		std::string		getLibPath( void ) const;
		void			setLibPath( std::string const & lib );
		int				getWidth( void ) const;
		int				getHeight( void ) const;
		IGraphicLib		*getLib( void ) const;

		/*
		** METHOD
		*/
		void			loadLib( void );

	private:
		std::string		libPath;
		int				width;
		int				height;
		IGraphicLib		*lib;
};

#endif
