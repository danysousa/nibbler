/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:06:21 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/13 13:52:09 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine.hpp>

/*
** CONSTRUCT & DESTRUCT
*/
GameEngine::GameEngine( void ) : widthMap( 100 ), heightMap( 50 ), snake( new Snake() ), food( new Food(100, 50) ), render( new RenderEngine() )
{
	return ;
}

GameEngine::GameEngine( int width, int height, std::string lib ) : widthMap( width ), heightMap( height )
{
	std::map<std::string, std::string>	tb_lib;

	tb_lib["sdl"] = "lib/sdl/SdlLib.so";
	tb_lib["opengl"] = "lib/opengl/OpenglLib.so";
	tb_lib["ncurses"] = "lib/ncurses/NcursesLib.so";
	this->snake = new Snake( this->widthMap / 2, this->heightMap / 2, "left" );
	this->food = new Food( this->widthMap, this->heightMap );
	this->render = new RenderEngine( tb_lib[lib] , this->widthMap, this->heightMap );
	return ;
}

GameEngine::GameEngine( GameEngine const & cpy )
{
	*this = cpy;
}

GameEngine::~GameEngine( void )
{
	delete this->snake;
	delete this->food;
	delete this->render;
	return ;
}

/*
** OPERATOR
*/
GameEngine		GameEngine::operator=( GameEngine const & cpy )
{
	this->widthMap = cpy.getWidthMap();
	this->heightMap = cpy.getHeightMap();
	this->render = cpy.getRender();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int				GameEngine::getWidthMap( void ) const
{
	return ( this->widthMap );
}

int				GameEngine::getHeightMap( void ) const
{
	return ( this->heightMap );
}

Snake *			GameEngine::getSnake( void ) const
{
	return ( this->snake );
}

Food *			GameEngine::getFood( void ) const
{
	return ( this->food );
}

RenderEngine *	GameEngine::getRender( void ) const
{
	return ( this->render );
}

int				GameEngine::getInput( void ) const
{
	return ( this->input );
}

/*
** METHOD
*/
void			GameEngine::updateAll( void )
{
	this->input = this->render->getLib()->keyPressed();

	if ( this->input == 20 && this->snake->getDirection().compare("right") != 0 )
		this->snake->setDirection("left");
	if ( this->input == 40 && this->snake->getDirection().compare("left") != 0 )
		this->snake->setDirection("right");
	if ( this->input == 60 && this->snake->getDirection().compare("down") != 0 )
		this->snake->setDirection("up");
	if ( this->input == 80 && this->snake->getDirection().compare("up") != 0 )
		this->snake->setDirection("down");

	if ( this->snake->getBody()[0]->getX() == this->food->getX() && this->snake->getBody()[0]->getY() == this->food->getY() )
	{
		this->snake->addBodyBlock();
		this->food->changePos( this->snake, this->widthMap, this->heightMap );
	}

	this->snake->update( this->widthMap, this->heightMap, this->render->getLib() );
	return ;
}

void			GameEngine::renderAll( void )
{
	this->snake->render( this->render->getLib() );
	this->food->render( this->render->getLib() );
	this->wall( this->render->getLib() );
	this->render->getLib()->score( this->snake->getSize() - 4 );
	return ;
}

void			GameEngine::cleanScreen( IGraphicLib *lib )
{
	lib->drawEmpty();
}

void			GameEngine::wall( IGraphicLib *lib )
{
	for ( int x = 0; x < this->widthMap; x++ )
	{
		lib->drawBlock( x, 0, 0 );
	}

	for ( int x = 0; x < this->widthMap; x++ )
	{
		lib->drawBlock( x, this->heightMap - 1, 0 );
	}

	for ( int y = 0; y < this->heightMap; y++ )
	{
		lib->drawBlock( 0, y, 0) ;
	}

	for ( int y = 0; y < this->heightMap; y++ )
	{
		lib->drawBlock( this->widthMap - 1, y, 0 );
	}
}
