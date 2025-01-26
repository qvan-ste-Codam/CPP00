#include <iostream>
#include <limits>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int handleIndexPrompt() {
    unsigned int i;

    while (true) {
        std::cout << "Enter index:\n> ";
        std::cin >> i;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer."
                      << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return i;
        }
    }
}

void handleSearch(const PhoneBook &phoneBook) {
    phoneBook.printContactOverview();
    try {
        unsigned int i = handleIndexPrompt();

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
    auto newContact = std::make_unique<Contact>(firstName, lastName, nickName,
                                                phoneNumber, secret);
    phoneBook.addContact(newContact);
}

int main() {
    std::string input;
    PhoneBook phoneBook;

    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
    while (true) {
        input = getInput("Enter command");
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
