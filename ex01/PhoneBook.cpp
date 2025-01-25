#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>

#include "Contact.hpp"

void PhoneBook::addContact(std::unique_ptr<Contact> &newContact) {
    int i = this->numberOfContacts;
    if (i >= 8) {
        int oldestContact = this->oldestContact;

        this->contacts[oldestContact] = std::move(newContact);
        oldestContact + 1 < 8 ? this->oldestContact++ : this->oldestContact = 0;
    } else {
        this->contacts[i] = std::move(newContact);
        this->numberOfContacts++;
    }
}

Contact &PhoneBook::getContactByIndex(const unsigned int i) const {
    if (i >= 8) {
        throw std::invalid_argument("Index is out of bounds\n");
    }

    if (i >= this->numberOfContacts) {
        throw std::invalid_argument("Contact doesn't exist\n");
    }

    return *this->contacts[i];
}

void PhoneBook::printContactOverview() const {
    for (size_t i = 0; i < this->numberOfContacts; i++) {
        auto contact = this->getContactByIndex(i);

        std::cout << std::setw(10) << i << '|';
        contact.printOverview();
    }
}
