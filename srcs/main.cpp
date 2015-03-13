/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:23:20 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/13 13:32:15 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <CoreEngine.hpp>

static void		ft_usage( void )
{
	std::cout << "Usage : ./nibbler [width] [height] [difficulty] [lib name]" << std::endl;

	return ;
}

static int		ft_check_params( char *str )
{
	for ( int i = 0; str[i] != '\0'; i++ )
	{
		if ( !isdigit( str[i] ) )
		{
			ft_usage();
			return ( 1 );
		}
	}
	if ( atoi( str ) < 10 )
	{
		std::cout << "Map is too small" << std::endl;
		return ( 1 );
	}
	if ( atoi( str ) > 73 )
	{
		std::cout << "Map is too large" << std::endl;
		return ( 1 );
	}
	return ( 0 );
}

int main( int argc, char **argv )
{
	std::string		lib_name;
	int				difficulty;
	int				i = 0;

	srand(time(NULL));
	if ( argc < 3 )
		ft_usage();
	else
	{
		if ( ft_check_params( argv[1] ) == 0 && ft_check_params( argv[2] ) == 0 )
		{
			difficulty = 3;
			if ( argc > 3 )
			{
				while ( argv[3][i] != '\0')
				{
					if ( !isdigit(argv[3][i]) || i > 2)
					{
						ft_usage();
						return (0);
					}
					i++;
				}
				difficulty = atoi( argv[3] );
			}

			if ( argc < 5 )
				lib_name = "sdl";
			else
				lib_name = argv[4];

			if ( lib_name.compare( "opengl" ) != 0 && lib_name.compare( "sdl" ) != 0 && lib_name.compare( "ncurses" ) != 0 )
			{
				std::cout << lib_name << " no exist : you can use 'opengl', 'sdl' or 'ncurses'" << std::endl;
				return (0);
			}
			CoreEngine	core = CoreEngine( static_cast<int>( atoi(argv[1]) ), static_cast<int>( atoi(argv[2]) ), lib_name, difficulty );
			core.loop();
		}
	}

	return 0;
}
