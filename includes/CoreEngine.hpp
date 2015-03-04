/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:59:51 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/04 17:24:33 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREENGINE_HPP
# define COREENGINE_HPP
# include <GameEngine.hpp>

class CoreEngine
{
	public:

		/*
		** CONSTRUCT & DESTRUCT
		*/
		CoreEngine( void );
		CoreEngine( CoreEngine const & cpy );
		~CoreEngine( void );

		/*
		** OPERATOR
		*/
		CoreEngine operator=( CoreEngine const & cpy );

		/*
		** METHOD
		*/
		void			loop(void);

	private:
		GameEngine		*gameEngine;
		int				start;
		clock_t			timeStart;
		clock_t			timeEnd;
};

#endif
