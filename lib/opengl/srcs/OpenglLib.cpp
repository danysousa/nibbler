/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/13 14:44:17 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenglLib.hpp>

int		OpenglLib::key = 0;

void		key_callback(GLFWwindow*, int key, int, int action, int )
{
	if ( action == GLFW_PRESS )
		OpenglLib::key = key;
}

OpenglLib::OpenglLib( int width, int height ) : width(width * ZOOM), height(height * ZOOM)
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
	x = ( x * ZOOM + 1.5) / ( static_cast<double>(this->width) / 2.0 );
	x = x - 1;

	return (x);
}

double		OpenglLib::adaptY(double y)
{
	y = ( y * ZOOM + 1.5) / ( static_cast<double>(this->height) / 2.0 );
	y = -y + 1;

	return (y);
}

void		OpenglLib::drawSquare( int x, int y , int )
{
	glColor3f(0.88f, 0.1f, 0.5f);
	glBegin(GL_QUADS);
		glVertex2d(this->adaptX(x - ( ZOOM / 15 )), this->adaptY(y - ( ZOOM / 15 )));
		glVertex2d(this->adaptX(x - ( ZOOM / 15 )), this->adaptY(y + ( ZOOM / 15 )));
		glVertex2d(this->adaptX(x + ( ZOOM / 15 )), this->adaptY(y + ( ZOOM / 15 )));
		glVertex2d(this->adaptX(x + ( ZOOM / 15 )), this->adaptY(y - ( ZOOM / 15 )));
	glEnd();

}

void		OpenglLib::drawCircle( int x, int y , int )
{
	double		angle;
	double		tmp_x;
	double		tmp_y;

	glColor3f(0.25f, 0.6f, 1.0f);
	glBegin(GL_POLYGON);
	for ( int i = 0; i <= 300; i++ )
	{
		angle = 2.0 * 3.14159265 * i / 300.0;
		tmp_x = cos(angle) * ( ZOOM / 15 );
		tmp_y = sin(angle) * ( ZOOM / 15 );
		glVertex2d( this->adaptX( tmp_x + static_cast<double>(x) ), this->adaptY( tmp_y + static_cast<double>(y) ) );
	}
	glEnd();

}

void		OpenglLib::drawTriangle( int x, int y , int )
{
	double		angle;
	double		tmp_x;
	double		tmp_y;

	glColor3f(0.0f, 1.0f, 0.8f);
	glBegin(GL_POLYGON);
	for ( int i = 0; i <= 300; i++ )
	{
		angle = 2.0 * 3.14159265 * i / 300.0;
		tmp_x = cos(angle) * ( ZOOM / 15 );
		tmp_y = sin(angle) * ( ZOOM / 15 );
		glVertex2d( this->adaptX( tmp_x + static_cast<double>(x) ), this->adaptY( tmp_y + static_cast<double>(y) ) );
	}
	glEnd();

}

void		OpenglLib::drawBlock( int x, int y , int )
{

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2d(this->adaptX(x - ( ZOOM / 15 )), this->adaptY(y - ( ZOOM / 15 )));
		glVertex2d(this->adaptX(x - ( ZOOM / 15 )), this->adaptY(y + ( ZOOM / 15 )));
		glVertex2d(this->adaptX(x + ( ZOOM / 15 )), this->adaptY(y + ( ZOOM / 15 )));
		glVertex2d(this->adaptX(x + ( ZOOM / 15 )), this->adaptY(y - ( ZOOM / 15 )));
	glEnd();
}

void		OpenglLib::drawEmpty( void )
{
	glClear(GL_COLOR_BUFFER_BIT);
}

int		OpenglLib::keyPressed( void )
{
	if ( OpenglLib::key == GLFW_KEY_ESCAPE || glfwWindowShouldClose(this->win) )
		return ( -1 );
	if ( OpenglLib::key == GLFW_KEY_SPACE )
		return ( 42 );
	if ( OpenglLib::key == GLFW_KEY_LEFT )
		return ( 20 );
	if ( OpenglLib::key == GLFW_KEY_RIGHT )
		return ( 40 );
	if ( OpenglLib::key == GLFW_KEY_UP )
		return ( 60 );
	if ( OpenglLib::key == GLFW_KEY_DOWN )
		return (80);
	if ( OpenglLib::key == GLFW_KEY_1 || OpenglLib::key == GLFW_KEY_KP_1 )
		return ( 1 );
	if ( OpenglLib::key == GLFW_KEY_2 || OpenglLib::key == GLFW_KEY_KP_2 )
		return ( 2 );
	if ( OpenglLib::key == GLFW_KEY_3 || OpenglLib::key == GLFW_KEY_KP_3 )
		return ( 3 );
	return ( 0 );
}

void		OpenglLib::score( int )
{
	return ;
}

void	OpenglLib::end( void )
{
	glfwDestroyWindow(this->win);
	glfwTerminate();
}

void		OpenglLib::refresh( void )
{
	this->key = 0;
	glfwSwapBuffers(this->win);
	glfwPollEvents();
}
