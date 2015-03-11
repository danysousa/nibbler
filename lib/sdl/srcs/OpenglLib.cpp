/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:11:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/11 15:33:38 by dsousa           ###   ########.fr       */
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

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->win = glfwCreateWindow( this->width, this->height, "OpenGL", nullptr, nullptr );
	glfwMakeContextCurrent(this->win);
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
	// glClear(GL_COLOR_BUFFER_BIT);
	/* Swap front and back buffers */
	glfwSwapBuffers(this->win);

	/* Poll for and process events */
	// glfwPollEvents();
}
