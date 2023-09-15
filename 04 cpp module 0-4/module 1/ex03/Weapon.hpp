/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:27:04 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/14 14:27:05 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
private:
    std::string _type;

public:
    Weapon(std::string tmpName);
    Weapon();

    const std::string   &getType();
    void                setType(std::string _newType);

    ~Weapon();
};
