/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 15:01:00 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenglLib.hpp>

int		OpenglLib::key = 0;

void		key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ( action == GLFW_PRESS )
		OpenglLib::key = key;

	static_cast<void>(window);
	static_cast<void>(scancode);
	static_cast<void>(mods);
}

OpenglLib::OpenglLib( int width, int height ) : width(width), height(height)
{
	// glfwSetErrorCallback( error_callback );
	if ( !glfwInit() )
		exit( EXIT_FAILURE );

	this->win = glfwCreateWindow( this->width, this->height, "window", NULL, NULL );

	if ( !this->win )
	{
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	glfwMakeContextCurrent( this->win );
	glfwSetKeyCallback( this->win, key_callback );
	glfwGetFramebufferSize(this->win, &width, &height);
	glViewport(0, 0, width, height);
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



void		OpenglLib::drawSquare( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
	  glBegin(GL_QUADS);
 glVertex2d(2,-1);
 glVertex2d(4,-1);
 glVertex2d(4,1);
 glVertex2d(2,1);
glEnd();
}

void		OpenglLib::drawCircle( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
  glBegin(GL_QUADS);
 glVertex2d(2,-1);
 glVertex2d(4,-1);
 glVertex2d(4,1);
 glVertex2d(2,1);
glEnd();

}

void		OpenglLib::drawTriangle( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
  glBegin(GL_QUADS);
 glVertex2d(2,-1);
 glVertex2d(4,-1);
 glVertex2d(4,1);
 glVertex2d(2,1);
glEnd();
}

void		OpenglLib::drawBlock( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
  glBegin(GL_QUADS);
 glVertex2d(2,-1);
 glVertex2d(4,-1);
 glVertex2d(4,1);
 glVertex2d(2,1);
glEnd();

}

void		OpenglLib::drawEmpty( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
  glBegin(GL_QUADS);
 glVertex2d(2,-1);
 glVertex2d(4,-1);
 glVertex2d(4,1);
 glVertex2d(2,1);
glEnd();
}

int		OpenglLib::keyPressed( void )
{
	if ( this->key == GLFW_KEY_ESCAPE )
	{
		// endwin();
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
	/* Swap front and back buffers */
    glfwSwapBuffers(this->win);

    /* Poll for and process events */
    glfwPollEvents();
}
