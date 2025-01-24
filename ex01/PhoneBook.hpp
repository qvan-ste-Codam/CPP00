#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include "Contact.hpp"
#include "memory"

class PhoneBook {
   public:
    int numberOfContacts = 0;
    std::unique_ptr<Contact> contacts[8];
    void addContact(std::unique_ptr<Contact> newContact);
    Contact &getContactById(int i);
};

#endif
