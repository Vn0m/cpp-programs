#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{

    double balance = 0;
    int choices = 0;

    do
    {
        std::cout << "********************************* \n";
        std::cout << "What would you like to do today? \n";
        std::cout << "********************************* \n";
        std::cout << "1. Show balance \n";
        std::cout << "2. Deposit \n";
        std::cout << "3. Withdraw \n";
        std::cout << "4. Exit \n";
        std::cin >> choices;

        std::cin.clear();
        fflush(stdin);

        switch (choices)
        {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            showBalance(balance);
            break;
        case 3:
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
            std::cout << "Thanks for visiting! \n";
            break;
        default:
            std::cout << "Invalid choice! \n";
        }
    } while (choices != 4);

    return 0;
}

void showBalance(double balance)
{
    std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

double deposit()
{

    double amount = 0;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;

    if (amount > 0)
    {
        return amount;
    }
    else
    {
        std::cout << "Invalid amount! \n";
        return 0;
    }
}

double withdraw(double balance)
{

    double amount = 0;
    std::cout << "Enter withdraw amount: ";
    std::cin >> amount;

    if (amount > balance)
    {
        std::cout << "Insufficient funds! \n";
        return 0;
    }
    else if (amount < 0)
    {
        std::cout << "Invalid amount! \n";
        return 0;
    }
    else
    {
        return amount;
    }
}