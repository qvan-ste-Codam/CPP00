#include "iostream"
#include "string"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg;

        arg = argv[i];
        for (char c : arg) {
            std::cout << static_cast<char>(std::toupper(c));
        }
    }
    std::cout << std::endl;
}
