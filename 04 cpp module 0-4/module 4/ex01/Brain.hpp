/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:32:35 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 18:19:34 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
private:
    std::string _ideas[100];
   
public:
                    Brain( void );
                    ~Brain( void );
                    Brain( const Brain& cpy );

    Brain&          operator=( const Brain& cpy );
    std::string*    getIdeas( void );
    void            setIdea( std::string idea );
};
