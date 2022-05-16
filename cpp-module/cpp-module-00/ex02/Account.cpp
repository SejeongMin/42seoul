// [19920104_091532] index:0;amount:42;created
#include <Account.hpp>
#include <iostream>

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = _totalAmount++;
	this->_nbDeposits = _totalNbDeposits++;
	this->_nbWithdrawals = _totalNbWithdrawals++;
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
	std::cout << "[19920104_091532] ";
}

void	Account::makeDeposit(int deposit)
{
	
}

void	Account::displayStatus(void) const
{
	//accounts:8;total:21524;deposits:8;withdrawals:0
	this->_displayTimestamp();
}

