#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include <memory>

#include "Contact.hpp"

class PhoneBook {
   public:
    unsigned int numberOfContacts = 0;
    std::unique_ptr<Contact> contacts[8];
    void addContact(std::unique_ptr<Contact> newContact);
    Contact &getContactByIndex(const unsigned int i);

   private:
    int oldestContact = 0;
};

#endif
