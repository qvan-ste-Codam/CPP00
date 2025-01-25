#include "Contact.hpp"

#include <iomanip>
#include <iostream>

Contact::Contact(const std::string &_firstName, const std::string &_lastName,
                 const std::string &_nickName, const std::string &_phoneNumber,
                 const std::string &_secret)
    : firstName(_firstName),
      lastName(_lastName),
      nickName(_nickName),
      phoneNumber(_phoneNumber),
      secret(_secret) {}

void Contact::printContact() const {
    std::cout << this->firstName << '\n'
              << this->lastName << '\n'
              << this->nickName << '\n'
              << this->phoneNumber << '\n'
              << this->secret << std::endl;
}

static std::string getFormattedProperty(const std::string &property) {
    return property.length() >= 10 ? property.substr(0, 9) + "." : property;
}

void Contact::printOverview() const {
    auto firstName = getFormattedProperty(this->firstName);
    auto lastName = getFormattedProperty(this->lastName);
    auto nickName = getFormattedProperty(this->nickName);

    std::cout << std::setw(10) << firstName << '|' << lastName << '|'
              << nickName << std::endl;
}
