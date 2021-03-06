/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:25:06 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/13 14:56:54 by dsousa           ###   ########.fr       */
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
	delete this->lib;
	dlclose(this->ptrLib);
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

	this->ptrLib = dlopen(this->libPath.c_str(), RTLD_LAZY | RTLD_LOCAL);

	if ( this->ptrLib == NULL )
	{
		std::cout << dlerror() << std::endl;
		exit( -1 );
	}

	f = ( IGraphicLib *( * )( int, int ) )( dlsym( this->ptrLib, "maker" ) );
	if ( f == NULL )
	{
		std::cout << dlerror() << std::endl;
		exit( -1 );
	}

	this->lib = f( this->width, this->height );
}

void			RenderEngine::changeLib( int id )
{
	std::vector<const char *>	v;

	v.push_back( "lib/ncurses/NcursesLib.so" );
	v.push_back( "lib/opengl/OpenglLib.so" );
	v.push_back( "lib/sdl/SdlLib.so" );

	if ( id > 3 || id == 0 )
		return ;

	if ( this->libPath == v[id - 1] )
		return ;

	this->lib->end();
	dlclose( this->ptrLib );
	this->libPath = v[id - 1];
	this->loadLib();
	sleep( 2 );
}
