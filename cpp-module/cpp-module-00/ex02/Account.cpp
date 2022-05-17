// [19920104_091532] index:0;amount:42;created
#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp(void)
{
	// std::cout << "[19920104_091532] ";
	char	buffer[19];
	time_t	now;
	struct tm	*timeinfo;
	
	time(&now);
	timeinfo = localtime(&now);
	strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	//[19920104_091532] index:0;p_amount:47;withdrawal:refused
	//[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount){
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return true;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}