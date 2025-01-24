#include "PhoneBook.hpp"

void PhoneBook::addContact(std::unique_ptr<Contact> newContact) {
    int i = this->numberOfContacts;
    if (i >= 8) {
        this->contacts[0] = std::move(newContact);
    } else {
        this->contacts[i] = std::move(newContact);
        this->numberOfContacts++;
    }
}

Contact &PhoneBook::getContactById(int i) {
    if (i >= this->numberOfContacts) {
        throw std::invalid_argument("Index out of bounds\n");
    }
    return *this->contacts[i];
}
