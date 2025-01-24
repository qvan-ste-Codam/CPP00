#include <iostream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

void handleAdd(PhoneBook &phoneBook) {
    std::string firstName, lastName, nickName, phoneNumber, secret;

    std::cout << "Enter first name: " << std::endl;
    getline(std::cin, firstName);
    std::cin.ignore();
    std::cout << "Enter last name: " << std::endl;
    getline(std::cin, lastName);
    std::cin.ignore();
    std::cout << "Enter nick name: " << std::endl;
    getline(std::cin, nickName);
    std::cin.ignore();
    std::cout << "Enter phone number: " << std::endl;
    getline(std::cin, phoneNumber);
    std::cin.ignore();
    std::cout << "Enter secret: " << std::endl;
    getline(std::cin, secret);

    std::unique_ptr<Contact> newContact(
        new Contact(firstName, lastName, nickName, phoneNumber, secret));
    phoneBook.addContact(std::move(newContact));
}

void handleSearch(PhoneBook &phoneBook) {
    for (int i = 0; i < phoneBook.numberOfContacts; i++) {
        Contact &contact = *phoneBook.contacts[i];

        std::cout << i << '|' << contact.firstName << '|' << contact.lastName
                  << '|' << contact.nickName << std::endl;
    }
    try {
        int i;

        std::cout << "Enter index: ";
        std::cin >> i;
        Contact &contact = phoneBook.getContactById(i);
        contact.printContact();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main(void) {
    std::string input;
    PhoneBook phoneBook;

    while (input != "EXIT") {
        std::cout << "ADD | SEARCH | EXIT" << std::endl;
        std::cin >> input;

        if (input == "ADD") {
            handleAdd(phoneBook);
        }
        if (input == "SEARCH") {
            handleSearch(phoneBook);
        }
    };
}
