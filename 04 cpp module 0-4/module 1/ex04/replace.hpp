/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:24:15 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/21 17:24:16 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>

class replace
{
private:
    std::ifstream   inFile;
    std::ofstream   outFile;
    std::string     s1;
    std::string     s2;

public:
    replace(std::string fileName, std::string avS1, std::string avS2);
    ~replace();

    void    findAndWrite();
};