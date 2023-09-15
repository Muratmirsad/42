/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:16:13 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/15 19:11:08 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

replace::replace(std::string fileName, std::string avS1, std::string avS2)
{
    this->inFile.open(fileName);
    this->outFile.open(fileName + ".replace");
    this->s1 = avS1;
    this->s2 = avS2;
}

replace::~replace()
{
    
}

void    replace::findAndWrite()
{
    std::string line;
    int         i;
    int         j;

    while(getline(this->inFile, line))
    {
        i = 0;
        while (line[i])
        {
            j = 0;
            while (line[i] == this->s1[j])
            {
                i++;
                j++;
                if (!line[i])
                {
                    
                    break;
                }
            }
            
            i++;
        }
    }
}
