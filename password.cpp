#include <iostream>
#include <time.h>

void generatePassword(int passwordLenght, int complexityLevel);

int main(){
    int passwordLenght;
    int complexityLevel;
    std::cout << "************************************\n";
    std::cout << "\t Password generator \n";
    std::cout << "************************************\n";
    std::cout << "Enter the size of the password: ";
    std::cin >> passwordLenght;
    std::cout << "Enter the level of complexity(1-3): ";
    std::cin >> complexityLevel;

    std::cout << "\n";

    generatePassword(passwordLenght, complexityLevel);


    return 0;   
}

void generatePassword(int passwordLenght, int complexityLevel){
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*_+-=.";
    char password[passwordLenght];
    srand(time(NULL));

    switch(complexityLevel){
        case 1:
            for(int i = 0; i < passwordLenght; i++){
                password[i] = letters[rand() % 26];
                std::cout << password[i];
            }
            break;
        case 2:
            for(int i = 0; i < passwordLenght; i++){
                password[i] = letters[rand() % 52];
                std::cout << password[i];
            }
            break;
        case 3:
            for(int i = 0; i < passwordLenght; i++){
                password[i] = letters[rand() % 75];
                std::cout << password[i];
            }
            break;
        default:
            std::cout << "Invalid option\n";
            break;
    }

    std::cout << "\n";
}