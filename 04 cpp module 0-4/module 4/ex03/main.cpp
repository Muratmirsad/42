/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:46:12 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/21 10:48:29 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include <iostream>
#include <string>

class ICharacter;
class AMateria;
class IMateriaSource;

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const &type) : type(type) {}
    virtual ~AMateria() {}

    std::string const &getType() const { return type; }
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target) = 0;
};

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};

class Ice : public AMateria
{
public:
    Ice() : AMateria("ice") {}

    AMateria *clone() const
    {
        return new Ice(*this);
    }

    void use(ICharacter &target);
};

class Cure : public AMateria
{
public:
    Cure() : AMateria("cure") {}

    AMateria *clone() const
    {
        return new Cure(*this);
    }

    void use(ICharacter &target);
};

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];

public:
    Character(std::string name) : name(name)
    {
        for (int i = 0; i < 4; ++i)
        {
            inventory[i] = nullptr;
        }
    }

    ~Character()
    {
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
        }
    }

    std::string const &getName() const
    {
        return name;
    }

    void equip(AMateria *m)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (inventory[i] == nullptr)
            {
                inventory[i] = m->clone();
                break;
            }
        }
    }

    void unequip(int idx)
    {
        if (idx >= 0 && idx < 4 && inventory[idx] != nullptr)
        {
            inventory[idx] = nullptr;
        }
    }

    void use(int idx, ICharacter &target)
    {
        if (idx >= 0 && idx < 4 && inventory[idx] != nullptr)
        {
            inventory[idx]->use(target);
        }
    }
};

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *m) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource
{
private:
    AMateria *learnedMaterias[4];
    int learnedCount;

public:
    MateriaSource() : learnedCount(0)
    {
        for (int i = 0; i < 4; ++i)
        {
            learnedMaterias[i] = nullptr;
        }
    }

    ~MateriaSource()
    {
        for (int i = 0; i < 4; ++i)
        {
            delete learnedMaterias[i];
        }
    }

    void learnMateria(AMateria *m)
    {
        if (learnedCount < 4)
        {
            learnedMaterias[learnedCount++] = m->clone();
        }
    }

    AMateria *createMateria(std::string const &type)
    {
        for (int i = 0; i < learnedCount; ++i)
        {
            if (learnedMaterias[i]->getType() == type)
            {
                return learnedMaterias[i]->clone();
            }
        }
        return nullptr;
    }
};

int main()
{
    IMateriaSource *source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = source->createMateria("ice");
    me->equip(tmp);
    tmp = source->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete source;

    return 0;
}
