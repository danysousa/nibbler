/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:25:06 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/12 16:15:19 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RenderEngine.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
RenderEngine::RenderEngine( void ) : libPath( "lib/ncurses/NcursesLib.so" ), width( 20 ), height( 20 )
{
	this->loadLib();
	return ;
}

RenderEngine::RenderEngine( std::string & libPath, int width, int height ) : libPath( libPath ), width( width ), height( height )
{
	this->loadLib();
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
	this->libPath = cpy.getLibPath();
	this->width = cpy.getWidth();
	this->height = cpy.getHeight();
	this->lib = cpy.getLib();

	return (*this);
}

/*
** GETTER & SETTER
*/
std::string		RenderEngine::getLibPath( void ) const
{
	return (this->libPath);
}

void			RenderEngine::setLibPath( std::string const & lib )
{
	this->libPath = lib;
	this->loadLib();
	return ;
}

int				RenderEngine::getWidth( void ) const
{
	return ( this->width );
}

int				RenderEngine::getHeight( void ) const
{
	return ( this->height );
}

IGraphicLib *	RenderEngine::getLib( void ) const
{
	return ( this->lib );
}

/*
** METHOD
*/
void			RenderEngine::loadLib( void )
{
	IGraphicLib		*(*f)(int, int);
	void			*hndl;

	hndl = dlopen(this->libPath.c_str(), RTLD_LAZY);

	if ( hndl == NULL )
	{
		std::cout << dlerror() << std::endl;
		exit( -1 );
	}

	f = ( IGraphicLib *( * )( int, int ) )( dlsym( hndl, "maker" ) );
	if ( f == NULL )
	{
		std::cout << dlerror() << std::endl;
		exit( -1 );
	}

	this->lib = f( this->width, this->height );
}
