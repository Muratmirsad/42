/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:49:15 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/26 02:24:25 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    
}

Harl::jjsfxfghghjHarl

void  Harl::debug(void)
{
    std::cout << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum. Gerçekten seviyorum!" << std::endl;
}

void  Harl::info(void)
{
    std::cout << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını istemezdim!" << std::endl;
}

void  Harl::warning(void)
{
    std::cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << std::endl;
}

void  Harl::error(void)
{
    std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
}

void  Harl::complain(std::string level)
{
    void        *funcArray[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levelArray[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         i = 0;

    while (i < 4 && levelArray.compare(level))
        *funcArray[i++]();
}
