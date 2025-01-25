#include "Account.hpp"

#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return Account::_nbAccounts; };

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts;
    Account::_nbAccounts++;

    this->_nbWithdrawals = 0;
    this->_nbDeposits = 0;

    if (initial_deposit > 0) {
        this->_amount = initial_deposit;
        Account::_totalAmount += initial_deposit;
    } else {
        this->_amount = 0;
    }
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "crated" << std::endl;
}

Account::~Account() {
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    int previousAmount = this->_amount;

    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << previousAmount << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << this->_amount << ";"
              << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (this->_amount - withdrawal < 0) {
        std::cout << "index:" << this->_accountIndex << ";"
                  << "p_amount:" << this->_amount << ";"
                  << "withdrawal:refused" << std::endl;
        return false;
    }

    int previousAmount = this->_amount;

    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << previousAmount << ";"
              << "withdrawal:" << withdrawal << ";"
              << "amount:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const { return this->_amount; };
