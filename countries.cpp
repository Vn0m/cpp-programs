#include <iostream>
#include <string>

struct Destination {
    std::string location;
    std::string description;
    std::string activities;
    double estimatedCost;
    int id;
};

const int MAX_DESTINATIONS = 2;

void addDestination(Destination destinations[], int& destinationCount) {
    if (destinationCount < MAX_DESTINATIONS) {
        std::cin.ignore(); 
        Destination newDestination;

        do {
            std::cout << "Location: ";
            std::getline(std::cin, newDestination.location);
            if (newDestination.location.empty()) {
                std::cout << "Location cannot be empty.\n";
            }
        } while (newDestination.location.empty());

        do {
            std::cout << "Description: ";
            std::getline(std::cin, newDestination.description);
            if (newDestination.description.empty()) {
                std::cout << "Description cannot be empty.\n";
            }
        } while (newDestination.description.empty());

        do {
            std::cout << "Activities: ";
            std::getline(std::cin, newDestination.activities);
            if (newDestination.activities.empty()) {
                std::cout << "Activities cannot be empty.\n";
            }
        } while (newDestination.activities.empty());

        double cost;
        do {
            std::cout << "Estimated Cost: $";
            std::cin >> cost;
            if (cost < 0) {
                std::cout << "Estimated cost cannot be negative.\n";
            }
        } while (cost < 0);
        newDestination.estimatedCost = cost;

        newDestination.id = destinationCount++;
        destinations[newDestination.id] = newDestination;

        std::cout << "Destination added successfully.\n";
    } else {
        std::cout << "Maximum number of destinations reached.\n";
    }
}

void modifyById(Destination destinations[], int destinationCount) {
    int id;
    std::cout << "Enter the ID of the destination you want to modify: ";
    std::cin >> id;

    if (id >= 0 && id < destinationCount) {
        Destination& destination = destinations[id];
        std::cin.ignore(); 

        do {
            std::cout << "Location (previous: " << destination.location << "): ";
            std::getline(std::cin, destination.location);
            if (destination.location.empty()) {
                std::cout << "Location cannot be empty.\n";
            }
        } while (destination.location.empty());

        do {
            std::cout << "Description (previous: " << destination.description << "): ";
            std::getline(std::cin, destination.description);
            if (destination.description.empty()) {
                std::cout << "Description cannot be empty.\n";
            }
        } while (destination.description.empty());

        do {
            std::cout << "Activities (previous: " << destination.activities << "): ";
            std::getline(std::cin, destination.activities);
            if (destination.activities.empty()) {
                std::cout << "Activities cannot be empty.\n";
            }
        } while (destination.activities.empty());

        double cost;
        do {
            std::cout << "Estimated Cost (previous: $" << destination.estimatedCost << "): $";
            std::cin >> cost;
            if (cost < 0) {
                std::cout << "Estimated cost cannot be negative.\n";
            }
        } while (cost < 0);
        destination.estimatedCost = cost;

        std::cout << "Destination modified successfully.\n";
    } else {
        std::cout << "Invalid destination ID.\n";
    }
}

void deleteById(Destination destinations[], int& destinationCount) {
    int id;
    std::cout << "Enter the ID of the destination you want to delete: ";
    std::cin >> id;

    if (id >= 0 && id < destinationCount) {
        for (int i = id; i < destinationCount - 1; ++i) {
            destinations[i] = destinations[i + 1];
            destinations[i].id = i;
        }
        --destinationCount;
        std::cout << "Destination deleted successfully.\n";
    } else {
        std::cout << "Invalid destination ID.\n";
    }
}

void showDestinations(Destination destinations[], int destinationCount){
    if(destinationCount == 0){
        std::cout << "No destinations available....\n";
    } else {
        std::cout << "\n\tTravel Destinations\n";
        for(int i = 0; i < destinationCount; ++i){
            std::cout << "ID: " << destinations[i].id << "\n";
            std::cout << "Location: " << destinations[i].location << "\n";
            std::cout << "Description: " << destinations[i].description << "\n";
            std::cout << "Activities: " << destinations[i].activities << "\n";
            std::cout << "Estimated Cost: $" << destinations[i].estimatedCost << "\n";
        }
    }
}

int main() {
    Destination destinations[MAX_DESTINATIONS];
    int destinationCount = 0;

    char choice;
    do {
        std::cout << "\t Menu \n"
                  << "1. Add travel destination\n"
                  << "2. Modify travel destination\n"
                  << "3. Delete travel destination\n"
                  << "4. Show travel destinations\n"
                  << "5. Exit\n"
                  << "Choose your option: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addDestination(destinations, destinationCount);
                break;
            case '2':
                modifyById(destinations, destinationCount);
                break;
            case '3':
                deleteById(destinations, destinationCount);
                break;
            case '4':
                showDestinations(destinations, destinationCount);
                break;
            case '5':
                std::cout << "Thank you for using!\n";
                break;
            default:
                std::cout << "Invalid option!\n";
                break;
        }
    } while (choice != '5');

    return 0;
}
