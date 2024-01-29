/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:32:35 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/29 14:37:28 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
private:
    std::string *_ideas;
   
public:
    Brain( void );
    ~Brain( void );

    std::string*    Brain::getIdeas( void );
    void            Brain::setIdea( std::string idea );

};
