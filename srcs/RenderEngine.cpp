/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:25:06 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 14:24:58 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RenderEngine.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
RenderEngine::RenderEngine( void ) : libName( "ncurse" )
{
	return ;
}

RenderEngine::RenderEngine( std::string & libName ) : libName( libName )
{
	return ;
}

RenderEngine::RenderEngine( RenderEngine const & cpy )
{
	*this = cpy;
}

RenderEngine::~RenderEngine( void )
{
	return ;
}

/*
** OPERATOR
*/
RenderEngine	RenderEngine::operator=( RenderEngine const & cpy )
{
	this->libName = cpy.getLibName();

	return (*this);
}

/*
** GETTER & SETTER
*/
std::string		RenderEngine::getLibName( void ) const
{
	return (this->libName);
}

void			RenderEngine::setLibName( std::string const & lib )
{
	(void)lib;
	return ;
}
