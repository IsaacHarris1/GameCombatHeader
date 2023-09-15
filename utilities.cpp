#include "utilities.h"

void clearScreen() {
    system("clear");
}

int basicD20Roll() {
    int d20 = 0;
    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(1, 20);
    d20 = dist(rng);
    return d20;
}

int inputValidation() {
    int input;
    while (true) {
        if (std::cin >> input) {
            break;
        }
        std::cout << "Invalid input, try again" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

char inputCharValidation() {
    char inputChar;
    while (true) {
        if (std::cin >> inputChar) {
            break;
        }
        std::cout << "Not a character, try again" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return inputChar;
}

int rollHelper(int amountRoll, std::mt19937& rng, std::uniform_int_distribution<int>& dist) {
    int rollTotal = 0;
    int diceRoll = 0;
    for (int i = 0; i < amountRoll; i++) {
        diceRoll = dist(rng);
        rollTotal += diceRoll;
        std::cout << "Total roll: " << rollTotal << std::endl;
    }
    return rollTotal;
}

int diceRoll() {
    std::mt19937 rng(std::time(nullptr));
    std::string diceChoice;
    int diceConvert;
    int amountRoll;
    int rollTotal = 0;
    std::cout << "What type of dice would you like me to roll? ex(d4)" << std::endl;
    std::cin >> diceChoice;

    diceConvert = std::stoi(diceChoice.substr(1));

    std::uniform_int_distribution<int> dist(1, diceConvert);
    while (true) {
        diceConvert = std::stoi(diceChoice.substr(1));
        switch (diceConvert) {
            case 4:
                std::cout << "How many times shall I roll?" << std::endl;
                std::cin >> amountRoll;
                rollTotal = rollHelper(amountRoll, rng, dist);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 6:
                std::cout << "How many times shall I roll?" << std::endl;
                std::cin >> amountRoll;
                rollTotal = rollHelper(amountRoll, rng, dist);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 8:
                std::cout << "How many times shall I roll?" << std::endl;
                std::cin >> amountRoll;
                rollTotal = rollHelper(amountRoll, rng, dist);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 10:
                std::cout << "How many times shall I roll?" << std::endl;
                std::cin >> amountRoll;
                rollTotal = rollHelper(amountRoll, rng, dist);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 12:
                std::cout << "How many times shall I roll?" << std::endl;
                std::cin >> amountRoll;
                rollTotal = rollHelper(amountRoll, rng, dist);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 20:
                std::cout << "How many times shall I roll?" << std::endl;
                std::cin >> amountRoll;
                rollTotal = rollHelper(amountRoll, rng, dist);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 100:
                std::cout << "How many times shall I roll?" << std::endl;
                std::cin >> amountRoll;
                rollTotal = rollHelper(amountRoll, rng, dist);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            default:
                std::cout << "Invalid dice, please try again" << std::endl;
                std::cin >> diceChoice;
                continue;
        }
        break;
    }
    return rollTotal;
}