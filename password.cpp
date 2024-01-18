#include <iostream>
#include <time.h>

void generatePassword(int passwordLenght);

int main(){
    int passwordLenght;
    std::cout << "************************************\n";
    std::cout << "\t Password generator \n";
    std::cout << "************************************\n";
    std::cout << "Enter the size of the password: ";
    std::cin >> passwordLenght;

    std::cout << "\n";

    generatePassword(passwordLenght);


    return 0;   
}

void generatePassword(int passwordLenght){
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*_+-=.";
    char password[passwordLenght];
    srand(time(NULL));
    for(int i = 0; i < passwordLenght; i++){
        password[i] = letters[rand() % 80];
        std::cout << password[i];
    }
    std::cout << "\n";

    
}