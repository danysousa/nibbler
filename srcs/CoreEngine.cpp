/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:45:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/03 14:53:27 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CoreEngine.hpp>
#include <iostream>

/*
** CONSTRUCT & DESTRUCT
*/
CoreEngine::CoreEngine( void )
{
	std::cout << "ok" << std::endl;
	return ;
}
CoreEngine::CoreEngine( CoreEngine const & cpy )
{
	*this = cpy;
}
CoreEngine::~CoreEngine( void )
{
	return ;
}

/*
** OPERATOR
*/
CoreEngine		CoreEngine::operator=( CoreEngine const & cpy )
{
	return cpy;
}

/*
** METHOD
*/
