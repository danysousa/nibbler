/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:23:20 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/06 10:19:22 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <CoreEngine.hpp>

static void		ft_usage( void )
{
	std::cout << "Usage : ./nibbler [width] [height]" << std::endl;

	return ;
}

int main( int argc, char **argv )
{
	srand(time(NULL));
	if ( argc != 3 )
		ft_usage();
	else
	{
		CoreEngine	core = CoreEngine( static_cast<int>( atoi(argv[1]) ), static_cast<int>( atoi(argv[2]) ) );
		core.loop();
	}



	return 0;
}
