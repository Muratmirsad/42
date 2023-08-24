/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:21:05 by mdiraga           #+#    #+#             */
/*   Updated: 2023/08/24 03:14:01 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const
{
    return this->_amount;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}
Account::~Account( void )
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
    _nbAccounts--;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;

	this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposit:" << _nbDeposits << std::endl;

}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t result = std::time(NULL);

    std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
	<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
	<<  std::setw(2) << std::localtime(&result)->tm_mday
	<<  "_"
	<<  std::setw(2) << std::localtime(&result)->tm_hour
	<<  std::setw(2) << std::localtime(&result)->tm_min
	<<  std::setw(2) << std::localtime(&result)->tm_sec 
	<< "] ";
}

bool	Account::makeWithdrawal( int withdrawal )
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "withdrawal:" << std::flush;
    if (withdrawal > checkAmount()) {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal << ";";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "amount:" << _amount << ";"
                << "nb_deposit:" << _nbDeposits << std::endl;
    return true;
}