#include "Contact.hpp"

#include "iostream"

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
    std::cout << this->firstName << std::endl;
    std::cout << this->lastName << std::endl;
    std::cout << this->phoneNumber << std::endl;
    std::cout << this->nickName << std::endl;
    std::cout << this->secret << std::endl;
}
