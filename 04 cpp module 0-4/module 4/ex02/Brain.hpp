/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:32:35 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 16:54:39 by mdiraga          ###   ########.fr       */
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
                    Brain(const Brain& brain);

    std::string*    getIdeas( void );
    void            setIdea( std::string idea );
    Brain&          operator=(const Brain& brain);

};
