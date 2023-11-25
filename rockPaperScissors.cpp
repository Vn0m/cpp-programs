#include <iostream>
#include <ctime>

char userChoice();
char computerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main()
{

    char player;
    char computer;

    player = userChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    computer = computerChoice();
    std::cout << "Computers choice: ";
    showChoice(computer);

    chooseWinner(player, computer);

    return 0;
}

char userChoice()
{

    char player;

    do
    {
        std::cout << "************************* \n";
        std::cout << "Rock-Paper-Scissors Game! \n";
        std::cout << "************************* \n";

        std::cout << "r for rock \n";
        std::cout << "p for paper \n";
        std::cout << "s for scissors \n";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char computerChoice(){

    srand(time(NULL));
    int num = rand() % 3 + 1;

    switch(num){
        case 1:
            return 'r';
        case 2:
            return 'p';
        case 3:
            return 's';
    }

    return 0;
}

void showChoice(char choice){

    switch(choice){
        case 'r':
            std::cout << "Rock \n";
            break;
        case 'p':
            std::cout << "Paper \n";
            break;
        case 's':
            std::cout << "Scissors \n";
            break;
    }
}

void chooseWinner(char player, char computer){

    switch(player){
        case 'r':
            if(computer == 'r'){
                std::cout << "its a tie! \n";
            } else if (computer == 'p'){
                std::cout << "you lose! \n";
            } else{
                std::cout << "you win! \n";
            }
            break;
        case 'p':
            if(computer == 'r'){
                std::cout << "you win! \n";
            } else if (computer == 'p'){
                std::cout << "its a tie! \n";
            } else{
                std::cout << "you lose! \n";
            }
            break;
        case 's':
            if(computer == 'r'){
                std::cout << "you lose! \n";
            } else if (computer == 'p'){
                std::cout << "you win! \n";
            } else{
                std::cout << "its a tie! \n";
            }
            break;
    }
}