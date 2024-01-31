#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
 //   std::cout << "Default constructor called." << std::endl;
    return ;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:\033[0;35m" << _accountIndex << "\033[0m";
    std::cout << ";amount:\033[0;35m" << initial_deposit << "\033[0m";
    std::cout << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount = _totalAmount + initial_deposit;
//    std::cout << "Constructor called." << std::endl;
    return ;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:\033[0;35m" << _accountIndex << "\033[0m";
    std::cout << ";amount:\033[0;35m" << _amount << "\033[0m";
    std::cout << ";closed" << std::endl;
//    std::cout << "Destructor called." << std::endl;
    return ;
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:\033[0;35m" << getNbAccounts() << "\033[0m";
    std::cout << ";total:\033[0;35m" << getTotalAmount() << "\033[0m";
    std::cout << ";deposits:\033[0;35m" << getNbDeposits() << "\033[0m";
    std::cout << ";withdrawals:\033[0;35m" << getNbWithdrawals() << "\033[0m" << std::endl;
    return ;
}

void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:\033[0;35m" << _accountIndex << "\033[0m";
    std::cout << ";p_amount:\033[0;35m" << _amount << "\033[0m";
    std::cout << ";deposit:\033[0;35m" << deposit << "\033[0m";

    _amount = _amount + deposit;
    _totalAmount = _totalAmount + deposit;

    std::cout << ";amount:\033[0;35m" << _amount << "\033[0m";
    std::cout << ";nb_deposits:\033[0;35m" << _nbDeposits << "\033[0m" << std::endl;

    return ;
}

int Account::checkAmount() const
{
    return (_amount);
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:\033[0;35m" << _accountIndex << "\033[0m";
        std::cout << ";p_amount:\033[0;35m" << _amount << "\033[0m";
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }

    _nbWithdrawals++;
    _totalNbWithdrawals++;

    _displayTimestamp();
    std::cout << "index:\033[0;35m" << _accountIndex << "\033[0m";
    std::cout << ";p_amount:\033[0;35m" << _amount << "\033[0m";
    std::cout << ";withdrawal:\033[0;35m" << withdrawal << "\033[0m";

    _amount = _amount - withdrawal;
    _totalAmount = _totalAmount - withdrawal;

    std::cout << ";amount:\033[0;35m" << _amount << "\033[0m";
    std::cout << ";nb_withdrawals:\033[0;35m" << _nbDeposits << "\033[0m" << std::endl;

    return (true);

}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:\033[0;35m" << _accountIndex << "\033[0m";
    std::cout << ";amount:\033[0;35m" << _amount << "\033[0m";
    std::cout << ";deposits:\033[0;35m" << _nbDeposits << "\033[0m";
    std::cout << ";withdrawals:\033[0;35m" << _nbWithdrawals << "\033[0m" << std::endl;
    return ;
}

void Account::_displayTimestamp()
{
    std::time_t currentTime = std::time(0);
    std::tm*    getTime = std::localtime(&currentTime);

    std::cout << "[" << getTime->tm_year + 1900;
    std::cout << getTime->tm_mon;
    std::cout << getTime->tm_mday;
    std::cout << '_' << getTime->tm_hour;
    std::cout << getTime->tm_min;
    std::cout << getTime->tm_sec << "] ";

    return ;
}