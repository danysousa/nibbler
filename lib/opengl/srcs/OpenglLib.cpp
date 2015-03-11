/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 18:38:37 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenglLib.hpp>

int		OpenglLib::key = 0;

void		key_callback(GLFWwindow*, int key, int, int action, int )
{
	if ( action == GLFW_PRESS )
		OpenglLib::key = key;
}

OpenglLib::OpenglLib( int width, int height ) : width(width * 3), height(height * 3)
{
	if ( !glfwInit() )
		exit( EXIT_FAILURE );

	this->win = glfwCreateWindow( this->width + 10, this->height + 10, "OpenGL", nullptr, nullptr );
	glfwMakeContextCurrent(this->win);
	glfwSetKeyCallback( this->win, key_callback );
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


double		OpenglLib::adaptX(double x)
{
	x = ( x * 3.0 + 1.5) / ( static_cast<double>(this->width) / 2.0 );
	x = x - 1;

	return (x);
}

double		OpenglLib::adaptY(double y)
{
	y = ( y * 3.0 + 1.5) / ( static_cast<double>(this->height) / 2.0 );
	y = -y + 1;

	return (y);
}

void		OpenglLib::drawSquare( int x, int y , int color )
{
	(void)color;
	glBegin(GL_QUADS);
		glVertex2d(this->adaptX(x - 0.8), this->adaptY(y - 0.8));
		glVertex2d(this->adaptX(x - 0.8), this->adaptY(y + 0.8));
		glVertex2d(this->adaptX(x + 0.8), this->adaptY(y + 0.8));
		glVertex2d(this->adaptX(x + 0.8), this->adaptY(y - 0.8));
	glEnd();

}

void		OpenglLib::drawCircle( int x, int y , int color )
{
	(void)color;
	double		angle;
	double		tmp_x;
	double		tmp_y;

	glBegin(GL_POLYGON);
	for ( int i = 0; i <= 300; i++ )
	{
		angle = 2.0 * 3.14159265 * i / 300.0;
		tmp_x = cos(angle) * 0.8;
		tmp_y = sin(angle) * 0.8;
		glVertex2d( this->adaptX( tmp_x + static_cast<double>(x) ), this->adaptY( tmp_y + static_cast<double>(y) ) );
	}
	glEnd();

}

void		OpenglLib::drawTriangle( int x, int y , int color )
{
	(void)color;
	double		angle;
	double		tmp_x;
	double		tmp_y;

	glBegin(GL_POLYGON);
	for ( int i = 0; i <= 300; i++ )
	{
		angle = 2.0 * 3.14159265 * i / 300.0;
		tmp_x = cos(angle) * 0.8;
		tmp_y = sin(angle) * 0.8;
		glVertex2d( this->adaptX( tmp_x + static_cast<double>(x) ), this->adaptY( tmp_y + static_cast<double>(y) ) );
	}
	glEnd();

}

void		OpenglLib::drawBlock( int x, int y , int color )
{
	(void)color;
	glBegin(GL_QUADS);
		glVertex2d(this->adaptX(x - 0.8), this->adaptY(y - 0.8));
		glVertex2d(this->adaptX(x - 0.8), this->adaptY(y + 0.8));
		glVertex2d(this->adaptX(x + 0.8), this->adaptY(y + 0.8));
		glVertex2d(this->adaptX(x + 0.8), this->adaptY(y - 0.8));
	glEnd();
}

void		OpenglLib::drawEmpty( void )
{
	glClear(GL_COLOR_BUFFER_BIT);
}

int		OpenglLib::keyPressed( void )
{
	if ( OpenglLib::key == GLFW_KEY_ESCAPE || glfwWindowShouldClose(this->win) )
	{
		glfwDestroyWindow(this->win);
		glfwTerminate();
		exit(0);
	}
	if ( OpenglLib::key == GLFW_KEY_LEFT )
		return ( 20 );
	if ( OpenglLib::key == GLFW_KEY_RIGHT )
		return ( 40 );
	if ( OpenglLib::key == GLFW_KEY_UP )
		return ( 60 );
	if ( OpenglLib::key == GLFW_KEY_DOWN )
		return (80);
	return ( OpenglLib::key );
}

void		OpenglLib::refresh( void )
{
	// glClear(GL_COLOR_BUFFER_BIT);
	/* Swap front and back buffers */
	glfwSwapBuffers(this->win);
	glfwPollEvents();

	/* Poll for and process events */
}
