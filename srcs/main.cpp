/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:23:20 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 11:38:50 by dsousa           ###   ########.fr       */
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

int main( void )
{
	srand(time(NULL));
	ft_usage();
	CoreEngine	core = CoreEngine();
	core.loop();

	return 0;
}
