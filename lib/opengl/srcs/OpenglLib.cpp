/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/10 14:50:30 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenglLib.hpp>

OpenglLib::OpenglLib( int width, int height ) : width(width), height(height)
{
	glfwSetErrorCallback( error_callback );
	if ( !glfwInit() )
		exit( EXIT_FAILURE );

	this->win = glfwCreateWindow( width, height, "window", NULL, NULL );

	if ( !this->win )
	{
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	glfwMakeContextCurrent( this->win );
	glfwSetKeyCallback(this->win, this->key_callback);
}


OpenglLib::OpenglLib( OpenglLib const & cpy )
{
	*this = cpy;
}

OpenglLib::~OpenglLib( void )
{
	return ;
}

/*
** OPERATOR
*/
OpenglLib		OpenglLib::operator=( OpenglLib const & cpy )
{
	this->width = cpy.getWidth();
	this->height = cpy.getHeight();
	return ( *this );
}

/*
** GETTER & SETTER
*/
int			OpenglLib::getWidth( void ) const
{
	return ( this->width );
}
int			OpenglLib::getHeight( void ) const
{
	return ( this->height );
}

/*
** METHOD
*/

void		OpenglLib::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ( action == GLFW_PRESS )
		this->key = key;

	static_cast<void>(scancode);
	static_cast<void>(mods);
}

void		OpenglLib::drawSquare( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
	glBegin(GL_QUAD);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.f);
	glEnd();
}

void		OpenglLib::drawCircle( int x, int y , int color )
{
		(void)color;
		(void)x;
		(void)y;
	glBegin(GL_QUAD);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.f);
	glEnd();
}

void		OpenglLib::drawTriangle( int x, int y , int color )
{
		(void)color;
		(void)x;
		(void)y;
	glBegin(GL_QUAD);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.f);
	glEnd();
}

void		OpenglLib::drawBlock( int x, int y , int color )
{
		(void)color;
		(void)x;
		(void)y;
	glBegin(GL_QUAD);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.f);
	glEnd();
}

void		OpenglLib::drawEmpty( int x, int y , int color )
{
		(void)color;
		(void)x;
		(void)y;
	glBegin(GL_QUAD);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.f);
	glEnd();
}

int		OpenglLib::keyPressed( void )
{
	if ( this->key == GLFW_KEY_ESCAPE )
	{
		endwin();
		exit(0);
	}
	if ( this->key == GLFW_KEY_LEFT )
		return ( 20 );
	if ( this->key == GLFW_KEY_RIGHT )
		return ( 40 );
	if ( this->key == GLFW_KEY_UP )
		return ( 60 );
	if ( this->key == GLFW_KEY_DOWN )
		return (80);
	return ( this->key );
}

void		OpenglLib::refresh( void )
{
	glClear(GL_COLOR_BUFFER_BIT);
}
