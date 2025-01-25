#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

void printProperty(const std::string property) {
    std::string toPrint =
        property.length() >= 10 ? property.substr(0, 9) + "." : property;

    std::cout << std::setw(10) << toPrint;
}

int handleIndexPrompt() {
    unsigned int i;

    while (true) {
        std::cout << "Enter index:\n> ";
        std::cin >> i;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return i;
        }
    }
}

void handleSearch(PhoneBook &phoneBook) {
    if (phoneBook.numberOfContacts == 0) {
        std::cerr << "Contact list is empty\n";
        return;
    }

    for (size_t i = 0; i < phoneBook.numberOfContacts; i++) {
        Contact &contact = phoneBook.getContactByIndex(i);
        std::cout << std::setw(10) << i;
        std::cout << '|';
        printProperty(contact.firstName);
        std::cout << '|';
        printProperty(contact.lastName);
        std::cout << '|';
        printProperty(contact.nickName);
        std::cout << '\n';
    }

    try {
        int i = handleIndexPrompt();

        Contact &contact = phoneBook.getContactByIndex(i);
        contact.printContact();
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }
}

std::string getInput(const std::string prompt) {
    std::string input;

    while (input.empty()) {
        std::cout << prompt << "\n> ";
        getline(std::cin, input);
    }
    return input;
}

void handleAdd(PhoneBook &phoneBook) {
    std::string firstName, lastName, nickName, phoneNumber, secret;

    firstName = getInput("Enter first name:");
    lastName = getInput("Enter last name:");
    nickName = getInput("Enter nick name:");
    phoneNumber = getInput("Enter phone number:");
    secret = getInput("Enter secret:");

    std::unique_ptr<Contact> newContact(
        new Contact(firstName, lastName, nickName, phoneNumber, secret));
    phoneBook.addContact(std::move(newContact));
}

int main() {
    std::string input;
    PhoneBook phoneBook;

    std::cout << "Commands: ADD, SEARCH, EXIT\n";
    while (true) {
        std::cout << "Enter command\n> ";
        getline(std::cin, input);
        if (input == "EXIT") {
            break;
        } else if (input == "ADD") {
            handleAdd(phoneBook);
        } else if (input == "SEARCH") {
            handleSearch(phoneBook);
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT."
                      << std::endl;
        }
    }
}
