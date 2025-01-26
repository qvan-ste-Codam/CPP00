#include "Account.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return Account::_nbAccounts; };

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::_displayTimestamp() {
    const auto now{std::chrono::system_clock::now()};
    const auto now_time_t = std::chrono::system_clock::to_time_t(now);
    const auto now_tm = *std::gmtime(&now_time_t);

    const int year = now_tm.tm_year + 1900;
    const int month = now_tm.tm_mon + 1;
    const int day = now_tm.tm_mday;
    const int hour = now_tm.tm_hour;
    const int minute = now_tm.tm_min;
    const int second = now_tm.tm_sec;

    std::cout << "[" << year << std::setw(2) << std::setfill('0') << month
              << std::setw(2) << std::setfill('0') << day << "_" << std::setw(2)
              << std::setfill('0') << hour << std::setw(2) << std::setfill('0')
              << minute << std::setw(2) << std::setfill('0') << second << "] ";
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
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
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "crated" << std::endl;
}

Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    const int previousAmount = this->_amount;

    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << previousAmount << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << this->_amount << ";"
              << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (this->_amount - withdrawal < 0) {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";"
                  << "p_amount:" << this->_amount << ";"
                  << "withdrawal:refused" << std::endl;
        return false;
    }

    const int previousAmount = this->_amount;

    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << previousAmount << ";"
              << "withdrawal:" << withdrawal << ";"
              << "amount:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const { return this->_amount; };
