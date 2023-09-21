/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:16:13 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/16 17:37:53 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

replace::replace(std::string fileName, std::string avS1, std::string avS2)
{
    this->inFile.open(fileName.c_str());
    if (!this->inFile.is_open())
    {
        std::cout << "file error" << std::endl;
        return ;
    }
    this->outFile.open((fileName + ".replace").c_str());
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
    int         k;

    while(getline(this->inFile, line))
    {
        i = 0;
        while (line[i])
        {
            j = 0;
            k = 0;
            while (line[i] == this->s1[j])
            {
                k = i;
                i++;
                j++;
                if (!this->s1[j])
                {
                    j = 0;
                    while (s2[j])
                        this->outFile << this->s2[j++];
                    k = -1;
                    break;
                }
            }
            if (k == -1)
                continue;
            if (k > 0)
                i = k;
            this->outFile << line[i];
            i++;
        }
        this->outFile << std::endl;
    }
}
