#include "Contact.hpp"

#include <iostream>

Contact::Contact(const std::string& fName, const std::string& lName,
                 const std::string& pNumber, const std::string& nName,
                 const std::string& sec) {
    firstName = fName;
    lastName = lName;
    phoneNumber = pNumber;
    nickName = nName;
    secret = sec;
}

void Contact::printContact() {
    std::cout << this->firstName << '\n';
    std::cout << this->lastName << '\n';
    std::cout << this->phoneNumber << '\n';
    std::cout << this->nickName << '\n';
    std::cout << this->secret << '\n';
}
