#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "string"

class Contact {
   public:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string secret;
    Contact(const std::string &fName, const std::string &lName,
            const std::string &pNumber, const std::string &nickName,
            const std::string &secret);
    void printContact();
};

#endif
