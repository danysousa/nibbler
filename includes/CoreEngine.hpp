/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:59:51 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/09 11:32:54 by nschilli         ###   ########.fr       */
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
		CoreEngine( int width, int height );
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
