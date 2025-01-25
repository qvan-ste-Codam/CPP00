#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
   public:
    Contact(const std::string &_firstName, const std::string &_lastName,
            const std::string &_nickName, const std::string &_phoneNumber,
            const std::string &_secret);
    void printContact() const;
    void printOverview() const;

   private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string secret;
};

#endif
