/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:23:20 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/06 10:40:55 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <CoreEngine.hpp>

static void		ft_usage( void )
{
	std::cout << "Usage : ./nibbler [width] [height]" << std::endl;

	return ;
}

static int		ft_check_params( char *str )
{
	for ( int i = 0;str[i] != '\0';i++ )
	{
		if ( !isdigit( str[i] ) )
		{
			ft_usage();
			return ( 1 );
		}
	}
	return ( 0 );
}

int main( int argc, char **argv )
{
	srand(time(NULL));
	if ( argc != 3 )
		ft_usage();
	else
	{
		if ( ft_check_params( argv[1] ) == 0 && ft_check_params( argv[2] ) == 0 )
		{
			CoreEngine	core = CoreEngine( static_cast<int>( atoi(argv[1]) ), static_cast<int>( atoi(argv[2]) ) );
			core.loop();
		}
	}

	return 0;
}
