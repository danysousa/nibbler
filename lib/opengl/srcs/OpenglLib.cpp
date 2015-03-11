/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 16:13:41 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenglLib.hpp>

int		OpenglLib::key = 0;

void		key_callback(GLFWwindow*, int key, int, int action, int )
{
	if ( action == GLFW_PRESS )
		OpenglLib::key = key;
}

OpenglLib::OpenglLib( int width, int height ) : width(width), height(height)
{
	if ( !glfwInit() )
		exit( EXIT_FAILURE );

	this->win = glfwCreateWindow( this->width, this->height, "OpenGL", nullptr, nullptr );
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



void		OpenglLib::drawSquare( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
	glBegin(GL_QUADS);
		glVertex2d(-0.5,-0.5);
		glVertex2d(-0.5,0.5);
		glVertex2d(0.5,0.5);
		glVertex2d(0.5,-0.5);
	glEnd();

}

void		OpenglLib::drawCircle( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
	float vertices[] = {
		 0.0f,  0.5f, // Vertex 1 (X, Y)
		 0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void		OpenglLib::drawTriangle( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
	float vertices[] = {
		 0.0f,  0.5f, // Vertex 1 (X, Y)
		 0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void		OpenglLib::drawBlock( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
	float vertices[] = {
		 0.0f,  0.5f, // Vertex 1 (X, Y)
		 0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void		OpenglLib::drawEmpty( int x, int y , int color )
{
	(void)color;
	(void)x;
	(void)y;
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
